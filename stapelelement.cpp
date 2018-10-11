#include "stapelelement.h"

StapelElement::StapelElement(QWidget *parent, Buch &b)
    : QWidget(parent)
{
    buch = &b;
    this->setLayout(new QVBoxLayout());

    QPixmap icon(":/Bilder/Buch");
    icon = icon.scaled(physicalDpiY() / 2,physicalDpiY() / 2);

    knopf = new QPushButton(this);
    knopf->setFlat(true);
    knopf->setIcon(icon);
    knopf->setIconSize(QSize(icon.width(), icon.height()));
    knopf->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    knopf->connect(knopf, &QPushButton::clicked,
                     this, &StapelElement::clicked);
    this->layout()->addWidget(knopf);

    beschriftung = new QLabel(this);
    beschriftung->setText(QString::fromStdString(buch->getTitle()));
    beschriftung->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    this->layout()->addWidget(beschriftung);

    anzeige = new Buchanzeige(nullptr, *buch);
    anzeige->setVisible(false);
    connect(anzeige, &Buchanzeige::changed, this, &StapelElement::update);

    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}


void StapelElement::clicked() {
    anzeige->setVisible(true);
    anzeige->show();
}

void StapelElement::update() {
    beschriftung->setText(QString::fromStdString(buch->getTitle()));
}



