#include "asearchp.h"
#include "ui_asearchp.h"
#include <adminr.h>

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QString>
#include <QDebug>

asearchp::asearchp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::asearchp)
{
    ui->setupUi(this);
}

asearchp::~asearchp()
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


void asearchp::on_cancel_clicked()
{
    adminr * c = new adminr (this);
    c->show();
    hide();
}

void asearchp::on_searchline_textChanged(const QString & m )
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
            QTableWidgetItem * group = new QTableWidgetItem ;
            QTableWidgetItem * name = new QTableWidgetItem ;
            QTableWidgetItem * supply = new QTableWidgetItem ;
            QTableWidgetItem * price = new QTableWidgetItem ;

            group->setText(products.group[i]);
            name->setText(products.name[i]);
            supply->setText(products.supply[i]);
            price->setText(products.price[i]);

            group->setTextAlignment(Qt::AlignCenter);
            name->setTextAlignment(Qt::AlignCenter);
            supply->setTextAlignment(Qt::AlignCenter);
            price->setTextAlignment(Qt::AlignCenter);

            this->ui->show->setItem(r,0,name);
            this->ui->show->setItem(r,1,group);
            this->ui->show->setItem(r,2,supply);
            this->ui->show->setItem(r,3,price);

            r++;
        }
    }
}
