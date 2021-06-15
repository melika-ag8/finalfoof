#ifndef ADDEL_H
#define ADDEL_H

#include <QDialog>

namespace Ui {
class addel;
}

class addel : public QDialog
{
    Q_OBJECT

public:
    explicit addel(QWidget *parent = nullptr);
    ~addel();

private slots:

    void on_exit_clicked();

    void on_add_clicked();

    void on_delete_2_clicked();

    void on_reload_clicked();

    void on_reload_2_clicked();

    void on_searchline_textChanged(const QString &arg1);

    void on_show_cellDoubleClicked(int row, int column);

private:
    Ui::addel *ui;
};

#endif // ADDEL_H
