#include "hafla.h"
#include "ui_hafla.h"

hafla::hafla(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hafla)
{
    ui->setupUi(this);
}

hafla::~hafla()
{
    delete ui;
}
