#include "memberr.h"
#include "ui_memberr.h"
#include <msearchp.h>
#include <mbuy.h>

memberr::memberr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::memberr)
{
    ui->setupUi(this);
}

memberr::~memberr()
{
    delete ui;
}

void memberr::on_showp_clicked()
{
    msearchp * mp = new msearchp (this) ;
    mp->show();
    hide();
}

void memberr::on_buy_clicked()
{
    mbuy * mb = new mbuy (this) ;
    mb->show();
    hide();
}
