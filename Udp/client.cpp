#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

    ui->sIp->setText("127.0.0.1");
    ui->sPort->setText("8888");
    ui->cPort->setText("9999");

    udp2 = new QUdpSocket(this);

    // if want receive must bind port
    //udp2->bind(ui->sPort->text().toInt());

    udp2->bind(QHostAddress::AnyIPv4,ui->sPort->text().toInt());

    // 加入到组播的组中
    udp2->joinMulticastGroup(QHostAddress("224.0.0.10"));

    // send msg
    connect(ui->send,&QPushButton::clicked,this,[=](){
        udp2->writeDatagram(ui->msg->toPlainText().toUtf8(),QHostAddress(ui->sIp->text()),ui->cPort->text().toInt());
        ui->record->append("Me say:"+ui->msg->toPlainText());
    });

    connect(udp2,&QUdpSocket::readyRead,this,[=](){
        qint64 size = udp2->pendingDatagramSize();
        QByteArray array(size,0);
        udp2->readDatagram(array.data(),size);
        ui->record->append(array);
        ui->msg->clear();
    });
}

Client::~Client()
{
    delete ui;
}
