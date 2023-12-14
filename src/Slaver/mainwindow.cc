#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "MavlinkWrapper.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      udp_server_ptr_(new QUdpSocket(this))
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_Send, &QPushButton::clicked, this,
            &MainWindow::sendMessage);
}

void MainWindow::sendMessage() {
    bool id_ok = false,speed_ok = false;
    int id = ui->lineEdit_ID->text().toInt(&id_ok);
    int speed = ui->lineEdit_Speed->text().toInt(&speed_ok);

    if (id_ok && speed_ok){
        auto message = MavlinkWrapper::EncodeMotorParamMessage(id, speed);
        SendUdpMessge(message);
    }
}

bool MainWindow::SendUdpMessge(QByteArray message) {
    qint64 bytesSent = udp_server_ptr_->writeDatagram(
        message, QHostAddress::LocalHost,
        target_port_);  // Change the destination address and port as needed

    if (bytesSent == -1) {
        qDebug() << "Error sending datagram: "
                 << udp_server_ptr_->errorString();
        return false;
    } else {
        return true;
    }
}

MainWindow::~MainWindow()
{
    if (udp_server_ptr_ != nullptr) {
        delete udp_server_ptr_;
        udp_server_ptr_ = nullptr;
    }
    delete ui;
}
