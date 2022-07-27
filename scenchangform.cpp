#include "scenchangform.h"
#include <QPalette>
#include <QString>
ScenchangForm::ScenchangForm(QWidget *parent) : QWidget(parent)
{
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::white);
    this->resize(200,162);
    this->setMinimumSize(QSize(200,162));
    this->setMaximumSize(QSize(200,162));
    labelborde = new QLabel(this);
    labelborde->setGeometry(QRect(18, 18, 164, 94));
    labelborde->setMinimumSize(QSize(164,94));
    labelborde->setMaximumSize(QSize(164,94));

    label = new QLabel(this);
    label->setGeometry(QRect(20, 20, 160, 90));
    label->setMinimumSize(QSize(160, 90));
    label->setMaximumSize(QSize(160, 90));

    label2 = new QLabel(this);
    label2->setGeometry(QRect(20, 120, 120, 22));
    label2->setMinimumSize(QSize(120, 22));
    label2->setMaximumSize(QSize(120, 22));
    label2->setPalette(pa);
    button = new KeyButton(this) ;
    button->setGeometry(QRect(20, 20, 160, 90));
    button->setMinimumSize(QSize(160, 90));
    button->setMaximumSize(QSize(160, 90));
    button->setStyleSheet("background:transparent");
    button->installEventFilter(this);
    connect(button,SIGNAL(clicked()),this,SLOT(SendScenButton()));

}
void ScenchangForm::SendScenButton()
{
    emit sendScenceFrom(label2->text());
}
bool ScenchangForm::eventFilter(QObject *watched, QEvent *event)
{
    if(button == watched)
    {
        if(QEvent::Enter==event->type()){
            button->setStyleSheet("QPushButton{border-image: url(:/Resource/Group.png);}");
        }else if(QEvent::Leave==event->type()){
            button->setStyleSheet("background:transparent");
        }
    }
    return QObject::eventFilter(watched,event);
}
