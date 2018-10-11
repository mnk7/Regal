#include "regal.h"

Regal::Regal(QWidget *parent)
    : QWidget(parent)
{
    //get screen size
    QSize size = qApp->screens()[0]->size();
    this->setContentsMargins(0, physicalDpiY() / 1000, 0, 0);
    this->setGeometry(static_cast<int>(size.width() * 0.25),
                      static_cast<int>(size.height() * 0.25),
                      60 * size.width() / physicalDpiX(),
                      50 * size.height() / physicalDpiY());

    menu = new QWidget(this);
    menu->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    menu->setLayout(new QHBoxLayout());

    QPushButton *load = new QPushButton(this);
    load->setText("Lade Datenbank");
    menu->layout()->addWidget(load);
    connect(load, &QPushButton::clicked, this, &Regal::getDatabase);

    QPushButton *save = new QPushButton(this);
    save->setText("Speichere Datenbank");
    menu->layout()->addWidget(save);
    connect(save, &QPushButton::clicked, this, &Regal::saveDatabase);


    hauptstapel = new Stapel(this, datenbank);
    hauptstapel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

Regal::~Regal()
{
}

void Regal::getDatabase() {
    path = QFileDialog::getOpenFileName(this, "Lade Datenbank", ".");
    if(path.size() > 0) {
        datenbank = loadData(path.toStdString());
        hauptstapel = new Stapel(this, datenbank);
    } else {
        exit(2);
    }
}

void Regal::saveDatabase() {
    saveData(path.toStdString(), datenbank);
}

void Regal::resizeEvent(QResizeEvent* event) {
    menu->setGeometry(0, 0, this->width(), physicalDpiY() / 3);
    hauptstapel->setGeometry(0, menu->height(),
                             this->width(), this->height() - menu->height());

    QWidget::resizeEvent(event);
}
