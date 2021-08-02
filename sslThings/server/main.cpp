#include <QCoreApplication>
#include "sslserver.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	SslServer server;

	return app.exec();
}
