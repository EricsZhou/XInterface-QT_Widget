#include "djwidget.h"
#include <QDebug>

DjWidget::DjWidget(QWidget *parent) :
    QWidget(parent)
{
    QFont ft;
    ft.setPointSize(11);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::white);
//    ui->label->setStyleSheet("border-image:url(:/Resource/background/button.png)");
    QString flieName = QCoreApplication::applicationDirPath();
    this->resize(290, 102);
    this->setMinimumSize(QSize(290, 102));
    this->setMaximumSize(QSize(290, 102));
    LineLabel = new QLabel(this);
    LineLabel->setGeometry(QRect(20, 101, 290, 1));
    LineLabel->setMinimumSize(QSize(290, 1));
    LineLabel->setMaximumSize(QSize(290, 1));
    LineLabel->setStyleSheet(QString::fromUtf8("background-color:rgb(230,230,230)"));
    Djlabel = new QLabel(this);
    Djlabel->setObjectName(QString::fromUtf8("Djlabel"));
    Djlabel->setGeometry(QRect(180, 20, 42, 20));
    Djlabel->setMinimumSize(QSize(100, 20));
    Djlabel->setMaximumSize(QSize(100, 20));
    QFont font;
    font.setPointSize(14);
    Djlabel->setFont(font);
    DjButton = new QPushButton(this);
    DjButton->setObjectName(QString::fromUtf8("DjButton"));
    DjButton->setGeometry(QRect(180, 50, 90, 32));
    DjButton->setMinimumSize(QSize(90, 32));
    DjButton->setMaximumSize(QSize(90, 32));

    DjButton->setStyleSheet("QPushButton{background-color:rgb(80,80,81);color:rgb(255, 255, 255);}"
                            "QPushButton:hover{background-color:rgb(90, 90, 91)}"
                            "QPushButton:pressed{background-color:rgb(23, 172, 255)}");
    DjImagelabel = new QLabel(this);
    DjImagelabel->setObjectName(QString::fromUtf8("DjImagelabel"));
    DjImagelabel->setGeometry(QRect(20, 20, 112, 63));
    DjImagelabel->setMinimumSize(QSize(112, 63));
    DjImagelabel->setMaximumSize(QSize(112, 63));
    DjImagelabel->installEventFilter(this);
    this->setWindowTitle(QCoreApplication::translate("DjWidget", "Form", nullptr));
    DjButton->setText(QString("使用"));

    Djlabel->setFont(ft);
    Djlabel->setPalette(pa);
    connect(DjButton,SIGNAL(clicked()),this,SLOT(buttonslot()));
}

DjWidget::~DjWidget()
{

}
void DjWidget::buttonslot()
{
    qDebug()<<"buttonslot()buttonslot()buttonslot()buttonslot()"<<Djlabel->text();
    emit Djname(Djlabel->text());
}
bool DjWidget::eventFilter(QObject *watched, QEvent *event)
{
    if(DjImagelabel == watched)
    {
        if(QEvent::Enter==event->type()){
            move->start();
        }else if(QEvent::Leave==event->type()){
            move->stop();
        }
    }
    return QObject::eventFilter(watched,event);
}

