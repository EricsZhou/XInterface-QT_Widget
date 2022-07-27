#include "scenchangwidget.h"
#include <QDebug>
#include <QCoreApplication>
extern QString leceName;
ScenChangWidget::ScenChangWidget(QWidget *parent) :
    QWidget(parent)

{
    this->resize(950, 575);
    this->setWindowTitle(QString("场景切换"));
//    this->setMinimumSize(QSize(950, 575));
//    this->setMaximumSize(QSize(950, 575));
    this->setMinimumSize(QSize(950, 575));
    this->setMaximumSize(QSize(950, 575));
    this->setStyleSheet(QString::fromUtf8("background-color:rgb(26, 26, 27)"));
    initX = 20;
    initY = 30;
    rowNum = 20;
    colNum = 30;
}

ScenChangWidget::~ScenChangWidget()
{

}
void ScenChangWidget::addscenceFrom(QList<QString> scen,QList<QString> icname)
{
    QString flieName = QCoreApplication::applicationDirPath();
    if(scen.size()>0)
    {
        for(int i=0;i<scen.size();i++){
            j=i/4;
            k = i%4;
            qDebug()<<"==============================="<<leceName;
            scenFrom[i] = new ScenchangForm(this);
            scenFrom[i]->setGeometry(QRect((initX+k*(scenFrom[i]->width()+rowNum)), (initY+j*(scenFrom[i]->height()+rowNum)),200,162));
            scenFrom[i]->setMinimumSize(QSize(200,162));
            scenFrom[i]->setMaximumSize(QSize(200,162));
            scenFrom[i]->label2->setText(scen.at(i));
            scenFrom[i]->label->setStyleSheet(QString("border-image:url("+flieName+"/Content/Movies/"+icname.at(i)+ ".jpg)"));
            if(leceName == scenFrom[i]->label2->text()){
                scenFrom[i]->labelborde->setStyleSheet("border:2px solid green;");
            }
            else{
                scenFrom[i]->labelborde->setStyleSheet("border:0px solid black;");
            }
            connect(scenFrom[i],SIGNAL(sendScenceFrom(QString)),this,SLOT(scenFromButton(QString)));
        }
    }
}
void ScenChangWidget::scenFromButton(QString str)
{
    this->close();
    emit SendScenceFrom(str);
}
