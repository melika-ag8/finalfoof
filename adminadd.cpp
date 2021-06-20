#include "adminadd.h"
#include "ui_adminadd.h"
#include <adminr.h>

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include <QList>
#include <QDebug>


adminadd::adminadd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminadd)
{
    ui->setupUi(this);
}

adminadd::~adminadd()
{
    delete ui;
}

class products
{
public:
    QStringList name ;
    QStringList group ;
    QStringList company ;
    QStringList supply ;
    QStringList price ;
};

void adminadd::on_add_clicked()
{
    products products ;

    QFile file("e:/products.txt");

    file.open( QFile::Append | QFile::WriteOnly );

    QTextStream s(&file);

    s << this->ui->nameline->text() << " " << this->ui->groupline->text() << " " << this->ui->companyline->text() << " "
      << this->ui->supplyline->text() << " " << this->ui->priceline->text() << endl ;

    file.close();

    file.open( QFile::Text | QFile::ReadOnly );

    while (!s.atEnd())
    {
        QStringList a = s.readLine().split(' ');
        products.name.append( a[0]);
        products.group.append( a[1]);
        products.company.append(a[2]);
        products.supply.append(a[3]);
        products.price.append(a[4]);
    }

    QMessageBox::information(this,"","add successfully");
}

void adminadd::on_reload_clicked()
{
    this->ui->nameline->clear();
    this->ui->groupline->clear();
    this->ui->companyline->clear();
    this->ui->supplyline->clear();
    this->ui->priceline->clear();
}

void adminadd::on_exit_clicked()
{
    adminr * f = new adminr (this);
        f->show();
        hide();
}
