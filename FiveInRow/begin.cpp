#include "mainwindow.h"
#include <QApplication>
#include "begin.h"
#include "ui_begin.h"

Begin::Begin(QWidget *parent) :
    QMainWindow (parent),
    ui(new Ui::Begin)
{
    ui->setupUi(this);
}

Begin::~Begin()
{
    delete ui;
}

void Begin::on_btnPlay_clicked()
{
    this->close();
    MainWindow *MW=new MainWindow();
    MW->show();
}


