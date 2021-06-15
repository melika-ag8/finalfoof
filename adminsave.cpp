#include "adminsave.h"
#include "ui_adminsave.h"

adminsave::adminsave(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminsave)
{
    ui->setupUi(this);
}

adminsave::~adminsave()
{
    delete ui;
}
