#ifndef SCENCHANGFORM_H
#define SCENCHANGFORM_H

#include <QWidget>
#include <QLabel>
#include "MyButton.h"
#include <QMouseEvent>
#include <QEvent>
#include <QCoreApplication>
class ScenchangForm : public QWidget
{
    Q_OBJECT
public:
    explicit ScenchangForm(QWidget *parent = nullptr);
    QLabel *label;
    QLabel *label2;
    QLabel *labelborde;
    KeyButton *button;

    bool eventFilter(QObject *watched, QEvent *event);
    QString flieName = QCoreApplication::applicationDirPath();
public slots:
    void SendScenButton();
signals:
    void sendScenceFrom(QString);
};

#endif // SCENCHANGFORM_H
