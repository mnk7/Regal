#include "stapelelement.h"

StapelElement::StapelElement(QWidget *parent, Buch &buch)
    : QWidget(parent)
{
    this->setLayout(new QVBoxLayout());

    QPixmap icon(":/Bilder/Buch");
    icon = icon.scaled(physicalDpiY(),
                       Qt::KeepAspectRatio);

    knopf = new QPushButton(this);
    knopf->setFlat(true);
    knopf->setIcon(icon);
    knopf->setIconSize(QSize(icon.width(), icon.height()));
    knopf->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    knopf->connect(knopf, &QPushButton::clicked,
                     this, &StapelElement::clicked);
    this->layout()->addWidget(knopf);

    beschriftung = new QLabel(this);
    beschriftung->setText(QString::fromStdString(buch.getTitle()));
    beschriftung->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    this->layout()->addWidget(beschriftung);

    anzeige = new Buchanzeige(nullptr, buch);
    anzeige->setVisible(false);

    standard.setWidth(this->width());
    standard.setHeight(this->height());
}


void StapelElement::clicked() {
    anzeige->setVisible(true);
    anzeige->show();
}



