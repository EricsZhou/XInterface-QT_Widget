#include "bigsreenform.h"
#include <QPalette>
BigSreenForm::BigSreenForm(QWidget *parent) :
    QWidget(parent)
{
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::white);
    this->resize(320, 147);
    this->setMinimumSize(QSize(320, 147));
    this->setMaximumSize(QSize(320, 147));
    label = new QLabel(this);
    label->setGeometry(QRect(20, 20, 65, 20));
    label->setMinimumSize(QSize(65, 20));
    label->setMaximumSize(QSize(65, 20));

    label_2 = new QLabel(this);
    label_2->setGeometry(QRect(20, 46, 144, 81));
    label_2->setMinimumSize(QSize(144, 81));
    label_2->setMaximumSize(QSize(144, 81));
    button = new KeyButton(this);
    button->setGeometry(QRect(210, 95, 90, 32));
    button->setMinimumSize(QSize(90, 32));
    button->setMaximumSize(QSize(90, 32));
    button->setStyleSheet("QPushButton{background-color:rgb(80,80,81);color:rgb(255, 255, 255);}"
                               "QPushButton:hover{background-color:rgb(90, 90, 91)}"
                               "QPushButton:pressed{background-color:rgb(23, 172, 255)}");
    button->setPalette(pa);
    label->setPalette(pa);
}

BigSreenForm::~BigSreenForm()
{

}
