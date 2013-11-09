#ifndef APP_H
#define APP_H

#include <QObject>

class ZmqSocket;

class LxMQApp : public QObject
{
	Q_OBJECT
public:
    LxMQApp();

protected slots:
    void start();
    void squawk();
    void heard();
    void ndy();

private:
    ZmqSocket *m_pSocket;
    QByteArray m_byteKey;
};

#endif // APP_H
