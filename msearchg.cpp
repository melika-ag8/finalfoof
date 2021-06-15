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

void msearchg::on_enter_clicked()
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
        if ( this->ui->searchline->text() == products.group[i] )
        {
            this->ui->groupline->setText( products.group[i] );

            break;
        }
    }
}
