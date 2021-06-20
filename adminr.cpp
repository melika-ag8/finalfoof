#include "adminr.h"
#include "ui_adminr.h"
#include <asearchg.h>

#include <abuy.h>
#include <edit.h>
#include <adminadd.h>
#include <deletepg.h>

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
    adminadd * m = new adminadd (this);
    m->show();
    hide();
}


void adminr::on_actiondelete_products_with_groups_triggered()
{
    deletepg * d = new deletepg (this);
    d->show();
    hide();
}

void adminr::on_actionamong_products_triggered()
{
    asearchg * s = new asearchg (this);
    s->show();
    hide();
}
