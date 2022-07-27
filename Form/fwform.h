#ifndef FWFORM_H
#define FWFORM_H

#include <QWidget>

namespace Ui {
class FwForm;
}

class FwForm : public QWidget
{
    Q_OBJECT

public:
    explicit FwForm(QWidget *parent = nullptr);
    ~FwForm();

private:
    Ui::FwForm *ui;
};

#endif // FWFORM_H
