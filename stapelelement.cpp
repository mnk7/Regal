#include "stapelelement.h"

StapelElement::StapelElement(QWidget *parent, Buch& b)
    : QWidget(parent), buch(b)
{
    this->setLayout(new QVBoxLayout());
    klein = true;

    anzeige = new Buchanzeige(this, b);
    anzeige->setVisible(false);

    QPixmap icon(":/Bilder/Buch");
    icon = icon.scaled(physicalDpiX(),
                       Qt::KeepAspectRatio);

    knopf = new QPushButton(this);
    knopf->setFlat(true);
    knopf->setIcon(icon);
    knopf->setIconSize(QSize(icon.width(), icon.height()));
    knopf->setFixedSize(icon.width(), icon.height());
    knopf->connect(knopf, &QPushButton::clicked,
                     this, &StapelElement::clicked);
    this->layout()->addWidget(knopf);

    beschriftung = new QLabel(this);
    beschriftung->setText(QString::fromStdString(b.getTitle()));
    beschriftung->setFixedWidth(knopf->width());
    this->layout()->addWidget(beschriftung);

    this->setFixedSize(knopf->width(),
                       knopf->height() + beschriftung->height());

    standard.setWidth(this->width());
    standard.setHeight(this->height());
    this->setVisible(true);
}

void StapelElement::clicked() {
    if(!klein) {
        this->layout()->removeWidget(knopf);
        knopf->setIcon(QIcon());
        this->layout()->removeWidget(beschriftung);
        anzeige->setVisible(true);
        klein = false;

        this->resize(this->size());
    } else {
        anzeige->setVisible(false);
        knopf->setIcon(icon);
        beschriftung->setVisible(true);

        this->layout()->addWidget(knopf);
        this->layout()->addWidget(beschriftung);
        klein = true;

        this->resize(standard.width(),
                     standard.height());
    }
}

void StapelElement::resizeEvent(QResizeEvent *event) {
    if(!klein) {
        this->setGeometry(0, 0,
                          parentWidget()->width(), parentWidget()->height());
        knopf->setGeometry(0, 0,
                           this->width(), this->height());
        anzeige->setGeometry(physicalDpiX() / 2, physicalDpiY() / 2,
                             parentWidget()->width() - physicalDpiX(),
                             parentWidget()->height() - physicalDpiY());
        anzeige->raise();
    } else {
        knopf->setFixedSize(icon.width(), icon.height());
        beschriftung->setFixedWidth(knopf->width());
    }

    QWidget::resizeEvent(event);
}


