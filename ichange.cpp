#include "ichange.h"
#include "ui_ichange.h"
#include <asignin.h>

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QMessageBox>


ichange::ichange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ichange)
{
    ui->setupUi(this);
}

ichange::~ichange()
{
    delete ui;
}

class admin
{
public:
    QStringList user ;
    QStringList pass ;
    QStringList acode ;
    QStringList ncode ;
    QStringList email ;
};

void ichange::on_cancel_clicked()
{
    asignin * c = new asignin (this) ;
    c->show();
    hide();
}

void ichange::on_change_clicked()
{

    admin admin ;

    QMessageBox::information(this,"","change successfully");

    QFile file("e:/admin.txt");

    QTextStream s(&file);

    file.open( QFile::Text | QFile::ReadOnly );

    while (!s.atEnd())
    {
        QStringList a = s.readLine().split(' ');
        admin.user.append(a[0]);
        admin.pass.append(a[1]);
        admin.acode.append(a[2]);
        admin.ncode.append(a[3]);
        admin.email.append(a[4]);
    }

    file.close();

    for (int i = 0 ; i < admin.user.size() ; i++ )
    {
        if ( this->ui->userline->text() == admin.user[i] && this->ui->ncodeline->text() == admin.ncode[i]
             && this->ui->emailline->text() == admin.email[i] )
        {
            admin.pass[i] = this->ui->newpassline->text();
            break;
        }
    }

    file.open( QFile::Text | QFile::WriteOnly );

    for (int i = 0 ; i < admin.user.size() ; i++ )
    {
        s << admin.user[i] << " " << admin.pass[i] << " " << admin.acode[i] << " " << admin.ncode[i] << " " << admin.email[i] << endl ;
    }

    asignin * c = new asignin (this) ;
    c->show();
    hide();

}
