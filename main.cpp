#include "mainwindow.h"

#include <QApplication>

#include <iostream>
#include <memory>
#include <functional>

using namespace std::placeholders;
using namespace std;
void fun1(int arg1,int arg2,int arg3)
{
    std::cout << arg1<<arg2<<arg3;
}

int main(int argc, char *argv[])
{
    //_1表示这个位置是新的可调用对象的第一个参数的位置
    //_2表示这个位置是新的可调用对象的第二个参数的位置
    auto f1 =  bind(fun1,_1,10,_2);
    f1(20,0);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
