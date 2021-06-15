#ifndef ADMINSAVE_H
#define ADMINSAVE_H

#include <QMainWindow>

namespace Ui {
class adminsave;
}

class adminsave : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminsave(QWidget *parent = nullptr);
    ~adminsave();

private:
    Ui::adminsave *ui;
};

#endif // ADMINSAVE_H
