#include "mfbuy.h"
#include "ui_mfbuy.h"
#include <finish.h>
#include <mbuy.h>

#include <QMessageBox>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QString>

mfbuy::mfbuy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mfbuy)
{
    ui->setupUi(this);
}

mfbuy::~mfbuy()
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

void mfbuy::on_finish_clicked()
{
    finish * f = new finish (this);
    f->show();
    hide();

    account account ;

    QFile file("memberaccount.txt");

    file.open( QFile::Append | QFile::WriteOnly );

    QTextStream s(&file);

    s << this->ui->fullnameline->text() << " " << this->ui->phoneline->text() << " " << this->ui->backline->text() << " "
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
void mfbuy::on_reload_clicked()
{
    this->ui->fullnameline->clear();
    this->ui->addressline->clear();
    this->ui->backline->clear();
    this->ui->addressline->clear();
    this->ui->creditline->clear();
}
