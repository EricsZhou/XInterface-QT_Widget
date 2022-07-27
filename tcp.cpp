#include "tcp.h"
#include "ui_Tcp.h"
#include "configdata.h"
#include <iostream>
#include <iostream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QPushButton>
#include <QUrl>
#include <qfiledialog.h>
#include <QProcess>
#include <QTimer>
#include <QFont>
#include <QPalette>
#include <QCoreApplication>
#include <QDebug>
QString leceName;
QString SpoutSendname;
//int SpoutW;
//int SpoutH;
int Spoutflag=0;
Tcp::Tcp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tcp)
{
    ui->setupUi(this);
    server = nullptr;
    serverThread = nullptr;
    msgDisplayTimer= new QTimer(this);
    test1Timer = new QTimer(this);
    test2Timer = new QTimer(this);

    glspoutwidget = new GLSpoutImageWidget(ui->JWwidget);
    glspoutwidget->setGeometry(QRect(0, 50, 320, 200));
    this->setWindowTitle(QString("MRStage-QT"));

    QFont ft;
    ft.setPointSize(1);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::white);
    ui->labeltext->setPalette(pa);
////    ui->FlightControlLabel->setStyleSheet("border-image:url(:/Resource/background/button.png)");
//    ui->FlightControlLabel->setPalette(pa);
    ui->Jwlabel->setPalette(pa);
    ui->Fwabel->setPalette(pa);
    ui->HDlabel->setPalette(pa);
    ui->BigVediolabel->setPalette(pa);
    ui->MusicLabel->setPalette(pa);

    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(100);
    ui->horizontalSlider->setSingleStep(1);
    ui->horizontalSlider->setValue(75);
//    ui->horizontalSlider->setStyleSheet("QSlider::groove:horizontal{background:rgb(255,255,0);height:10px;}\
//                                        QSlider::handle:vertical{height: 10px;width: 10px;border-color: rgb(100,100,100);margin: -2 -6px;}\
//                                            QSlider::add-page:horizontal{background-color: rgb(255,0,255);}\
//                                            QSlider::sub-page:horizontal{background-color: rgb(255,255,0);}");
    ui->horizontalSlider->setStyleSheet("QSlider::groove:horizontal{height: 5px;left: 0px; right: 0px; border:0px;border-radius:6px;background:rgba(0,0,0,50);}\
                                        QSlider::handle:horizontal{image:url(:/Resource/sliderHander.png);width:  10px;height: 10px;margin-top: -20px;margin-left: 0px;margin-bottom: -20px;margin-right: 0px;border-color:rgb(255,0,250);}\
                                        QSlider::sub-page:horizontal{background:rgba(80,166,234,1);}");

    ui->pushButton->setStyleSheet("QPushButton{background-color:rgb(80,80,81);color:rgb(255, 255, 255);}"
                                    "QPushButton:hover{background-color:rgb(90, 90, 91)}"
                                    "QPushButton:pressed{background-color:rgb(23, 172, 255)}");
    ui->pushButton->setStyleSheet("color:white");
    ui->label->setStyleSheet("border-image:url(:/Resource/Vector.png)");

    ui->label_slider->setText("75");
    ui->label_slider->setPalette(pa);
    QFont font;
    font.setPointSize(0);
    for(auto i=0;i<3;i++)
    {
        JwSpoutButton[i] = new KeyButton(ui->JWwidget);
        JwSpoutButton[i]->setFont(ft);
        JwSpoutButton[i]->setStyleSheet(QString::fromUtf8("background: transparent;"));
        connect(JwSpoutButton[i],SIGNAL(keyPressed(QString)),this,SLOT(SendCameraWidgetMsg(QString)));
    }
    JwSpoutButton[0]->setGeometry(QRect(30, 80, 113, 63));
    JwSpoutButton[1]->setGeometry(QRect(177,80, 113, 63));
    JwSpoutButton[2]->setGeometry(QRect(30, 183, 113, 63));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(Open_SChangWidget()));
    connect(ui->horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT(sendSliderValue(int)));
//    UpdateSpoutWidget();
    CreateServer();
}

Tcp::~Tcp()
{
    QJsonObject jsonObject;
    jsonObject.insert("FuncName","Close");
    QString msg=QString(QJsonDocument(jsonObject).toJson());
    emit serverMsg(msg);

    delete ui;

    if(serverThread)
    {
        serverThread->quit();
        serverThread->wait();
        delete serverThread;
    }
    serverThread = nullptr;

    if(server)
        delete server;
    server = nullptr;
    DjList.clear();
}

void Tcp::CreateServer()
{
    if(!server)
    {
        server = new Server("QTServer",QWebSocketServer::SslMode::NonSecureMode);
        serverThread = new QThread;
        server->moveToThread(serverThread);
        serverThread->start();

        connect(this,&Tcp::serverMsg,server,&Server::send);
        connect(server,SIGNAL(msg(QString)),this,SLOT(HandleMsg(QString)));
        connect(server,SIGNAL(DisplayErrorMsg(QString)),this,SLOT(DisplayErrorMsg(QString)));
    }
}

void Tcp::HandleMsg(const QString &str)
{
    qDebug()<<"receive:"<<str;
    if(str=="heartbeat")
    {
        emit serverMsg("heartbeat");
        return;
    }
    QJsonDocument jsonDocument = QJsonDocument::fromJson(str.toUtf8().data());
    if(!jsonDocument.isNull())
    {
        QJsonObject jsonObject =jsonDocument.object();
        QString funcName=jsonObject.value("FuncName").toString();
        if(funcName=="AllInteractionInfMsg")
            HandleAllInteractionInfMsg(jsonObject);
        else if(funcName=="ErrorMsg")
            HandleErrorMsg(jsonObject);
        else if(funcName=="SwitchCamera")
            HandleSwitchCameraMsg(jsonObject);
        else if(funcName=="SwitchAutoMotion")
            HandleAutoMotionMsg(jsonObject);
        else if(funcName=="CloseQT")
            this->close();
        else if(funcName =="SwitchLevel")
            HandlesenceChange(jsonObject);
    }
    else
    {
        DisplayErrorMsg("信息接收失败");
        return;
    }
}

void Tcp::HandleAllInteractionInfMsg(QJsonObject jsonObject)
{
    QJsonArray data = jsonObject.value("Msg").toArray();
    mapName=jsonObject.value("MapName").toString();
    updadewidget();
    updatelist();
    for (qint32 i=0;i< data.size();i++ ) {
        QString name=data[i].toObject().value("Name").toString();
        QString category=data[i].toObject().value("Category").toString();
        //道具
        if(category=="Item"||category=="Effects")
        {

//            QMetaObject::invokeMethod(item,"_addItemTcp",Q_ARG(QVariant,name),Q_ARG(QVariant,QCoreApplication::applicationDirPath()));
//            itemList.append(name);
            DjList.append(name);
        }//远近恒远
        else if(category=="Camera")
        {
            QJsonObject otherInfo=data[i].toObject().value("OtherInfo").toObject();
            QJsonArray motionArray=otherInfo.value("otherInfo").toArray();
            QStringList motion;
            for(int i=0;i<motionArray.size();i++)
            {
                motion.append(motionArray[i].toString());
            }
            cameraMap.insert(name,motion);
            //在这调用

        }//大屏幕
        else if(category=="Screen"||category=="Poster")
        {
            BScreenList.append(name);
            BScreenList2.append(category);
//            QMetaObject::invokeMethod(item,"_addScreenTcp",Q_ARG(QVariant,name),Q_ARG(QVariant,category));
        }//氛围
        else if(category=="Atmosphere")
        {
            FwList.append(name);
//            QMetaObject::invokeMethod(item,"_addAutoFwbuttonWidget",Q_ARG(QVariant,name));
        }//运镜
        else if(category=="SwitchIten")
        {
            SWList.append(name);
        }//场景切换
        else if(category == "LevelManager")
        {
            QJsonObject otherInfo1=data[i].toObject().value("OtherInfo").toObject();

            QJsonArray motionArray1=otherInfo1.value("otherinfo").toArray();
            for(int i=0;i<motionArray1.size();i++)
            {
                scencForm.append(motionArray1[i].toObject().value("DisplayName").toString());
                scencFormname.append(motionArray1[i].toObject().value("IconName").toString());
            }
        }
    }
    AddAnyWidget();
}

void Tcp::HandleErrorMsg(QJsonObject jsonObject)
{
    QJsonObject msg=jsonObject.value("Msg").toObject();
    QString errorMsg= msg.value("Msg").toString();
    qDebug()<<errorMsg;
//    errormsgBox->warning(NULL, "错误",errorMsg, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    QMessageBox *errormsgBox = new QMessageBox();
    errormsgBox->warning(NULL, "警告",errorMsg,NULL, NULL);
    msgDisplayTimer->stop();
    msgDisplayTimer->start(5000);
}

void Tcp::HandleSwitchCameraMsg(QJsonObject jsonObject)
{
    QJsonObject msg=jsonObject.value("Msg").toObject();
    cameraString= msg.value("CameraName").toString();
    HandleCameraChangeMsg(cameraString);
}
void Tcp::HandlesenceChange(QJsonObject jsonObject)
{
    QJsonObject msg=jsonObject.value("Msg").toObject();
    leceName= msg.value("LevelName").toString();
    updadewidget();
    AddAnyWidget();
    HandleCameraChangeMsg(cameraString);
}
void Tcp::HandleAutoMotionMsg(QJsonObject jsonObject)
{
    QJsonObject msg=jsonObject.value("Msg").toObject();
    bool state= msg.value("State").toBool();
    for(int i= 0;i<3;i++){
        if(switwchidget[i]->label1->text()=="自动运镜"){
            if(state == true)
            {
                switwchidget[i]->label2->setText("开");
                switwchidget[i]->button->setStyleSheet("QPushButton{border-image: url(:/Resource/open.png);}");
                return;
            }
            else{
                switwchidget[i]->label2->setText("关");
                switwchidget[i]->button->setStyleSheet("QPushButton{border-image: url(:/Resource/close.png);}");
                return;
            }
        }
    }
}
void Tcp::DisplayErrorMsg(QString msg)
{
//    item->setProperty("errorMsg","ERROR:"+msg);
    qDebug()<<msg;
    msgDisplayTimer->stop();
//    connect(msgDisplayTimer, &QTimer::timeout,[&](){item->setProperty("errorMsg","");});
    msgDisplayTimer->start(5000);
}

void Tcp::keyPressEvent(QKeyEvent  *event)
{

    if(event->key()==Qt::Key_Q)
    {
        if(!server->IsConnect())
        {
            DisplayErrorMsg("通信未连接");
            return;
        }
        QJsonObject jsonObject;
        jsonObject.insert("FuncName","AllInteractionInfMsg");
        QString msg=QString(QJsonDocument(jsonObject).toJson());
        emit serverMsg(msg);
    }
    else if(event->key()==Qt::Key_F5)
    {
        if(!test1Timer->isActive())
        {
            connect(test1Timer, SIGNAL(timeout()), server, SLOT(test1()));
            test1Timer->start(5*60*60*1000);
        }
        else
        {
            test1Timer->stop();
            test1Timer=nullptr;
        }
    }
}
/////////////////////////////
//机位控制衡中 远近  前后 抖动什么的
void Tcp::SendCameraMsg(QString motion)
{
    if(!server->IsConnect())
    {
        DisplayErrorMsg("通信未连接");
        return;
    }
    QJsonObject jsonObject;
    jsonObject.insert("FuncName","InteractionEvent");
    jsonObject.insert("Name",ui->labeltext->text());
    jsonObject.insert("Motion",motion);
    QString msg=QString(QJsonDocument(jsonObject).toJson());
    emit serverMsg(msg);
}
void Tcp::SendCameraWidgetMsg(QString motion)
{


    if(!server->IsConnect())
    {
        DisplayErrorMsg("通信未连接");
        return;
    }
    QJsonObject jsonObject;
    jsonObject.insert("FuncName","InteractionEvent");
    jsonObject.insert("Name","CameraManager");
    jsonObject.insert("CameraName",motion);
    QString msg=QString(QJsonDocument(jsonObject).toJson());
    emit serverMsg(msg);
}
//打开文件加
void Tcp::OpenScreenFile()
{
//    if(!server->IsConnect())
//    {
//        DisplayErrorMsg("通信未连接");
//        return;
//    }
    QString Url="";
    if(BScreenList2[0]=="Screen")
        Url = QFileDialog::getOpenFileName(this,tr(""),"~/",tr("MP4 Files(*.mp4 *.jpg *.png)"));
    else if(BScreenList2[0] =="Poster")
        Url = QFileDialog::getOpenFileName(this,tr(""),"~/",tr("PNG/JPG Files(*.png *.jpg)"));
    qDebug()<<Url;
    if(Url.length()>0)
    {
        QJsonObject jsonObject;
        jsonObject.insert("FuncName","InteractionEvent");
        jsonObject.insert("Name",BScreenList[0]);
        jsonObject.insert("Url",Url);
        QString msg=QString(QJsonDocument(jsonObject).toJson());
        emit serverMsg(msg);
    }
}
//道具互动 使用按钮发送
void Tcp::SendItemMsg(QString item)
{
    if(!server->IsConnect())
    {
        DisplayErrorMsg("通信未连接");
        return;
    }
    QJsonObject jsonObject;
    jsonObject.insert("FuncName","InteractionEvent");
    jsonObject.insert("Name",item);
    QString msg=QString(QJsonDocument(jsonObject).toJson());
    emit serverMsg(msg);
}

void Tcp::SendAutoMotionMsg(QString name,bool state)
{
    if(!server->IsConnect())
    {
        DisplayErrorMsg("通信未连接");
        return;
    }
    QJsonObject jsonObject;
    jsonObject.insert("FuncName","InteractionEvent");
    jsonObject.insert("Name",name);
    jsonObject.insert("SwitchState",state);
    QString msg=QString(QJsonDocument(jsonObject).toJson());
    emit serverMsg(msg);
}
//氛围切换 按钮发送数据
void Tcp::SendAutoFwBtnMsg(QString name)
{
    if(!server->IsConnect())
    {
        DisplayErrorMsg("通信未连接");
        return;
    }
    QJsonObject jsonObject;
    jsonObject.insert("FuncName","InteractionEvent");
    jsonObject.insert("Name",name);
    QString msg=QString(QJsonDocument(jsonObject).toJson());
    emit serverMsg(msg);
}
//场景切换
void Tcp::sendScenceMsg(QString name)
{

    std::cout <<" name "<<std::endl;
    if(!server->IsConnect())
    {
        DisplayErrorMsg("通信未连接");
        return;
    }
    QJsonObject jsonObject;
    jsonObject.insert("FuncName","InteractionEvent");
    jsonObject.insert("Name","LevelManager");
    jsonObject.insert("LevelName",name);
    QString msg=QString(QJsonDocument(jsonObject).toJson());
    emit serverMsg(msg);
}
//音乐可视化强度
void Tcp::sendSliderValue(int value)
{
    std::cout <<value<<std::endl;
    ui->label_slider->setText(QString("%1").arg(value));
    if(!server->IsConnect())
    {
        DisplayErrorMsg("通信未连接");
        return;
    }
    QJsonObject jsonObject;

    jsonObject.insert("FuncName","InteractionEvent");
    jsonObject.insert("Name","WindowsAudioValueManager");
    jsonObject.insert("AudioValue",value);
    QString msg=QString(QJsonDocument(jsonObject).toJson());
    emit serverMsg(msg);
}
void Tcp::updadewidget()
{
    QLayoutItem *child;
    while ((child = ui->verticalLayout->itemAt(0)) != nullptr) {
        ui->verticalLayout->removeItem(child);
        delete child->widget();
        delete child;
        child = nullptr;
    }
    while ((child = ui->formLayout->itemAt(0)) != nullptr) {
        ui->formLayout->removeItem(child);
        delete child->widget();
        delete child;
        child = nullptr;
    }
    while ((child = ui->formLayout_2->itemAt(0)) != nullptr) {
        ui->formLayout_2->removeItem(child);
        delete child->widget();
        delete child;
        child = nullptr;
    }
    while ((child = ui->formLayout_3->itemAt(0)) != nullptr) {
        ui->formLayout_3->removeItem(child);
        delete child->widget();
        delete child;
        child = nullptr;
    }
    while ((child = ui->verticalLayout_2->itemAt(0)) != nullptr) {
        ui->verticalLayout_2->removeItem(child);
        delete child->widget();
        delete child;
        child = nullptr;
    }
    while ((child = ui->verticalLayout_3->itemAt(0)) != nullptr) {
        ui->verticalLayout_3->removeItem(child);
        delete child->widget();
        delete child;
        child = nullptr;
    }


}
void Tcp::updatelist()
{

    cameraMap.clear();
    DjList.clear();
    FwList.clear();
    SWList.clear();
    BScreenList.clear();
    BScreenList2.clear();
    scencForm.clear();
    scencFormname.clear();
}
void Tcp::AddAnyWidget()
{
//    UpdateSpoutWidget();
    //道具list
    QString flieName = QCoreApplication::applicationDirPath();
    qDebug()<<"111"+flieName;
    if(DjList.size()>0)
    {
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
        for(int i=0;i<DjList.size();i++){
            djwidget[i] = new DjWidget(ui->HDscrollAreaWidget);
            djwidget[i]->Djlabel->setText(DjList.at(i));
            djwidget[i]->move = new QMovie(QString(flieName+"/Resource/"+djwidget[i]->Djlabel->text()+".gif"));
            djwidget[i]->move->setScaledSize(djwidget[i]->DjImagelabel->size());
            djwidget[i]->DjImagelabel->setMovie(djwidget[i]->move);
            djwidget[i]->move->start();
            djwidget[i]->move->stop();

            djwidget[i]->DjImagelabel->show();
            ui->verticalLayout->addWidget(djwidget[i]);
            connect(djwidget[i],SIGNAL(Djname(QString)),this,SLOT(SendItemMsg(QString)));
        }
        ui->verticalLayout->addItem(verticalSpacer);
    //氛围按钮生成
    }
    if(FwList.size()>0)
    {
        for(int i =0 ;i<FwList.size();i++)
        {
            fwbutton[i]=new KeyButton();
            fwbutton[i]->setText(FwList.at(i));
            fwbutton[i]->setMinimumSize(QSize(90, 32));
            fwbutton[i]->setMaximumSize(QSize(90, 32));
            fwbutton[i]->setStyleSheet("QPushButton{background-color:rgb(80,80,81);color:rgb(255, 255, 255);}"
                                       "QPushButton:hover{background-color:rgb(90, 90, 91)}"
                                       "QPushButton:pressed{background-color:rgb(23, 172, 255)}");

            if(i%2)
                ui->formLayout->setWidget(i/2, QFormLayout::FieldRole, fwbutton[i]);
            else
                ui->formLayout->setWidget(i/2, QFormLayout::LabelRole, fwbutton[i]);
            connect(fwbutton[i],SIGNAL(keyClicked(QString)),this,SLOT(SendAutoFwBtnMsg(QString)));
        }
    }
    //运镜与特效生成
    if(SWList.size()>0)
    {
        for(int i=0;i<SWList.size();i++)
        {
            switwchidget[i] = new SwitchWidget(ui->scrollAreaWidgetContents_3);
            switwchidget[i]->label1->setText(SWList.at(i));
            ui->verticalLayout_2->addWidget(switwchidget[i]);
            connect(switwchidget[i],SIGNAL(myclicked(QString,bool)),this,SLOT(SendAutoMotionMsg(QString,bool)));
        }
    }
    //机位控制视频生成
    if(cameraMap.size()>0){
        QMap<QString,QList<QString>>::iterator  it = cameraMap.begin();
        int i=0;

        while (it!=cameraMap.end()) {
            glspoutwidget->label[i]->setText(it.key());
            JwSpoutButton[i]->setText(it.key());
//            if(it.key() == "横_中"){
//                SpoutW = 1920;
//                SpoutH = 1080;
//            }
//            else if(it.key() == "竖_中"){
//                SpoutW = 1080;
//                SpoutH = 1920;
//            }

            ++i;
            ++it;
        }
    }
    //大屏幕
    if(BScreenList.size()>0)
    {
        for(int i=0;i<BScreenList.size();i++)
        {
            bigSreenWidget[i] = new BigSreenForm(ui->CenterVediowidget);
            bigSreenWidget[i]->resize(320, 147);
            bigSreenWidget[i]->setMinimumSize(QSize(320, 147));
            bigSreenWidget[i]->setMaximumSize(QSize(320, 147));
            bigSreenWidget[i]->label->setText(BScreenList.at(i));
            bigSreenWidget[i]->button->setText("切换图片/视频");
            bigSreenWidget[i]->label_2->setPixmap(QPixmap::fromImage(QImage(flieName+"/Resource/"+bigSreenWidget[i]->label->text()+".png").scaled(bigSreenWidget[i]->label_2->width(),bigSreenWidget[i]->label_2->height(),Qt::KeepAspectRatio)));
            ui->verticalLayout_3->addWidget(bigSreenWidget[i]);
            connect(bigSreenWidget[i]->button,SIGNAL(clicked()),this,SLOT(OpenScreenFile()));
        }
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
        ui->verticalLayout_3->addItem(verticalSpacer_2);
    }

}

void Tcp::HandleCameraChangeMsg(QString Jwtext)
{
    //每一次信号清空 重新生成
    QLayoutItem *child;
    while ((child = ui->formLayout_3->itemAt(0)) != nullptr) {
        ui->formLayout_3->removeItem(child);
        delete child->widget();
        delete child;
        child = nullptr;
    }
    ui->labeltext->setText(Jwtext);
    //视频按钮生成
    if(cameraMap.find(Jwtext).value().size()>0)
    {

        for(int i =0 ;i<cameraMap.find(Jwtext).value().size();i++)
        {
            Jwbutton[i]=new KeyButton();
            Jwbutton[i]->setText(cameraMap.find(Jwtext).value().at(i));
            Jwbutton[i]->setMinimumSize(QSize(120, 32));
            Jwbutton[i]->setMaximumSize(QSize(120, 32));
            Jwbutton[i]->setStyleSheet("QPushButton{background-color:rgb(80,80,81);color:rgb(255, 255, 255);}"
                                       "QPushButton:hover{background-color:rgb(90, 90, 91)}"
                                       "QPushButton:pressed{background-color:rgb(23, 172, 255)}");

            if(i%2)
                ui->formLayout_3->setWidget(i/2, QFormLayout::FieldRole, Jwbutton[i]);
            else
                ui->formLayout_3->setWidget(i/2, QFormLayout::LabelRole, Jwbutton[i]);
            connect(Jwbutton[i],SIGNAL(keyClicked(QString)),this,SLOT(SendCameraMsg(QString)));
        }
    }
}

void Tcp::Open_SChangWidget()
{
    SCForm = new ScenChangWidget();
    SCForm->setAttribute(Qt::WA_ShowModal);                 //设置模态
    SCForm->resize(950,575);
    SCForm->addscenceFrom(scencForm,scencFormname);
    connect(SCForm,SIGNAL(SendScenceFrom(QString)),this,SLOT(sendScenceMsg(QString)));
    SCForm->show();
}
