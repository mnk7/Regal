#include "regal.h"

#include <iostream>

Regal::Regal(QWidget *parent)
    : QWidget(parent)
{
    path = QFileDialog::getOpenFileName(this, "Öffne Datenbank", "/User/mnk7/Documents/workspaces/Qt-Kurs/Regal");
    if(path.size() > 0) {
        datenbank = loadData(path.toStdString());
    } else {
        exit(2);
    }
}

Regal::~Regal()
{
}
