#ifndef BIGFORM_H
#define BIGFORM_H

#include <QWidget>

namespace Ui {
class BigForm;
}

class BigForm : public QWidget
{
    Q_OBJECT

public:
    explicit BigForm(QWidget *parent = nullptr);
    ~BigForm();

private:
    Ui::BigForm *ui;
};

#endif // BIGFORM_H
