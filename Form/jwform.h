#ifndef JWFORM_H
#define JWFORM_H

#include <QWidget>

namespace Ui {
class JwForm;
}

class JwForm : public QWidget
{
    Q_OBJECT

public:
    explicit JwForm(QWidget *parent = nullptr);
    ~JwForm();

private:
    Ui::JwForm *ui;
};

#endif // JWFORM_H
