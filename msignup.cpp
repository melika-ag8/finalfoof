#include "msignup.h"
#include "ui_msignup.h"
#include <mainwindow.h>
#include <memberr.h>

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>

msignup::msignup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::msignup)
{
    ui->setupUi(this);
}

msignup::~msignup()
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

void msignup::on_cancel_clicked()
{
    MainWindow * c = new MainWindow (this);
    c->show();
    hide();
}

void msignup::on_save_clicked()
{
    member member ;

    QFile file("e:/member.txt");

    QTextStream s(&file);

    file.open( QFile::Text | QFile::ReadOnly );

    while (!s.atEnd())
    {
        QStringList a = s.readLine().split(' ');
        member.user.append(a[0]);
        member.pass.append(a[1]);
        member.ncode.append(a[2]);
        member.email.append(a[3]);
    }

    file.close();

    bool check = false ;

    for (int i = 0 ; i < member.user.size() ; i++ )
    {
        if ( this->ui->userline->text() == member.user[i] )
        {
            check = true ;
            break;
        }
    }

    if ( check == true )
    {
        QMessageBox::information(this, "" , "you can not choose this username" );
    }
    else
    {
        file.open( QFile::Append | QFile::WriteOnly );

        s << this->ui->userline->text() << " " << this->ui->passline->text() << " " <<
         this->ui->ncodeline->text() << " " << this->ui->emailline->text() << endl ;

        memberr * r = new memberr (this);
        r->show();
        hide();
    }
}

void msignup::on_reload_clicked()
{
    this->ui->userline->clear();
    this->ui->passline->clear();
    this->ui->ncodeline->clear();
    this->ui->emailline->clear();
}
