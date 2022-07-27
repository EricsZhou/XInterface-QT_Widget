#ifndef MYBUTTON_H
#define MYBUTTON_H
#include <QWidget>
#include <QPushButton>
class KeyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit KeyButton(QWidget *parent = 0) : QPushButton(parent),
        pauseMsecs(400), intervalMsecs(30)
    {
//        tm = new QTimer(this);
//        connect(tm, SIGNAL(timeout()), this, SLOT(on_pressed_last()));
        connect(this, SIGNAL(pressed()), this, SLOT(on_pressed()));
        connect(this, SIGNAL(released()), this, SLOT(on_released()));
        connect(this, SIGNAL(clicked()), this, SLOT(on_clicked()));
    }

private:
//    QTimer *tm;
    long pauseMsecs;
    long intervalMsecs;

signals:
    void keyPressed(QString msg);
    void keyReleased(QString msg);
    void keyClicked(QString msg);

public slots:
    void on_pressed() { emit this->keyPressed(this->text());}
//                        tm->start(pauseMsecs); }
    void on_pressed_last() { emit this->keyPressed(this->text());}
//                             tm->setInterval(intervalMsecs); }
    void on_released() { /*tm->stop();*/ emit this->keyReleased(this->text()); }
    void on_clicked() { emit this->keyClicked(this->text()); }
};
#endif // MYBUTTON_H
