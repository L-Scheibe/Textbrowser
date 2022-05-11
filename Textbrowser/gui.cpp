#include "gui.h"
#include <QDebug>

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    connect(&m_scanner, &HttpClient::sendData, this, &Gui::showResult);
}

void Gui::on_goButton_clicked()
{
    QString host = hostEntry->text();
    m_scanner.getHttp(host);
}

void Gui::showResult(QString& httpprintback)
{
    resultBrowser->append(httpprintback);
}
