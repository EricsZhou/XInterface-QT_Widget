#ifndef HDFORM_H
#define HDFORM_H

#include <QWidget>

namespace Ui {
class HdForm;
}

class HdForm : public QWidget
{
    Q_OBJECT

public:
    explicit HdForm(QWidget *parent = nullptr);
    ~HdForm();

private:
    Ui::HdForm *ui;
};

#endif // HDFORM_H
