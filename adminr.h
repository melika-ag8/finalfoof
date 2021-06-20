#ifndef ADMINR_H
#define ADMINR_H

#include <QMainWindow>
//#include <searchp.h>
//#include <searchg.h>

namespace Ui {
class adminr;
}

class adminr : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminr(QWidget *parent = nullptr);
    ~adminr();

private slots:

    void on_actionbuy_triggered();

    void on_actionEdit_product_triggered();

    void on_actionadd_and_delete_product_triggered();

    void on_actiondelete_products_with_groups_triggered();

    void on_actionamong_products_triggered();

private:
    Ui::adminr *ui;
};

#endif // ADMINR_H
