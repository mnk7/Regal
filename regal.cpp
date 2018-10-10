#include "regal.h"

Regal::Regal(QWidget *parent)
    : QWidget(parent)
{
    path = QFileDialog::getOpenFileName(this, "Öffne Datenbank", ".");
    if(path.size() > 0) {
        datenbank = loadData(path.toStdString());
    } else {
        exit(2);
    }

    //get screen size
    QSize size = qApp->screens()[0]->size();

    Stapel *hauptstapel = new Stapel(this, datenbank);
    this->setLayout(new QVBoxLayout());
    this->layout()->addWidget(hauptstapel);

    this->setGeometry(static_cast<int>(size.width() * 0.25),
                      static_cast<int>(size.height() * 0.25),
                      60 * size.width() / physicalDpiX(),
                      50 * size.height() / physicalDpiY());
}

Regal::~Regal()
{
}
