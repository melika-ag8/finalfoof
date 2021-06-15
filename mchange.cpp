#include "mchange.h"
#include "ui_mchange.h"
#include <msignin.h>

#include <QMessageBox>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QString>

mchange::mchange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mchange)
{
    ui->setupUi(this);
}

mchange::~mchange()
{
    delete ui;
}

class member
{
public:
    QStringList user ;
    QStringList pass ;
    QStringList ncode ;
    QStringList email ;
};

void mchange::on_change_clicked()
{
    member member ;

    QFile file("e:/member.txt");

    QTextStream d(&file);

    file.open( QFile::Text | QFile::ReadOnly );

    while (!d.atEnd())
    {
        QStringList a = d.readLine().split(' ');
        member.user.append(a[0]);
        member.pass.append(a[1]);
        member.ncode.append(a[2]);
        member.email.append(a[3]);
    }

    file.close();

    bool check = false ;

    for (int i = 0 ; i < member.user.size() ; i++ )
    {
        if ( this->ui->userline->text() == member.user[i] && this->ui->ncodeline->text() == member.ncode[i] && this->ui->emailline->text() == member.email[i] )
        {
            check = true ;
            member.pass[i] = this->ui->newpassline->text() ;

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

        msignin * r = new msignin (this);
        r->show() ;
        hide();
    }

    file.open( QFile::Text | QFile::WriteOnly );

    for (int i = 0 ; i < member.user.size() ; i++ )
    {
     d << member.user[i] << " " << member.pass[i] << " " << member.ncode[i] << " " << member.email[i] << endl ;
    }
}


void mchange::on_exit_clicked()
{
    msignin * r = new msignin (this);
    r->show() ;
    hide();
}
