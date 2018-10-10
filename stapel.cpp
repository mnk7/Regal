#include "stapel.h"

Stapel::Stapel(QWidget *parent, std::vector<Buch> &d) : QWidget(parent)
{
    datenbank = d;

    buecher.resize(datenbank.size());
    for(Buch &b: datenbank) {
        QPushButton *anzeige = new QPushButton(this);
        buecher.push_back(anzeige);
    }
}

Stapel::~Stapel() {

}
