/********************************************************************************
** Form generated from reading UI file 'djwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DJWIDGET_H
#define UI_DJWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DjWidget
{
public:
    QLabel *Djlabel;
    QPushButton *DjButton;
    QLabel *DjImagelabel;

    void setupUi(QWidget *DjWidget)
    {
        if (DjWidget->objectName().isEmpty())
            DjWidget->setObjectName(QString::fromUtf8("DjWidget"));
        DjWidget->resize(300, 102);
        DjWidget->setMinimumSize(QSize(300, 102));
        DjWidget->setMaximumSize(QSize(300, 102));
        Djlabel = new QLabel(DjWidget);
        Djlabel->setObjectName(QString::fromUtf8("Djlabel"));
        Djlabel->setGeometry(QRect(180, 20, 42, 20));
        Djlabel->setMinimumSize(QSize(42, 20));
        Djlabel->setMaximumSize(QSize(42, 20));
        QFont font;
        font.setPointSize(14);
        Djlabel->setFont(font);
        DjButton = new QPushButton(DjWidget);
        DjButton->setObjectName(QString::fromUtf8("DjButton"));
        DjButton->setGeometry(QRect(180, 50, 90, 32));
        DjButton->setMinimumSize(QSize(90, 32));
        DjButton->setMaximumSize(QSize(90, 32));
        DjButton->setStyleSheet(QString::fromUtf8("background-color:rgb(0,0,0)"));
        DjImagelabel = new QLabel(DjWidget);
        DjImagelabel->setObjectName(QString::fromUtf8("DjImagelabel"));
        DjImagelabel->setGeometry(QRect(20, 20, 91, 61));

        retranslateUi(DjWidget);

        QMetaObject::connectSlotsByName(DjWidget);
    } // setupUi

    void retranslateUi(QWidget *DjWidget)
    {
        DjWidget->setWindowTitle(QCoreApplication::translate("DjWidget", "Form", nullptr));
        Djlabel->setText(QCoreApplication::translate("DjWidget", "111111", nullptr));
        DjButton->setText(QString());
        DjImagelabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DjWidget: public Ui_DjWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DJWIDGET_H
