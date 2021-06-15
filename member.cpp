#include "member.h"
#include "ui_member.h"
#include <memberr.h>
#include <mainwindow.h>

member::member(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::member)
{
    ui->setupUi(this);
}

member::~member()
{
    delete ui;
}

void member::on_save_clicked()
{
    memberr * r = new memberr (this);
    r->show();
    hide();
}

void member::on_save_2_clicked()
{
    memberr * r = new memberr (this);
    r->show();
    hide();
}


void member::on_cancel_clicked()
{
    MainWindow * c = new MainWindow (this);
    c->show();
    hide();
}

void member::on_cancel_2_clicked()
{
    MainWindow * c = new MainWindow (this);
    c->show();
    hide();
}
