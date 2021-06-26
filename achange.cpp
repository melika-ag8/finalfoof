#include "achange.h"
#include "ui_achange.h"
#include <asignin.h>

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QString>
#include <QMessageBox>

achange::achange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::achange)
{
    ui->setupUi(this);
}

achange::~achange()
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

void achange::on_change_clicked()
{
    admin admin ;

    QFile file("admin.txt");

    QTextStream d(&file);

    file.open( QFile::Text | QFile::ReadOnly );

    while (!d.atEnd())
    {
        QStringList a = d.readLine().split(' ');
        admin.user.append(a[0]);
        admin.pass.append(a[1]);
        admin.acode.append(a[2]);
        admin.ncode.append(a[3]);
        admin.email.append(a[4]);
    }

    file.close();

    bool check = false ;

    for (int i = 0 ; i < admin.user.size() ; i++ )
    {
        if ( this->ui->userline->text() == admin.user[i] && this->ui->acodeline->text() == admin.acode[i] && this->ui->ncodeline->text() == admin.ncode[i] && this->ui->emailline->text() == admin.email[i] )
        {
            check = true ;
            admin.pass[i] = this->ui->newpassline->text() ;

            break ;
        }
    }

    if ( check == false )
    {
        QMessageBox::information(this, "" , "wrong user info" );
    }
    else
    {
        QMessageBox::information(this, "" , "change successfully" );

        asignin * r = new asignin (this);
        r->show() ;
        hide();
    }

    file.open( QFile::Text | QFile::WriteOnly );

    for (int i = 0 ; i < admin.user.size() ; i++ )
    {
     d << admin.user[i] << " " << admin.pass[i] << " " << admin.acode[i] << " " << admin.ncode[i] << " " << admin.email[i] << endl ;
    }
}

void achange::on_exit_clicked()
{
    asignin * r = new asignin (this);
    r->show() ;
    hide();
}
