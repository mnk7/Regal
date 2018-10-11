#include "stapel.h"
#include <iostream>

Stapel::Stapel(QWidget *parent, std::vector<Buch> &datenbank) : QWidget(parent)
{
    this->setLayout(new FlowLayout());

    buecher.resize(datenbank.size());
    for(decltype (datenbank.size()) i = 0; i < datenbank.size(); ++i) {
        //the first button is related to the first book etc.
        buecher[i] = new StapelElement(this, datenbank[i]);
        buecher[i]->setGeometry(0, 0,
                                buecher[i]->width(), buecher[i]->height());
        this->layout()->addWidget(buecher[i]);
    }
}

Stapel::~Stapel() {
}
