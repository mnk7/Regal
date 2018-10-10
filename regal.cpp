#include "regal.h"

Regal::Regal(QWidget *parent)
    : QWidget(parent)
{
    path = QFileDialog::getOpenFileName(this, "Öffne Datenbank", "/User/mnk7/Documents/workspaces/Qt-Kurs/Regal");
    if(path.size() > 0) {
        datenbank = loadData(path.toStdString());
    } else {
        exit(2);
    }

    Stapel *hauptstapel = new Stapel(this, datenbank);
    this->setLayout(new QVBoxLayout());
    this->layout()->addWidget(hauptstapel);
}

Regal::~Regal()
{
}
