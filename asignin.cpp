#include "asignin.h"
#include "ui_asignin.h"
#include <mainwindow.h>
#include <adminr.h>
#include <achange.h>
//#include <ichange.h>

#include <QMessageBox>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QString>
#include <QDebug>

asignin::asignin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::asignin)
{
    ui->setupUi(this);
}

asignin::~asignin()
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

void asignin::on_cancel_clicked()
{
    MainWindow * c = new MainWindow (this);
    c->show();
    hide();
}   

void asignin::on_reload_clicked()
{
    this->ui->userline->clear();
    this->ui->passline->clear();
}

void asignin::on_save_clicked()
{
    admin admin ;

    QFile file("e:/admin.txt");

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

    bool check = false ;

    for (int i = 0 ; i < admin.user.size() ; i++ )
    {
        if ( this->ui->userline->text() == admin.user[i] && this->ui->passline->text() == admin.pass[i] )
        {
            check = true ;
            adminr * r = new adminr (this);
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

void asignin::on_changepass_clicked()
{
    achange * ch = new achange (this);
    ch->show();
    hide();
}
