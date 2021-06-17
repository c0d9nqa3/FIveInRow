#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include "qevent.h"
#include "qpoint.h"
#include "qmessagebox.h"
#include <QPainter>
#include <QMouseEvent>
#include <QWidget>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(867,(CHESS_ROWS + 1)*RECT_HEIGHT+40);
    //resize((CHESS_COLUMES + 1)*RECT_WIDTH  ,(CHESS_ROWS + 1)*RECT_HEIGHT);
    mIsBlackTurn = true;
    changenum();
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *e)
{
	DrawChessboard();		//画棋盘
	DrawItems();			//画棋子
	DrawItemWithMouse();	//画鼠标（当前方的棋子形状）

	update();
}
void MainWindow::DrawChessboard()
{
	QPainter painter(this);
    QBrush brush;//色刷，填充棋盘颜色
    brush.setColor(QColor("#EEC085"));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    for(int i = 0;i<CHESS_COLUMES; i++)
    {
        for (int j = 0; j<CHESS_ROWS; j++)
        {
            painter.drawRect( (i+0.5)*RECT_WIDTH,(j+0.5)*RECT_HEIGHT,RECT_WIDTH,RECT_HEIGHT);
        }
    }


}

void MainWindow::DrawItems()
{
	QPainter painter(this);
	painter.setPen(QPen(QColor(Qt::transparent)));

    for (int i = 0; i<mItems.size(); i++)
	{
		Item item = mItems[i];
		if (item.mBlack)
		{
			painter.setBrush(Qt::black);
		}
		else
		{
            painter.setBrush(Qt::white);
		}
		DrawChessAtPoint(painter,item.mPt);
	}
}





void MainWindow::DrawChessAtPoint(QPainter& painter,QPoint& pt)
{
    QPoint ptCenter((pt.x()+0.5)*RECT_WIDTH,(pt.y()+0.5)*RECT_HEIGHT);
   // rx=pt.x();ry=pt.y();
    painter.drawEllipse(ptCenter,RECT_WIDTH / 3,RECT_HEIGHT / 3);
}

void MainWindow::DrawItemWithMouse()
{
	QPainter painter(this);
	painter.setPen(QPen(QColor(Qt::transparent)));
	if (mIsBlackTurn)
	{
		painter.setBrush(Qt::black);
	}
	else
	{
		painter.setBrush(Qt::white);
	}
    painter.drawEllipse(mapFromGlobal(QCursor::pos()),RECT_WIDTH / 3,RECT_HEIGHT / 3);
}

void MainWindow::mousePressEvent(QMouseEvent * e)
{
    if(e->button()==Qt::LeftButton){
	//求鼠标点击处的棋子点pt
    QPoint pt;
	pt.setX( (e->pos().x() ) / RECT_WIDTH);
	pt.setY( (e->pos().y() ) / RECT_HEIGHT);
    pt2=pt;

	//如果已存在棋子，就什么也不做
	for (int i = 0; i<mItems.size(); i++)
	{
		Item item = mItems[i];
		if (item.mPt == pt)
		{
			//已有棋子
			return;
		}
	}
    //不存在棋子，就下一个棋子
	Item item(pt,mIsBlackTurn);
	mItems.append(item);
    //mItems.removeOne(item);

    //统计8个方向是否五子连
    int nLeft=CountNearItem(item,QPoint(-1,0));
    int nLeftUp=CountNearItem(item,QPoint(-1,-1));
    int nUp=CountNearItem(item,QPoint(0,-1));
    int nRightUp=CountNearItem(item,QPoint(1,-1));
    int nRight =CountNearItem(item,QPoint(1,0));
    int nRightDown=CountNearItem(item,QPoint(1,1));
    int nDown=CountNearItem(item,QPoint(0,1));
    int nLeftDown=CountNearItem(item,QPoint(-1,1));
    if ((nLeft+nRight) >= 4 ||
		 (nLeftUp + nRightDown) >= 4 ||
		 (nUp + nDown) >= 4 ||
		 (nRightUp + nLeftDown) >= 4 )
	{
		QString str = mIsBlackTurn?"Black":"White";
        if(str=="Black"){
            BlackWin++;

        }
        else {
            WhiteWin++;
        }
        changenum();
        QMessageBox::information(NULL, "GAME OVER",str, QMessageBox::Yes , QMessageBox::Yes);

		mItems.clear();
        //count++;
		return;
	}
	//该另一方下棋了
	mIsBlackTurn = !mIsBlackTurn;
    }



        // 鼠标右键点击悔棋
   else if(e->button()==Qt::RightButton){
        for (int i = 0; i<mItems.size(); i++)
        {
            Item item = mItems[i];
            if (item.mPt == pt2)
            {
                mItems.removeOne(item);
            }
        }

    }
}

int MainWindow::CountNearItem(Item item,QPoint ptDirection)
{
	int nCount = 0;
    item.mPt=item.mPt+ptDirection;

	while (mItems.contains(item))
	{
		nCount++;
		item.mPt += ptDirection;
	}
	return nCount;
}


void MainWindow::changenum(){
    QString B=QString::number(BlackWin,10);
    QString W=QString::number(WhiteWin,10);
    ui->labelB->setText(B);
    ui->labelW->setText(W);
}
