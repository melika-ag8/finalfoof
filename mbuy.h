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

    void on_calculate_clicked();

    void on_searchline_textChanged(const QString &arg1);

    void on_show_cellDoubleClicked(int row, int column);

    void on_YES_clicked();

    void on_no_clicked();

private:
    Ui::mbuy *ui;
};

#endif // MBUY_H
