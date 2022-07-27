#include "bigform.h"
#include "ui_bigform.h"

BigForm::BigForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BigForm)
{
    ui->setupUi(this);
}

BigForm::~BigForm()
{
    delete ui;
}
