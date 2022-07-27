#include "hdform.h"
#include "ui_hdform.h"

HdForm::HdForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HdForm)
{
    ui->setupUi(this);
}

HdForm::~HdForm()
{
    delete ui;
}
