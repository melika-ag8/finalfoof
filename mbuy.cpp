#include "mbuy.h"
#include "ui_mbuy.h"
#include <mfbuy.h>
#include <memberr.h>

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include <QList>

mbuy::mbuy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mbuy)
{
    ui->setupUi(this);
}

mbuy::~mbuy()
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

void mbuy::on_buy_clicked()
{
    mfbuy * mfb = new mfbuy (this) ;
    mfb->show();
    hide();
}

void mbuy::on_cancel_clicked()
{
    memberr * c = new memberr (this);
    c->show();
    hide();
}

void mbuy::on_calculate_clicked()
{
    QString p = QString::number( this->ui->needline->text().toUInt() * this->ui->price->toPlainText().toDouble() ) ;
    this->ui->totalpriceline->setText( p );
}

void mbuy::on_searchline_textChanged(const QString & m )
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

void mbuy::on_show_cellDoubleClicked(int row, int column)
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

void mbuy::on_YES_clicked()
{
    QString p = QString::number( (this->ui->needline->text().toUInt() * this->ui->price->toPlainText().toDouble()) + 5 ) ;
    this->ui->totalpriceline->setText( p );
}

void mbuy::on_no_clicked()
{
    QString p = QString::number( (this->ui->needline->text().toUInt() * this->ui->price->toPlainText().toDouble()) ) ;
    this->ui->totalpriceline->setText( p );
}
