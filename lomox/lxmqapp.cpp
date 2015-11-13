#include "lxmqapp.h"

#include <QTimer>
#include <QStringList>
#include <QCoreApplication>
#include <QtDebug>
#include <QDateTime>

#include "ZmqSocket.h"
#include "ZmqMessage.h"

LxMQApp::LxMQApp()
{
	QTimer::singleShot(0, this, SLOT(start()));
}

void LxMQApp::start()
{
	QStringList args = QCoreApplication::arguments();
	if(args.size() < 3) 
	{
		qWarning() << "Usage: " << args.front() << " client|server <key>";
		QCoreApplication::exit();
		return;
	}

	m_byteKey = args.at(2).toLocal8Bit();

	QTimer *ndyt = new QTimer(this);
	connect(ndyt, SIGNAL(timeout()), this, SLOT(ndy()));
	ndyt->setInterval(5000);
	ndyt->start();

	if(args.at(1) == "client") 
	{
		m_pSocket = new ZmqSocket(ZMQ_SUB, this);
		connect(m_pSocket, SIGNAL(readyRead()), this, SLOT(heard()));
		m_pSocket->subscribe(m_byteKey);
		m_pSocket->connectTo("tcp://127.0.0.1:3782");
	}

	if(args.at(1) == "server") 
	{
		m_pSocket = new ZmqSocket(ZMQ_PUB, this);
		m_pSocket->bind("tcp://127.0.0.1:3782");
		QTimer *t = new QTimer(this);
		connect(t, SIGNAL(timeout()), this, SLOT(squawk()));
		t->setInterval(1000);
		t->start();
	}
}

void LxMQApp::squawk()
{
	QString s =  QDateTime::currentDateTime().toString();
	qDebug() << "Squawking " << s;
	m_pSocket->send(m_byteKey + s.toLocal8Bit());
}

void LxMQApp::heard()
{
	QList<QByteArray> r = m_pSocket->recv();
	for(QList<QByteArray>::const_iterator i=r.constBegin(); i!=r.constEnd(); ++i)
	{
		qDebug() << "Received " << *i;
	}
}

void LxMQApp::ndy()
{
  qDebug() << "Not dead yet";
}
