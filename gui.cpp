#include "gui.h"
#include <QDebug>

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    connect(&m_scanner, &HttpClient::scanFinished, this, &Gui::showResult);
}

void Gui::on_goButton_clicked()
{
    QByteArray host = hostEntry->text().toUtf8();
    m_scanner.readyRead();
}

void Gui::showResult(QByteArray host, bool status)
{
    qDebug() << host << status;
    QString msg = (status == true) ? "open" : "closed";
    QString result = QString::number(status) + " -> " + msg;
    resultBrowser->append(result);
}
