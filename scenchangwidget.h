#ifndef SCENCHANGWIDGET_H
#define SCENCHANGWIDGET_H

#include <QWidget>
#include "scenchangform.h"
#include <QList>
class ScenChangWidget : public QWidget
{
    Q_OBJECT

public:
    /*explicit */ScenChangWidget(QWidget *parent = nullptr);
    ~ScenChangWidget();
    ScenchangForm *scenFrom[100];
    int initX,initY;
    int rowNum,colNum;
    int j;
    int k;
    void addscenceFrom(QList<QString>,QList<QString> );
private:
public slots:
    void scenFromButton(QString str);
signals:
    void SendScenceFrom(QString);

};

#endif // SCENCHANGWIDGET_H
