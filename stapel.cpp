#include "stapel.h"

Stapel::Stapel(QWidget *parent, std::vector<Buch> &d) : QWidget(parent)
{
    datenbank = d;

    this->setLayout(new QGridLayout());

    buecher.resize(datenbank.size());
    for(decltype (datenbank.size()) i = 0; i < datenbank.size(); ++i) {
        //the first button is related to the first book etc.
        buecher.at(i) = new StapelElement(this, datenbank.at(i));
        this->layout()->addWidget(buecher.at(i));
    }
}

Stapel::~Stapel() {

}
