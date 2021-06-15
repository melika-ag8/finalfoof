#ifndef MFBUY_H
#define MFBUY_H

#include <QDialog>

namespace Ui {
class mfbuy;
}

class mfbuy : public QDialog
{
    Q_OBJECT

public:
    explicit mfbuy(QWidget *parent = nullptr);
    ~mfbuy();

private slots:

    void on_cancel_clicked();

    void on_finish_clicked();

private:
    Ui::mfbuy *ui;
};

#endif // MFBUY_H
