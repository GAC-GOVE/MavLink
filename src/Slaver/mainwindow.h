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


public slots:
    void sendMessage();

private:
    bool SendUdpMessge(QByteArray message);

private:
    Ui::MainWindow *ui;
    QUdpSocket *udp_server_ptr_;
    const int target_port_ = 8195;
};
#endif // MAINWINDOW_H
