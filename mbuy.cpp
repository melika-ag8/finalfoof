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

void mbuy::on_enter_clicked()
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
        if ( this->ui->searchline->text() == products.name[i] )
        {
            this->ui->name->setText( products.name[i] );
            this->ui->group->setText( products.group[i] );
            this->ui->supply->setText( products.supply[i] );
            this->ui->price->setText( products.price[i] );

            break;
        }
    }
}

void mbuy::on_calculate_clicked()
{
    QString p = QString::number( this->ui->needline->text().toUInt() * this->ui->price->toPlainText().toDouble() ) ;
    this->ui->totalpriceline->setText( p );
}
