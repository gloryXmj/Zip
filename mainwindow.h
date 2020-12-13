#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include  "Zlib/KwZip.h"

#include <QFutureWatcher>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static void ZipThread(MainWindow *pThis);
public slots:
    void OnProcessValue(int value);
private:
    Ui::MainWindow *ui;
    ::QFutureWatcher<void> m_ZipWatch;
};
#endif // MAINWINDOW_H
