#include "stapel.h"

Stapel::Stapel(QWidget *parent, std::vector<Buch> &d) : QWidget(parent)
{
    datenbank = d;

    QPixmap icon(":/Bilder/Buch");
    icon = icon.scaled(physicalDpiX(), physicalDpiY(), Qt::KeepAspectRatio);

    buecher.resize(datenbank.size());
    for(Buch &b: datenbank) {
        //the first button is related to the first book etc.
        QPushButton *anzeige = new QPushButton(this);
        anzeige->setFlat(true);
        anzeige->setIcon(icon);
        anzeige->setIconSize(QSize(icon.width(), icon.height()));
        anzeige->setFixedSize(icon.width(), icon.height());
        buecher.push_back(anzeige);
    }
}

Stapel::~Stapel() {

}
