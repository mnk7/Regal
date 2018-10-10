#include "regal.h"

#include <iostream>

Regal::Regal(QWidget *parent)
    : QWidget(parent)
{
    path = QFileDialog::getOpenFileName(this, "Öffne Datenbank", "~");
    datenbank = loadData(path.toStdString());
    std::cout << datenbank.size() << std::endl;
}

Regal::~Regal()
{
}
