#include "msignin.h"
#include "ui_msignin.h"
#include <mainwindow.h>
#include <memberr.h>
#include <mchange.h>
//#include <mchange.h>

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include <QDebug>

msignin::msignin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::msignin)
{
    ui->setupUi(this);
}

msignin::~msignin()
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

void msignin::on_cancel_clicked()
{
    MainWindow * c = new MainWindow (this);
    c->show();
    hide();
}

void msignin::on_save_clicked()
{
    member member ;

    QFile file("member.txt");

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

    bool check = false ;

    for (int i = 0 ; i < member.user.size() ; i++ )
    {
        if ( this->ui->userline->text() == member.user[i] && this->ui->passline->text() == member.pass[i] )
        {
            check = true ;
            memberr * r = new memberr (this);
            r->show() ;
            hide();
            break;
        }

    }

    if ( check == false )
    {
        QMessageBox::information(this, "" , "wrong username or password" );
    }
}

void msignin::on_reload_clicked()
{
    this->ui->passline->clear();
    this->ui->userline->clear();
}

void msignin::on_changepass_clicked()
{
mchange * ch = new mchange (this);
ch->show();
hide();
}
