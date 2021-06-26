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
    QStringList company ;
    QStringList supply ;
    QStringList price ;
};

void msearchp::on_searchline_textChanged(const QString & m)
{
    if ( this->ui->product->isChecked() )
    {
        int r = 0 ;

        products products ;

        QFile file("products.txt");

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
                ui->showg->removeRow(i);
            }
        }
        for (int i = 0 ; i <  products.name.size() ; i++ )
        {
            QString f = products.name[i] ;
            if ( f.contains( m ) )
            {
                this->ui->showg->insertRow(r);
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

                this->ui->showg->setItem(r,0,name);
                this->ui->showg->setItem(r,1,group);
                this->ui->showg->setItem(r,2,company);
                this->ui->showg->setItem(r,3,supply);
                this->ui->showg->setItem(r,4,price);

                r++;
            }
        }
    }
    else if ( this->ui->group->isChecked())
    {
        int r = 0 ;

        products products ;

        QFile file("products.txt");

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

                this->ui->showg->setItem(r,0,name);
                this->ui->showg->setItem(r,1,group);
                this->ui->showg->setItem(r,2,company);
                this->ui->showg->setItem(r,3,supply);
                this->ui->showg->setItem(r,4,price);

                r++;
            }
        }
    }
    else if ( this->ui->company->isChecked() )
    {
        int r = 0 ;

        products products ;

        QFile file("products.txt");

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
                ui->showg->removeRow(i);
            }
        }
        for (int i = 0 ; i <  products.name.size() ; i++ )
        {
            QString f = products.company[i] ;
            if ( f.contains( m ) )
            {
                this->ui->showg->insertRow(r);
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

                this->ui->showg->setItem(r,0,name);
                this->ui->showg->setItem(r,1,group);
                this->ui->showg->setItem(r,2,company);
                this->ui->showg->setItem(r,3,supply);
                this->ui->showg->setItem(r,4,price);

                r++;
            }
        }
    }
}

void msearchp::on_cancel_clicked()
{
    memberr * c = new memberr (this);
    c->show();
    hide();
}
