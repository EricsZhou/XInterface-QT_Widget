#include "switchwidget.h"

SwitchWidget::SwitchWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(300,30);
    this->setMinimumSize(QSize(300,30));
    this->setMaximumSize(QSize(300,30));
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::white);
    label1 = new QLabel(this);

    label2= new QLabel(this);
    button = new QPushButton(this);
    label2->setPalette(pa);
    label1->setPalette(pa);
    label1->setGeometry(QRect(20, 14, 56, 12));
    label1->setMinimumSize(QSize(56, 12));
    label1->setMaximumSize(QSize(56, 12));

    label2->setGeometry(QRect(266, 14, 14,12));
    label2->setMinimumSize(QSize(14,12));
    label2->setMaximumSize(QSize(14,12));
    label2->setText("关");


    button->setGeometry(QRect(186,10,60,20));
    button->setMinimumSize(QSize(60,20));
    button->setMaximumSize(QSize(60,20));
    button->setStyleSheet("QPushButton{border-image: url(:/Resource/close.png);}");
    connect(button,SIGNAL(clicked()),this,SLOT(on_clicked()));
}
void SwitchWidget::on_clicked()
{
    bool state;
    if(label2->text() == "关")
    {
        label2->setText("开");
        state = true;
        button->setStyleSheet("QPushButton{border-image: url(:/Resource/open.png);}");
    }
    else{
        label2->setText("关");
        state = false;
        button->setStyleSheet("QPushButton{border-image: url(:/Resource/close.png);}");
    }
    emit this->myclicked(label1->text(),state);
}
