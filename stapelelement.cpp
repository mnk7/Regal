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
    setzeTitel();
    beschriftung->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    this->layout()->addWidget(beschriftung);

    anzeige = new Buchanzeige(nullptr, *buch);
    anzeige->setVisible(false);
    connect(anzeige, &Buchanzeige::changed, this, &StapelElement::update);

    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    this->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(this, &StapelElement::customContextMenuRequested,
            this, &StapelElement::showContextMenu);
}


void StapelElement::clicked() {
    anzeige->setVisible(true);
    anzeige->show();
}

void StapelElement::update() {
    setzeTitel();
}

void StapelElement::showContextMenu(const QPoint &p) {
    QMenu contextMenu(tr("Context menu"), this);

    QAction action1("Entferne Buch", this);
    connect(&action1, &QAction::triggered, this, &StapelElement::entferne);
    contextMenu.addAction(&action1);

    contextMenu.exec(mapToGlobal(p));
}

void StapelElement::entferne() {
    buch->setEntfernt();
    this->setVisible(false);
}

void StapelElement::setzeTitel() {
    QString titel = QString::fromStdString(buch->getTitle());
    if(titel.size() > 15) {
        titel.resize(15);
        titel.replace(12, 3, "...");
    }

    beschriftung->setText(titel);
}



