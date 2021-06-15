#include "finish.h"
#include "ui_finish.h"
#include <mainwindow.h>

finish::finish(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::finish)
{
    ui->setupUi(this);
}

finish::~finish()
{
    delete ui;
}

void finish::on_pushButton_clicked()
{
    MainWindow * b = new MainWindow (this);
    b->show();
    hide();
}
