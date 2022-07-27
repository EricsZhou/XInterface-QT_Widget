#include "mymouseqlabel.h"

MyMouseQlabel::MyMouseQlabel(QWidget *parent) : QLabel(parent)
{
    connect(this, SIGNAL(clicked()), this, SLOT(on_clicked()));
}
void MyMouseQlabel::mouseReleaseEvent(QMouseEvent *ev)
{
    emit clicked(ev);
}

void MyMouseQlabel::mousePressEvent(QMouseEvent *ev)
{
    emit pressed(ev);
}

void MyMouseQlabel::mouseDoubleClickEvent(QMouseEvent *ev)
{
    emit doubled(ev);
}

void MyMouseQlabel::mouseMoveEvent(QMouseEvent *ev)
{
    emit moved(ev);
}
