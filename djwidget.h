#ifndef DJWIDGET_H
#define DJWIDGET_H

#include <QWidget>
#include <QString>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QString>
#include <QMouseEvent>
#include <QEvent>
#include <QMovie>
class DjWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DjWidget(QWidget *parent = nullptr);
    ~DjWidget();
    bool eventFilter(QObject *watched, QEvent *event);   //事件过滤
signals:
   void Djname(QString);
public:
    QLabel *Djlabel;
    QPushButton *DjButton;
    QLabel *DjImagelabel;
    QLabel *LineLabel;
    QMovie *move;
public slots:
    void buttonslot();
};

#endif // DJWIDGET_H
