#ifndef SWITCHFORM_H
#define SWITCHFORM_H

#include <QWidget>

namespace Ui {
class SwitchForm;
}

class SwitchForm : public QWidget
{
    Q_OBJECT

public:
    explicit SwitchForm(QWidget *parent = nullptr);
    ~SwitchForm();

private:
    Ui::SwitchForm *ui;
};

#endif // SWITCHFORM_H
