#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>

namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();

private:
    Ui::client *ui;
};

#endif // CLIENT_H
