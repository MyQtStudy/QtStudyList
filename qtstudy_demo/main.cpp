#include "mainwindow.h"
// qt中类名和头文件名一样,而且没有.h
#include <QApplication>
#include <QLabel>

// 应用程序入口
int main(int argc, char *argv[])
{
    // 应用程序类,每一个QT程序中有且只有一个
    QApplication a(argc, argv);
    // 创建窗口类, 创建出来后默认不显示
    MainWindow w;
    // 显示窗口
    w.show();

    //a 就是应用程序类
    return a.exec();
}
