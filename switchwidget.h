#ifndef SWITCHWIDGET_H
#define SWITCHWIDGET_H

#include <QWidget>
//#include "MyButton.h"
#include <QPushButton>
#include <QLabel>

class SwitchWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SwitchWidget(QWidget *parent = nullptr);
    QLabel *label1;
    QLabel *label2;
    QPushButton *button;
signals:
    void myclicked(QString msg,bool msg2);
public slots:
    void on_clicked();


};

#endif // SWITCHWIDGET_H
