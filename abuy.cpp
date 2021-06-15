#include "abuy.h"
#include "ui_abuy.h"
#include <afbuy.h>
#include <adminr.h>

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QString>
#include <QMessageBox>

abuy::abuy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::abuy)
{
    ui->setupUi(this);
}

abuy::~abuy()
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

void abuy::on_buy_clicked()
{
    afbuy * afb = new afbuy (this);
    afb->show();
    hide();
}

void abuy::on_cancel_clicked()
{
    adminr * c = new adminr (this);
    c->show();
    hide();
}

void abuy::on_calculate_clicked()
{
    QString p = QString::number( this->ui->needline->text().toUInt() * this->ui->price->toPlainText().toDouble() ) ;
    this->ui->totalpriceline->setText( p );
}

void abuy::on_searchline_textChanged(const QString & m )
{int r = 0 ;

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


void abuy::on_show_cellDoubleClicked(int row, int column)
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

    this->ui->name->setText( products.name[i] );
    this->ui->group->setText( products.group[i] );
    this->ui->supply->setText( products.supply[i] );
    this->ui->price->setText( products.price[i] );

}
