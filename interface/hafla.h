#ifndef HAFLA_H
#define HAFLA_H

#include <QDialog>

namespace Ui {
class hafla;
}

class hafla : public QDialog
{
    Q_OBJECT

public:
    explicit hafla(QWidget *parent = nullptr);
    ~hafla();

private:
    Ui::hafla *ui;
};

#endif // HAFLA_H
