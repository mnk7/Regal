#include "stapelelement.h"

StapelElement::StapelElement(QWidget *parent, Buch &b)
    : QWidget(parent)
{
    buch = &b;
    this->setLayout(new QVBoxLayout());

    knopf = new QPushButton(this);
    knopf->setFlat(true);
    setzeIcon();
    knopf->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    knopf->connect(knopf, &QPushButton::clicked,
                     this, &StapelElement::clicked);
    this->layout()->addWidget(knopf);

    beschriftung = new QLabel(this);
    setzeTitel();
    beschriftung->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    beschriftung->setAlignment(Qt::AlignCenter);
    this->layout()->addWidget(beschriftung);

    anzeige = new Buchanzeige(nullptr, *buch);
    anzeige->setVisible(false);
    connect(anzeige, &Buchanzeige::changed, this, &StapelElement::update);
    connect(anzeige, &Buchanzeige::iconChanged,
            this, &StapelElement::setzeIcon);

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

void StapelElement::setzeIcon() {
    QPixmap *icon;
    if(buch->getPath().size() > 0){
        icon = new QPixmap(QString::fromStdString(buch->getPath()));
    } else {
        icon = new QPixmap(":/Bilder/Buch");
    }

    *icon = icon->scaled(static_cast<int>(physicalDpiX() * 0.75),
                         static_cast<int>(physicalDpiY() * 0.75),
                         Qt::KeepAspectRatio);

    knopf->setIcon(*icon);
    knopf->setIconSize(QSize(icon->width(), icon->height()));
}



