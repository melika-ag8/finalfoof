#ifndef DELETEPG_H
#define DELETEPG_H

#include <QDialog>

namespace Ui {
class deletepg;
}

class deletepg : public QDialog
{
    Q_OBJECT

public:
    explicit deletepg(QWidget *parent = nullptr);
    ~deletepg();

private slots:
    void on_searchline_textChanged(const QString &arg1);

    void on_reload_2_clicked();

    void on_exit_clicked();

    void on_show_cellDoubleClicked(int row, int column);

    void on_delete_2_clicked();

private:
    Ui::deletepg *ui;
};

#endif // DELETEPG_H
