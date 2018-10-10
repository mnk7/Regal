#include "stapel.h"

Stapel::Stapel(QWidget *parent, std::vector<Buch> &d) : QWidget(parent)
{
    datenbank = d;

    buecher.resize(datenbank.size());
    for(const Buch &b: datenbank) {
        Buchanzeige *anzeige = new Buchanzeige(this, b);
        buecher.push_back(anzeige);
    }
}

Stapel::~Stapel() {

}
