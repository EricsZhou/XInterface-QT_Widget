#ifndef BIGSREENFORM_H
#define BIGSREENFORM_H

#include <QWidget>
#include <QLabel>
#include "MyButton.h"
#include <QPushButton>


class BigSreenForm : public QWidget
{
    Q_OBJECT

public:
    explicit BigSreenForm(QWidget *parent = nullptr);
    ~BigSreenForm();
    QLabel *label;
    QLabel *label_2;
//    KeyButton *button;
    QPushButton *button;
public slots:


};

#endif // BIGSREENFORM_H
