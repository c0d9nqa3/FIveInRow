#include "mainwindow.h"
#include <QApplication>
#include <begin.h>
#include <QDebug>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Begin w;
	w.show();

	return a.exec();
}
