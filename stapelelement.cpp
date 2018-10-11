#include "stapelelement.h"

StapelElement::StapelElement(QWidget *parent, Buch& b)
    : QWidget(parent), buch(b)
{
    this->setLayout(new QVBoxLayout());
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    anzeige = new Buchanzeige(this, b);
    anzeige->setVisible(false);

    QPixmap icon(":/Bilder/Buch");
    icon = icon.scaled(physicalDpiX(), physicalDpiY(),
                       Qt::KeepAspectRatio);

    QPushButton *knopf = new QPushButton(this);
    knopf->setFlat(true);
    knopf->setIcon(icon);
    knopf->setIconSize(QSize(icon.width(), icon.height()));
    knopf->setFixedSize(icon.width(), icon.height());
    knopf->connect(knopf, &QPushButton::clicked,
                     this, &StapelElement::showBook);
    this->layout()->addWidget(knopf);

    QLabel *beschriftung = new QLabel(this);
    beschriftung->setText(QString::fromStdString(b.getTitle()));
    beschriftung->setFixedWidth(knopf->width());
    this->layout()->addWidget(beschriftung);
}

void StapelElement::showBook() {
    anzeige->setGeometry(physicalDpiX() / 2, physicalDpiY() / 2,
                         parentWidget()->width() - physicalDpiX(),
                         parentWidget()->height() - physicalDpiY());
    anzeige->setVisible(true);
}

void StapelElement::resizeEvent(QResizeEvent *event) {



    QWidget::resizeEvent(event);
}


