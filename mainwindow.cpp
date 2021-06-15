#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <asignin.h>
#include <asignup.h>
#include <msignin.h>
#include <msignup.h>

#include <QFile>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_adminin_clicked()
{
    asignin * ai = new asignin (this);
    ai->show();
    hide();
}

void MainWindow::on_adminup_clicked()
{
    asignup * ap = new asignup (this);
    ap->show();
    hide();
}

void MainWindow::on_memberin_clicked()
{
    msignin * mi = new msignin (this);
    mi->show();
    hide();
}

void MainWindow::on_memberup_clicked()
{
    msignup * mp = new msignup (this);
    mp->show();
    hide();
}
