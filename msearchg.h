#ifndef MSEARCHG_H
#define MSEARCHG_H

#include <QDialog>

namespace Ui {
class msearchg;
}

class msearchg : public QDialog
{
    Q_OBJECT

public:
    explicit msearchg(QWidget *parent = nullptr);
    ~msearchg();

private slots:
    void on_cancel_clicked();

    void on_searchline_textChanged(const QString &arg1);

private:
    Ui::msearchg *ui;
};

#endif // MSEARCHG_H
