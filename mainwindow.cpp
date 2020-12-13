#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <functional>

#include <QDebug>
#include <QtConcurrent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_ZipWatch.progressRangeChanged(0,100);
    connect(&m_ZipWatch,SIGNAL(progressValueChanged(int)),this,SLOT(OnProcessValue(int)));
    QFuture<void> future = QtConcurrent::run(&MainWindow::ZipThread,this);
    m_ZipWatch.setFuture(future);


    //bool res = KwZip::UnzipFile("C:\\Users\\xmj\\Desktop\\2048.zip","C:\\Users\\xmj\\Desktop\\2048bak");
    //qDebug() << res;
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ZipThread(MainWindow *pThis)
{
    for (int  i = 0; i <= 10000  ; i++ ) {
        //进度修改的信号需要自己发送
        pThis->m_ZipWatch.progressValueChanged(i/100);
    }
    //KwZip::ZipFile("C:/Users/xmj/Downloads/Video","C:/Users/xmj/Desktop/Video.zip","xmj");
}

void MainWindow::OnProcessValue(int value)
{
    qDebug() << value;
}

