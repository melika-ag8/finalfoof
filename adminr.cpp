#include "adminr.h"
#include "ui_adminr.h"
#include <asearchp.h>
#include <asearchg.h>

#include <abuy.h>
#include <edit.h>
#include <addel.h>

adminr::adminr(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminr)
{
    ui->setupUi(this);
}

adminr::~adminr()
{
    delete ui;
}

void adminr::on_actionamong_products_triggered()
{
    asearchp * sp = new asearchp (this) ;
    sp->show();
    hide();
}

void adminr::on_actionamong_products_group_triggered()
{
    asearchg * sg = new asearchg (this) ;
    sg->show();
    hide();
}


void adminr::on_actionbuy_triggered()
{
    abuy* ab = new abuy (this) ;
        ab->show();
        hide();
}

void adminr::on_actionEdit_product_triggered()
{
    edit * e = new edit (this);
    e->show();
    hide();
}

void adminr::on_actionadd_and_delete_product_triggered()
{
    addel * m = new addel (this);
    m->show();
    hide();
}

