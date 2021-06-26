#include "afbuy.h"
#include "ui_afbuy.h"
#include <abuy.h>
#include <finish.h>

#include <QMessageBox>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QString>

afbuy::afbuy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afbuy)
{
    ui->setupUi(this);
}

afbuy::~afbuy()
{
    delete ui;
}

class account
{
public:
  QStringList fullname ;
  QStringList phone ;
  QStringList backemail ;
  QStringList address ;
  QStringList credit ;
};


void afbuy::on_cancel_clicked()
{
    abuy * c = new abuy (this);
    c->show();
    hide();
}

void afbuy::on_done_clicked()
{
    finish * f = new finish ;
    f->show();
    hide();

    account account ;

    QFile file("adminaccount.txt");

    file.open( QFile::Append | QFile::WriteOnly );

    QTextStream s(&file);

    s << this->ui->fullnameline->text() << " " << this->ui->phoneline->text() << " " << this->ui->backupline->text() << " "
      << this->ui->addressline->text() << " " << this->ui->creditline->text() << endl ;

    file.close();

    file.open( QFile::Text | QFile::ReadOnly );

    while (!s.atEnd())
    {
        QStringList a = s.readLine().split(' ');
        account.fullname.append(a[0]);
        account.phone.append(a[1]);
        account.backemail.append(a[2]);
        account.address.append(a[3]);
        account.credit.append(a[4]);
    }

    file.close();

}

void afbuy::on_reload_clicked()
{
    this->ui->fullnameline->clear();
    this->ui->phoneline->clear();
    this->ui->backupline->clear();
    this->ui->addressline->clear();
    this->ui->creditline->clear();
}
