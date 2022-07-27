#include "fwform.h"
#include "ui_fwform.h"

FwForm::FwForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FwForm)
{
    ui->setupUi(this);
}

FwForm::~FwForm()
{
    delete ui;
}
