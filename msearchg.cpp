#include "msearchg.h"
#include "ui_msearchg.h"
#include <memberr.h>

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include <QList>

msearchg::msearchg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::msearchg)
{
    ui->setupUi(this);
}

msearchg::~msearchg()
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

void msearchg::on_cancel_clicked()
{
    memberr * c = new memberr (this);
    c->show();
    hide();
}

void msearchg::on_searchline_textChanged(const QString & m )
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
