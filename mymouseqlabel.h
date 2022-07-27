#ifndef MYMOUSEQLABEL_H
#define MYMOUSEQLABEL_H
#include <QMouseEvent>
#include <QLabel>
#include <QWidget>
class MyMouseQlabel : public QLabel
{Q_OBJECT
public:
    explicit MyMouseQlabel(QWidget *parent = nullptr);

protected:
    void mouseReleaseEvent(QMouseEvent *ev);  //抬起
    void mousePressEvent(QMouseEvent *ev);    //按下
    void mouseDoubleClickEvent(QMouseEvent *ev);  //双击
    void mouseMoveEvent(QMouseEvent *ev);     //拖动

signals:
    void clicked(QMouseEvent *ev);  //抬起
    void pressed(QMouseEvent *ev);  //按下
    void doubled(QMouseEvent *ev);  //双击
    void moved(QMouseEvent *ev);    //拖动
public slots:
};

#endif // MYMOUSEQLABEL_H
