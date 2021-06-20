#include "edit.h"
#include "ui_edit.h"
#include <adminr.h>

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include <QList>
#include <QDebug>

edit::edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit)
{
    ui->setupUi(this);
}

edit::~edit()
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

void edit::on_searchline_textChanged(const QString & m )
{
    int r = 0 ;

    products products ;

    QFile file("e:/products.txt");

    QTextStream s(&file);

    file.open( QFile::Text | QFile::ReadOnly );

    while (!s.atEnd())
    {
        QStringList a = s.readLine().split(' ');
        products.name.append(a[0]);
        products.group.append(a[1]);
        products.company.append(a[2]);
        products.supply.append(a[3]);
        products.price.append(a[4]);
    }

    for (int i = 0 ; i < 20 ; ++i )
    {
        for (int i = 0 ; i < 20 ; ++i )
        {
            ui->show->removeRow(i);
        }
    }
    for (int i = 0 ; i <  products.name.size() ; i++ )
    {
        QString f = products.name[i] ;
        if ( f.contains( m ) )
        {
            this->ui->show->insertRow(r);
            QTableWidgetItem * group = new QTableWidgetItem ;
            QTableWidgetItem * name = new QTableWidgetItem ;
            QTableWidgetItem * supply = new QTableWidgetItem ;
            QTableWidgetItem * price = new QTableWidgetItem ;
            QTableWidgetItem * company = new QTableWidgetItem ;

            group->setText(products.group[i]);
            name->setText(products.name[i]);
            supply->setText(products.supply[i]);
            price->setText(products.price[i]);
            company->setText(products.company[i]);

            group->setTextAlignment(Qt::AlignCenter);
            name->setTextAlignment(Qt::AlignCenter);
            supply->setTextAlignment(Qt::AlignCenter);
            price->setTextAlignment(Qt::AlignCenter);
            company->setTextAlignment(Qt::AlignCenter);

            this->ui->show->setItem(r,0,name);
            this->ui->show->setItem(r,1,group);
            this->ui->show->setItem(r,2,company);
            this->ui->show->setItem(r,3,supply);
            this->ui->show->setItem(r,4,price);

            r++;
        }
    }
}

void edit::on_reload_clicked()
{
    this->ui->searchline->clear();
}

void edit::on_change_clicked()
{
    products products ;

    QMessageBox::information(this,"","change successfully");

    QFile file("e:/products.txt");

    QTextStream s(&file);

    file.open( QFile::Text | QFile::ReadOnly );

    while (!s.atEnd())
    {
        QStringList a = s.readLine().split(' ');
        products.name.append(a[0]);
        products.group.append(a[1]);
        products.company.append(a[2]);
        products.supply.append(a[3]);
        products.price.append(a[4]);
    }

    file.close();

    for (int i = 0 ; i < products.name.size() ; i++ )
    {
        if ( this->ui->searchline->text() == products.name[i] )
        {
            products.name[i] = this->ui->newname->text();
            products.group[i] = this->ui->newgroup->text();
            products.company[i] = this->ui->newcompany->text();
            products.supply[i] = this->ui->newsupply->text();
            products.price[i] = this->ui->newprice->text();
            break;
        }
    }

    file.open( QFile::Text | QFile::WriteOnly );

    for (int i = 0 ; i < products.name.size() ; i++ )
    {
        s << products.name[i] << " " << products.group[i] << " " << products.company[i] << " " << products.supply[i] << " " << products.price[i] << endl ;
    }
}

void edit::on_cancel_clicked()
{
    adminr * c = new adminr (this);
    c->show();
    hide();
}
