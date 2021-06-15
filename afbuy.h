#ifndef AFBUY_H
#define AFBUY_H

#include <QDialog>

namespace Ui {
class afbuy;
}

class afbuy : public QDialog
{
    Q_OBJECT

public:
    explicit afbuy(QWidget *parent = nullptr);
    ~afbuy();

private slots:

    void on_done_clicked();

    void on_cancel_clicked();

    void on_reload_clicked();

private:
    Ui::afbuy *ui;
};

#endif // AFBUY_H
