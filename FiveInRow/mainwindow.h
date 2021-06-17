#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Item.h"
#include "qmap.h"
#define CHESS_ROWS		15
#define CHESS_COLUMES	15
#define RECT_WIDTH		45
#define RECT_HEIGHT		45

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int BlackWin=0,WhiteWin=0;  //记录黑棋白棋赢的局数
    //float rx,ry;
    QPoint pt2;
protected:
    void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *);
private:
	void DrawChessboard();
    void changenum();
	void DrawItems();
	void DrawItemWithMouse();
	void DrawChessAtPoint(QPainter& painter,QPoint& pt);
	int CountNearItem(Item item,QPoint ptDirection);	//统计某个方向(共8个方向)上的相连个数，用QPoint表示统计方向，如(1,1)表示右下方,（-1,0）表示向左
private:
    Ui::MainWindow *ui;

    QVector<Item> mItems;
    bool mIsBlackTurn;	//当前该黑棋下

};

#endif
