#ifndef ASEARCHG_H
#define ASEARCHG_H

#include <QDialog>

namespace Ui {
class asearchg;
}

class asearchg : public QDialog
{
    Q_OBJECT

public:
    explicit asearchg(QWidget *parent = nullptr);
    ~asearchg();

private slots:

    void on_cancel_clicked();

    void on_searchline_textChanged(const QString &arg1);

private:
    Ui::asearchg *ui;
};

#endif // ASEARCHG_H
