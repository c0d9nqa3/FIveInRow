#ifndef BEGIN_H
#define BEGIN_H

#include <QWidget>

#include <QMainWindow>
#include <QDialog>

namespace Ui {
class Begin;
}

class Begin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Begin(QWidget *parent = nullptr);
    ~Begin();

private slots:
    void on_btnPlay_clicked();

    //void on_pushButton_clicked();

private:
    Ui::Begin *ui;
};

#endif // BEGIN_H
