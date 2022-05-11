#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>

const int PORT = 80;
const int TIMEOUT = 5000;

class HttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = nullptr);
    void getHttp(QString& host);
    void connected();
    void readyRead();

signals:
    void sendData(QString& nachricht);

public slots:


private:
    QTcpSocket *m_socket;
    QByteArray m_hostname;
    QString m_signal;
};

#endif // HTTPCLIENT_H
