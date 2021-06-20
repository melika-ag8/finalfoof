#ifndef ABUY_H
#define ABUY_H

#include <QDialog>

namespace Ui {
class abuy;
}

class abuy : public QDialog
{
    Q_OBJECT

public:
    explicit abuy(QWidget *parent = nullptr);
    ~abuy();

private slots:

    void on_buy_clicked();

    void on_cancel_clicked();

    void on_searchline_textChanged(const QString &arg1);

    void on_show_cellDoubleClicked(int row, int column);

    void on_yes_clicked();

    void on_no_clicked();

private:
    Ui::abuy *ui;
};

#endif // ABUY_H
