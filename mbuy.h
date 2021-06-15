#ifndef MBUY_H
#define MBUY_H

#include <QDialog>

namespace Ui {
class mbuy;
}

class mbuy : public QDialog
{
    Q_OBJECT

public:
    explicit mbuy(QWidget *parent = nullptr);
    ~mbuy();

private slots:
    void on_buy_clicked();

    void on_cancel_clicked();

    void on_enter_clicked();

    void on_calculate_clicked();

private:
    Ui::mbuy *ui;
};

#endif // MBUY_H
