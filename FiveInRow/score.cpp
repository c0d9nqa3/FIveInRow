#include "score.h"
#include "ui_score.h"
#include "mainwindow.h"
Score::Score(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Score)
{
    ui->setupUi(this);
}

Score::~Score()
{
    delete ui;
}
//计算胜率修改label的文本实现战绩显示的函数
void Score::change(){
    float percentB,percentW;
    MainWindow *m=new MainWindow();
    QString Bwin=QString::number(m->BlackWin);
    QString Wwin=QString::number(m->WhiteWin);
    ui->label_blackwin->setText(Bwin);
    ui->label_whitewin->setText(Wwin);
    //(m->BlackWin)/m->count;
    //percentW=m->WhiteWin/m->count;
    //ui->label_b->setText(""+(int)percentB*100);
    //ui->label_w->setText(""+(int)percentW*100);

}
