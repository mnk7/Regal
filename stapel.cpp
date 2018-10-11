#include "stapel.h"

Stapel::Stapel(QWidget *parent, std::vector<Buch> &d) : QWidget(parent)
{
    datenbank = d;

    buecher.resize(datenbank.size());
    for(decltype (datenbank.size()) i = 0; i < datenbank.size(); ++i) {
        //the first button is related to the first book etc.
        buecher[i] = new StapelElement(this, datenbank[i]);
        buecher[i]->move(i * physicalDpiX(), i * physicalDpiY() / 2);
    }
}

Stapel::~Stapel() {

}
