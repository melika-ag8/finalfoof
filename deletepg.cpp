#include "deletepg.h"
#include "ui_deletepg.h"
#include <adminr.h>

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include <QList>
#include <QDebug>

deletepg::deletepg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletepg)
{
    ui->setupUi(this);
}

deletepg::~deletepg()
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

void deletepg::on_searchline_textChanged(const QString & m )
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

void deletepg::on_reload_2_clicked()
{
    this->ui->name->clear();
    this->ui->group->clear();
    this->ui->company->clear();
    this->ui->supply->clear();
    this->ui->price->clear();
}


void deletepg::on_exit_clicked()
{
    adminr * e = new adminr (this);
    e->show();
    hide();
}

void deletepg::on_show_cellDoubleClicked(int row, int column)
{
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

    QString t = this->ui->show->item(row,0)->text();
    int i = products.name.indexOf(t);

    this->ui->name->setText( products.name[i] );
    this->ui->group->setText( products.group[i] );
    this->ui->company->setText(products.company[i]);
    this->ui->supply->setText( products.supply[i] );
    this->ui->price->setText( products.price[i] );

}

void deletepg::on_delete_2_clicked()
{
    products products ;

    QFile file("e:/products.txt");

    QTextStream s(&file);

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

    for (int i = 0 ; i < products.name.size() ; i++ )
    {
        if ( this->ui->searchline->text() == products.name[i] )
        {
            QString s = products.name[i];
            products.name.removeOne(s) ;
            products.group.removeOne(s);
            products.company.removeOne(s);
            products.supply.removeOne(s);
            products.price.removeOne(s);

            break;
        }
    }

    file.close();

    file.open( QFile::Text | QFile::WriteOnly );

    for (int i = 0 ; i < products.name.size() ; i++ )
    {
        s << products.name[i] << " " << products.group[i] << " " << products.company[i] << " " << products.supply[i] << " " << products.price[i] << endl ;
    }

    QMessageBox::information(this, "" , "delete successfully" );
}
