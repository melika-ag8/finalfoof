#ifndef EDIT_H
#define EDIT_H

#include <QDialog>

namespace Ui {
class edit;
}

class edit : public QDialog
{
    Q_OBJECT

public:
    explicit edit(QWidget *parent = nullptr);
    ~edit();

private slots:

    void on_searchline_textChanged(const QString &arg1);

    void on_reload_clicked();

    void on_change_clicked();

    void on_cancel_clicked();

private:
    Ui::edit *ui;
};

#endif // EDIT_H
