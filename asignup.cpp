#include "asignup.h"
#include "ui_asignup.h"
#include <mainwindow.h>
#include <adminr.h>

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QMessageBox>

asignup::asignup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::asignup)
{
    ui->setupUi(this);
}

asignup::~asignup()
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

int admincode = 789 ;

void asignup::on_save_clicked()
{
    admin admin ;

    QFile file("admin.txt");

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

    bool adminc = true ;
    bool name = true ;

    for (int i = 0 ; i < admin.user.size() ; i++ )
    {
        if ( this->ui->acodeline->text().toInt() != admincode )
        {
            adminc = false ;
            break;
        }
        else if ( this->ui->userline->text() == admin.user[i] )
        {
            name = false ;
            break;
        }
    }

    if ( adminc == false )
    {
        QMessageBox::information(this, "" , "you are not the admin" );
    }
    else if ( name == false )
    {
        QMessageBox::information(this, "" , "you can not choose this username" );
    }
    else
    {
        file.open( QFile::Append | QFile::WriteOnly );

        s << this->ui->userline->text() << " " << this->ui->passline->text() << " " << this->ui->acodeline->text() << " "
          << this->ui->codeline->text() << " " << this->ui->emailline->text() << endl ;

        adminr * r = new adminr (this);
        r->show();
        hide();
    }

}

void asignup::on_cancel_clicked()
{
    MainWindow * c = new MainWindow (this);
    c->show();
    hide();
}

void asignup::on_reload_clicked()
{
    this->ui->userline->clear();
    this->ui->passline->clear();
    this->ui->acodeline->clear();
    this->ui->codeline->clear();
    this->ui->emailline->clear();
}
