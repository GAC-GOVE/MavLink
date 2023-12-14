#include "mainwindow.h"
#include "MavlinkResolver.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      udp_receiver_ptr_(new QUdpSocket(this))
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    insertPlainText("---===Mavlink2.0 Test===---\n");

    initUdpSocket(8195);
    connect(udp_receiver_ptr_, &QUdpSocket::readyRead, this,
            &MainWindow::processPendingDatagrams);
}

void MainWindow::insertPlainText(const QString &text) {
    ui->textEdit->moveCursor(QTextCursor::End);
    ui->textEdit->insertPlainText(text);
    ui->textEdit->insertPlainText("\n");
}

MainWindow::~MainWindow()
{
    if (udp_receiver_ptr_ != nullptr){
        delete udp_receiver_ptr_;
    }
    delete ui; 
}

void MainWindow::initUdpSocket(int port) {
    if (!udp_receiver_ptr_->bind(port)) {
        insertPlainText(udp_receiver_ptr_->errorString());
    }
}

void MainWindow::processPendingDatagrams() {
    while (udp_receiver_ptr_->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udp_receiver_ptr_->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;
        udp_receiver_ptr_->readDatagram(datagram.data(), datagram.size(),
                                        &sender, &senderPort);

        QString raw_data = "Raw Data : " + datagram;
        insertPlainText(raw_data);

        MotorParam motor_param;
        if (MavlinkResolver::GetMortorParamMessage(datagram, motor_param)) {
            QString decode_data =
                "Decode Data : ID:" + QString::number(motor_param.ID) +
                ", Speed:" + QString::number(motor_param.Speed);
            insertPlainText(decode_data);
        }
    }
}
