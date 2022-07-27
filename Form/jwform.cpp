#include "jwform.h"
#include "ui_jwform.h"

JwForm::JwForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JwForm)
{
    ui->setupUi(this);
}

JwForm::~JwForm()
{
    delete ui;
}
