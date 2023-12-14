#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initUdpSocket(int port);
    void insertPlainText(const QString &text);

private slots:
    void processPendingDatagrams();

private:
    Ui::MainWindow *ui;
    QUdpSocket *udp_receiver_ptr_;
};
#endif // MAINWINDOW_H
