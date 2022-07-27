#include "switchform.h"
#include "ui_switchform.h"

SwitchForm::SwitchForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SwitchForm)
{
    ui->setupUi(this);
}

SwitchForm::~SwitchForm()
{
    delete ui;
}
