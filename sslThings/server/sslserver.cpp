#include "sslserver.h"
SslServer::SslServer(QObject *parent) : QTcpServer(parent)
{
    if (!listen(QHostAddress::Any, 12345)) {
        qDebug()<<"error to listen is "<<errorString();
    }else{
        qDebug()<<"We are listening";
    }
}
void SslServer::incomingConnection(qintptr socketDescriptor)
{
    sslSocket = new QSslSocket(this);
    connect(sslSocket,SIGNAL(encrypted()),this,SLOT(weAreEncrypted()));
    connect(this,SIGNAL(newConnection()),this,SLOT(newConnection()));
    sslSocket->setSocketDescriptor(socketDescriptor);


    sslSocket->setPrivateKey("/media/psf/Home/Cer/private.key",QSsl::KeyAlgorithm::Rsa);
    sslSocket->setLocalCertificate("/media/psf/Home/Cer/certificate.pem",QSsl::Pem);




    sslSocket->setPeerVerifyMode(QSslSocket::VerifyNone);
	sslSocket->startServerEncryption();
}
void SslServer::readData(){

    qDebug()<<"Client said that :"<<sslSocket->readAll();
}
void SslServer::weAreEncrypted(){
    qDebug()<<"We are encrypted";
}

void SslServer::newConnection(){
connect(sslSocket,SIGNAL(readyRead()),this,SLOT(readData()));
}
