#include "regal.h"

Regal::Regal(QWidget *parent)
    : QWidget(parent)
{
    path = QFileDialog::getOpenFileUrl(this);
}

Regal::~Regal()
{
}
