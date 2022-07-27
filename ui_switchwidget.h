/********************************************************************************
** Form generated from reading UI file 'switchwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWITCHWIDGET_H
#define UI_SWITCHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SwitchWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *SwitchWidget)
    {
        if (SwitchWidget->objectName().isEmpty())
            SwitchWidget->setObjectName(QString::fromUtf8("SwitchWidget"));
        SwitchWidget->resize(300, 50);
        SwitchWidget->setMinimumSize(QSize(300, 50));
        SwitchWidget->setMaximumSize(QSize(300, 50));
        horizontalLayout = new QHBoxLayout(SwitchWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, -1, 20, -1);
        label = new QLabel(SwitchWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(101, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(SwitchWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(SwitchWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);


        retranslateUi(SwitchWidget);

        QMetaObject::connectSlotsByName(SwitchWidget);
    } // setupUi

    void retranslateUi(QWidget *SwitchWidget)
    {
        SwitchWidget->setWindowTitle(QCoreApplication::translate("SwitchWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("SwitchWidget", "111", nullptr));
        label_2->setText(QCoreApplication::translate("SwitchWidget", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("SwitchWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SwitchWidget: public Ui_SwitchWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWITCHWIDGET_H
