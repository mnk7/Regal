#include "regal.h"

#include <iostream>

Regal::Regal(QWidget *parent)
    : QWidget(parent)
{
    path = QFileDialog::getOpenFileName(this, "Öffne Datenbank", "/User/mnk7/Documents/workspaces/Qt-Kurs/Regal");
    datenbank = loadData(path.toStdString());

    for(const Buch& b: datenbank) {
        printBuch(std::cout, b);
    }
}

Regal::~Regal()
{
}
