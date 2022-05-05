#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>

class HttpClient : public QObject
{
    Q_OBJECT
public:
    //explicit HttpClient(QObject *parent = nullptr);
    explicit HttpClient(int argc, char* argv[], QObject *parent = nullptr);

signals:
    void scanFinished(QByteArray host, bool status);

public slots:
    void connected();
    void readyRead();

private:
    QTcpSocket *m_socket;
    QByteArray m_hostname;
};

#endif // HTTPCLIENT_H
