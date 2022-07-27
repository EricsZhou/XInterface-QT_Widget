/********************************************************************************
** Form generated from reading UI file 'tcp.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCP_H
#define UI_TCP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tcp
{
public:
    QLabel *Jwlabel;
    QWidget *JWwidget;
    QLabel *label;
    QLabel *labeltext;
    QPushButton *pushButton;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_4;
    QFormLayout *formLayout_2;
    QWidget *widget_2;
    QGridLayout *gridLayout_5;
    QScrollArea *scrollArea_5;
    QWidget *scrollAreaWidgetContents_5;
    QFormLayout *formLayout_3;
    QWidget *SWitchwidget;
    QGridLayout *gridLayout_4;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *BigVediolabel;
    QWidget *CenterVediowidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *Fwabel;
    QWidget *SWitchwidget_2;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QFormLayout *formLayout;
    QLabel *HDlabel;
    QWidget *HDwidget;
    QScrollArea *HDscrollArea;
    QWidget *HDscrollAreaWidget;
    QVBoxLayout *verticalLayout;
    QLabel *MusicLabel;
    QSlider *horizontalSlider;
    QLabel *label_slider;

    void setupUi(QWidget *Tcp)
    {
        if (Tcp->objectName().isEmpty())
            Tcp->setObjectName(QString::fromUtf8("Tcp"));
        Tcp->resize(1040, 680);
        Tcp->setMinimumSize(QSize(1040, 680));
        Tcp->setMaximumSize(QSize(1040, 680));
        Tcp->setStyleSheet(QString::fromUtf8("background-color:rgb(16,16,16)"));
        Jwlabel = new QLabel(Tcp);
        Jwlabel->setObjectName(QString::fromUtf8("Jwlabel"));
        Jwlabel->setGeometry(QRect(20, 20, 320, 90));
        Jwlabel->setMinimumSize(QSize(320, 90));
        Jwlabel->setMaximumSize(QSize(320, 90));
        QFont font;
        font.setPointSize(17);
        font.setBold(false);
        Jwlabel->setFont(font);
        Jwlabel->setStyleSheet(QString::fromUtf8("background-color:rgb(48,49,51)"));
        Jwlabel->setAlignment(Qt::AlignCenter);
        JWwidget = new QWidget(Tcp);
        JWwidget->setObjectName(QString::fromUtf8("JWwidget"));
        JWwidget->setGeometry(QRect(20, 112, 320, 368));
        JWwidget->setMinimumSize(QSize(320, 368));
        JWwidget->setMaximumSize(QSize(320, 368));
        JWwidget->setStyleSheet(QString::fromUtf8("background-color:rgb(48,49,51)"));
        label = new QLabel(JWwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(132, 21, 14, 10));
        label->setMinimumSize(QSize(14, 10));
        label->setMaximumSize(QSize(14, 10));
        label->setBaseSize(QSize(2, 0));
        labeltext = new QLabel(JWwidget);
        labeltext->setObjectName(QString::fromUtf8("labeltext"));
        labeltext->setGeometry(QRect(152, 20, 37, 13));
        labeltext->setMinimumSize(QSize(37, 13));
        labeltext->setMaximumSize(QSize(37, 13));
        pushButton = new QPushButton(JWwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(248, 16, 52, 20));
        pushButton->setMinimumSize(QSize(52, 20));
        pushButton->setMaximumSize(QSize(52, 20));
        widget = new QWidget(JWwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 50, 320, 200));
        widget->setMinimumSize(QSize(320, 200));
        widget->setMaximumSize(QSize(320, 200));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea_4 = new QScrollArea(widget);
        scrollArea_4->setObjectName(QString::fromUtf8("scrollArea_4"));
        scrollArea_4->setFrameShape(QFrame::NoFrame);
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 320, 200));
        formLayout_2 = new QFormLayout(scrollAreaWidgetContents_4);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setHorizontalSpacing(30);
        formLayout_2->setContentsMargins(20, 0, -1, -1);
        scrollArea_4->setWidget(scrollAreaWidgetContents_4);

        gridLayout_2->addWidget(scrollArea_4, 0, 0, 1, 1);

        widget_2 = new QWidget(JWwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 250, 320, 118));
        widget_2->setMinimumSize(QSize(320, 118));
        widget_2->setMaximumSize(QSize(320, 118));
        gridLayout_5 = new QGridLayout(widget_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        scrollArea_5 = new QScrollArea(widget_2);
        scrollArea_5->setObjectName(QString::fromUtf8("scrollArea_5"));
        scrollArea_5->setFrameShape(QFrame::NoFrame);
        scrollArea_5->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 320, 118));
        formLayout_3 = new QFormLayout(scrollAreaWidgetContents_5);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setHorizontalSpacing(10);
        formLayout_3->setVerticalSpacing(10);
        formLayout_3->setContentsMargins(20, 10, -1, -1);
        scrollArea_5->setWidget(scrollAreaWidgetContents_5);

        gridLayout_5->addWidget(scrollArea_5, 0, 0, 1, 1);

        SWitchwidget = new QWidget(Tcp);
        SWitchwidget->setObjectName(QString::fromUtf8("SWitchwidget"));
        SWitchwidget->setGeometry(QRect(20, 499, 320, 160));
        SWitchwidget->setMinimumSize(QSize(320, 160));
        SWitchwidget->setMaximumSize(QSize(320, 160));
        SWitchwidget->setStyleSheet(QString::fromUtf8("background-color:rgb(48,49,51)"));
        gridLayout_4 = new QGridLayout(SWitchwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        scrollArea_3 = new QScrollArea(SWitchwidget);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setFrameShape(QFrame::NoFrame);
        scrollArea_3->setWidgetResizable(true);
        scrollArea_3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 320, 160));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        gridLayout_4->addWidget(scrollArea_3, 0, 0, 1, 1);

        BigVediolabel = new QLabel(Tcp);
        BigVediolabel->setObjectName(QString::fromUtf8("BigVediolabel"));
        BigVediolabel->setGeometry(QRect(360, 20, 320, 90));
        BigVediolabel->setMinimumSize(QSize(320, 90));
        BigVediolabel->setMaximumSize(QSize(16777215, 90));
        BigVediolabel->setFont(font);
        BigVediolabel->setStyleSheet(QString::fromUtf8("background-color:rgb(48,49,51)"));
        BigVediolabel->setAlignment(Qt::AlignCenter);
        CenterVediowidget = new QWidget(Tcp);
        CenterVediowidget->setObjectName(QString::fromUtf8("CenterVediowidget"));
        CenterVediowidget->setGeometry(QRect(360, 112, 320, 296));
        CenterVediowidget->setMinimumSize(QSize(320, 296));
        CenterVediowidget->setMaximumSize(QSize(320, 296));
        CenterVediowidget->setStyleSheet(QString::fromUtf8("background-color:rgb(48,49,51)"));
        verticalLayout_3 = new QVBoxLayout(CenterVediowidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        Fwabel = new QLabel(Tcp);
        Fwabel->setObjectName(QString::fromUtf8("Fwabel"));
        Fwabel->setGeometry(QRect(360, 428, 320, 90));
        Fwabel->setMinimumSize(QSize(320, 90));
        Fwabel->setMaximumSize(QSize(320, 90));
        Fwabel->setFont(font);
        Fwabel->setStyleSheet(QString::fromUtf8("background-color:rgb(48,49,51)"));
        Fwabel->setLineWidth(0);
        Fwabel->setAlignment(Qt::AlignCenter);
        Fwabel->setMargin(0);
        SWitchwidget_2 = new QWidget(Tcp);
        SWitchwidget_2->setObjectName(QString::fromUtf8("SWitchwidget_2"));
        SWitchwidget_2->setGeometry(QRect(360, 520, 320, 140));
        SWitchwidget_2->setMinimumSize(QSize(320, 140));
        SWitchwidget_2->setMaximumSize(QSize(320, 140));
        SWitchwidget_2->setAutoFillBackground(false);
        SWitchwidget_2->setStyleSheet(QString::fromUtf8("background-color:rgb(48,49,51)"));
        gridLayout_3 = new QGridLayout(SWitchwidget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QScrollArea(SWitchwidget_2);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setEnabled(true);
        scrollArea_2->setFrameShape(QFrame::NoFrame);
        scrollArea_2->setLineWidth(0);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 320, 140));
        formLayout = new QFormLayout(scrollAreaWidgetContents_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(80);
        formLayout->setVerticalSpacing(5);
        formLayout->setContentsMargins(20, 10, 0, 0);
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_3->addWidget(scrollArea_2, 0, 1, 1, 1);

        HDlabel = new QLabel(Tcp);
        HDlabel->setObjectName(QString::fromUtf8("HDlabel"));
        HDlabel->setGeometry(QRect(700, 20, 320, 90));
        HDlabel->setMinimumSize(QSize(320, 90));
        HDlabel->setMaximumSize(QSize(320, 90));
        HDlabel->setFont(font);
        HDlabel->setStyleSheet(QString::fromUtf8("background-color:rgb(48,49,51)"));
        HDlabel->setAlignment(Qt::AlignCenter);
        HDwidget = new QWidget(Tcp);
        HDwidget->setObjectName(QString::fromUtf8("HDwidget"));
        HDwidget->setGeometry(QRect(700, 112, 320, 548));
        HDwidget->setMinimumSize(QSize(320, 548));
        HDwidget->setMaximumSize(QSize(320, 548));
        HDwidget->setStyleSheet(QString::fromUtf8("background-color:rgb(48,49,51)"));
        HDscrollArea = new QScrollArea(HDwidget);
        HDscrollArea->setObjectName(QString::fromUtf8("HDscrollArea"));
        HDscrollArea->setGeometry(QRect(0, 50, 320, 490));
        HDscrollArea->setMinimumSize(QSize(320, 490));
        HDscrollArea->setMaximumSize(QSize(320, 490));
        HDscrollArea->setFrameShape(QFrame::NoFrame);
        HDscrollArea->setWidgetResizable(true);
        HDscrollAreaWidget = new QWidget();
        HDscrollAreaWidget->setObjectName(QString::fromUtf8("HDscrollAreaWidget"));
        HDscrollAreaWidget->setGeometry(QRect(0, 0, 320, 490));
        verticalLayout = new QVBoxLayout(HDscrollAreaWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        HDscrollArea->setWidget(HDscrollAreaWidget);
        MusicLabel = new QLabel(HDwidget);
        MusicLabel->setObjectName(QString::fromUtf8("MusicLabel"));
        MusicLabel->setGeometry(QRect(20, 10, 98, 12));
        MusicLabel->setMinimumSize(QSize(98, 12));
        MusicLabel->setMaximumSize(QSize(98, 12));
        horizontalSlider = new QSlider(HDwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 30, 250, 15));
        horizontalSlider->setMinimumSize(QSize(250, 0));
        horizontalSlider->setMaximumSize(QSize(250, 16777215));
        horizontalSlider->setMaximum(31);
        horizontalSlider->setSingleStep(0);
        horizontalSlider->setValue(0);
        horizontalSlider->setSliderPosition(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_slider = new QLabel(HDwidget);
        label_slider->setObjectName(QString::fromUtf8("label_slider"));
        label_slider->setGeometry(QRect(275, 27, 30, 20));
        label_slider->setMinimumSize(QSize(30, 20));
        label_slider->setMaximumSize(QSize(30, 20));
        QFont font1;
        font1.setPointSize(12);
        label_slider->setFont(font1);
        label_slider->setLayoutDirection(Qt::LeftToRight);

        retranslateUi(Tcp);

        QMetaObject::connectSlotsByName(Tcp);
    } // setupUi

    void retranslateUi(QWidget *Tcp)
    {
        Tcp->setWindowTitle(QCoreApplication::translate("Tcp", "Tcp", nullptr));
        Jwlabel->setText(QCoreApplication::translate("Tcp", "\346\234\272\344\275\215\346\216\247\345\210\266", nullptr));
        label->setText(QString());
        labeltext->setText(QString());
        pushButton->setText(QCoreApplication::translate("Tcp", "\345\210\207\346\215\242\345\234\272\346\231\257", nullptr));
        BigVediolabel->setText(QCoreApplication::translate("Tcp", "\345\244\247\350\215\247\345\271\225", nullptr));
        Fwabel->setText(QCoreApplication::translate("Tcp", "\346\260\233\345\233\264\345\210\207\346\215\242", nullptr));
        HDlabel->setText(QCoreApplication::translate("Tcp", "\344\272\222\345\212\250\351\201\223\345\205\267", nullptr));
        MusicLabel->setText(QCoreApplication::translate("Tcp", "\351\237\263\344\271\220\345\217\257\350\247\206\345\214\226\345\274\272\345\272\246", nullptr));
        label_slider->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Tcp: public Ui_Tcp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCP_H
