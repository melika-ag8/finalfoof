#include "addel.h"
#include "ui_addel.h"
#include <adminr.h>

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include <QList>
#include <QDebug>

addel::addel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addel)
{
    ui->setupUi(this);
}

addel::~addel()
{
    delete ui;
}

class products
{
public:
    QStringList name ;
    QStringList group ;
    QStringList supply ;
    QStringList price ;
};


void addel::on_exit_clicked()
{
    adminr * f = new adminr (this);
    f->show();
    hide();
}

void addel::on_add_clicked()
{
    products products ;

    QFile file("e:/products.txt");

    file.open( QFile::Append | QFile::WriteOnly );

    QTextStream s(&file);

    s << this->ui->nameline->text() << " " << this->ui->groupline->text() << " "
      << this->ui->supplyline->text() << " " << this->ui->priceline->text() << endl ;

    file.close();

    file.open( QFile::Text | QFile::ReadOnly );

    while (!s.atEnd())
    {
        QStringList a = s.readLine().split(' ');
        products.name.append( a[0]);
        products.group.append( a[1]);
        products.supply.append(a[2]);
        products.price.append(a[3]);
    }

    QMessageBox::information(this,"","add successfully");
}

void addel::on_delete_2_clicked()
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
        products.supply.append(a[2]);
        products.price.append(a[3]);
    }

    for (int i = 0 ; i < products.name.size() ; i++ )
    {
        if ( this->ui->nameline2->text() == products.name[i] )
        {
            QString s = products.name[i];
            products.name.removeOne(s) ;
            products.group.removeOne(s);
            products.supply.removeOne(s);
            products.price.removeOne(s);

            break;
        }
    }

    file.close();

    file.open( QFile::Text | QFile::WriteOnly );

    for (int i = 0 ; i < products.name.size() ; i++ )
    {
        s << products.name[i] << " " << products.group[i] << " " << products.supply[i] << " " << products.price[i] << endl ;
    }

    QMessageBox::information(this, "" , "delete successfully" );
}

void addel::on_reload_clicked()
{
    this->ui->nameline->clear();
    this->ui->groupline->clear();
    this->ui->supplyline->clear();
    this->ui->priceline->clear();
}

void addel::on_reload_2_clicked()
{
    this->ui->searchline->clear();
    this->ui->nameline2->clear();
}

void addel::on_searchline_textChanged(const QString & m )
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
        products.supply.append(a[2]);
        products.price.append(a[3]);
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
            QTableWidgetItem * name = new QTableWidgetItem ;

            name->setText(products.name[i]);

            name->setTextAlignment(Qt::AlignCenter);

            this->ui->show->setItem(r,0,name);

            r++;
        }
    }
}


void addel::on_show_cellDoubleClicked(int row, int column)
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
        products.supply.append(a[2]);
        products.price.append(a[3]);
    }

    QString t = this->ui->show->item(row,0)->text();
    int i = products.name.indexOf(t);

    this->ui->nameline2->setText(products.name[i]);
}
