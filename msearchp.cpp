#include "msearchp.h"
#include "ui_msearchp.h"
#include <memberr.h>

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include <QList>

msearchp::msearchp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::msearchp)
{
    ui->setupUi(this);
}

msearchp::~msearchp()
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

void msearchp::on_cancel_clicked()
{
    memberr * c = new memberr (this);
    c->show();
    hide();
}

void msearchp::on_enter_clicked()
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
            this->ui->nameline->setText( products.name[i] );
            this->ui->groupline->setText( products.group[i] );
            this->ui->supplyline->setText( products.supply[i] );
            this->ui->priceline->setText( products.price[i] );

            break;
        }
    }
}
