#include <QTcpServer>
#include <QSslKey>
#include<QTcpSocket>
#include<QSslSocket>
class SslServer : public QTcpServer
{
	Q_OBJECT

public:
	SslServer(QObject *parent = 0);

private:

    QSslSocket *sslSocket;

private slots:
    void newConnection();
    void readData();
    void weAreEncrypted();
protected:
	void incomingConnection(qintptr socketDescriptor);
};

