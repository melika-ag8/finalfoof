#include "asearchg.h"
#include "ui_asearchg.h"
#include <adminr.h>

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QString>
#include <QMessageBox>

asearchg::asearchg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::asearchg)
{
    ui->setupUi(this);
}

asearchg::~asearchg()
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

void asearchg::on_cancel_clicked()
{
    adminr * c = new adminr (this);
    c->show();
    hide();
}

void asearchg::on_searchline_textChanged(const QString & m )
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
            ui->showg->removeRow(i);
        }
    }

    for (int i = 0 ; i <  products.name.size() ; i++ )
    {
        QString f = products.group[i] ;
        if ( f.contains( m ) )
        {
            this->ui->showg->insertRow(r);
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

            this->ui->showg->setItem(r,0,group);
            this->ui->showg->setItem(r,1,name);
            this->ui->showg->setItem(r,2,supply);
            this->ui->showg->setItem(r,3,price);

            r++;
        }
    }
}












