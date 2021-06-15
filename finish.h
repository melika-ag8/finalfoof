#ifndef FINISH_H
#define FINISH_H

#include <QDialog>

namespace Ui {
class finish;
}

class finish : public QDialog
{
    Q_OBJECT

public:
    explicit finish(QWidget *parent = nullptr);
    ~finish();

private slots:
    void on_pushButton_clicked();

private:
    Ui::finish *ui;
};

#endif // FINISH_H
