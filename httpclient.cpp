#include "httpclient.h"
#include <QDebug>
#include <QCoreApplication>

/*
HttpClient::HttpClient(QObject *parent) : QObject(parent)
{

}
*/
HttpClient::HttpClient(int argc, char* argv[], QObject *parent) : QObject(parent)
{
    m_hostname = argv[1];
    unsigned short port = 80;
    m_socket = new QTcpSocket(this);
    bool status = false;

    // Signal ->  Slot-Verbindung
    connect(m_socket, &QTcpSocket::connected, this, &HttpClient::connected);
    connect(m_socket, &QTcpSocket::readyRead, this, &HttpClient::readyRead);

    m_socket->connectToHost(m_hostname, port); // TCP Connect
    if (!m_socket->waitForConnected(5000)) {
        status = true;
        qDebug() << "Connect failed!";
        exit(1);
    }

    emit scanFinished(m_hostname, status);
}

void HttpClient::connected()
{
    // normgerechter HTTP Request zum Server
    m_socket->write("GET / HTTP/1.1\r\nHost:" + m_hostname + "\r\n\r\n");
}

void HttpClient::readyRead()
{
    // HTTP-Antwort vom Server
    qDebug() << m_socket->readAll();
    m_socket->disconnectFromHost();
    QCoreApplication::quit();
}
