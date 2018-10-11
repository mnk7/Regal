#include "regal.h"

Regal::Regal(QWidget *parent)
    : QWidget(parent)
{
    //get screen size
    QSize size = qApp->screens()[0]->size();
    this->setLayout(new QVBoxLayout());
    this->setGeometry(static_cast<int>(size.width() * 0.25),
                      static_cast<int>(size.height() * 0.25),
                      60 * size.width() / physicalDpiX(),
                      50 * size.height() / physicalDpiY());

    QWidget *menu = new QWidget(this);
    menu->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    this->layout()->addWidget(menu);
    menu->setLayout(new QHBoxLayout());

    QPushButton *load = new QPushButton(this);
    load->setText("Lade Datenbank");
    menu->layout()->addWidget(load);
    connect(load, &QPushButton::clicked, this, &Regal::getDatabase);

    QPushButton *save = new QPushButton(this);
    save->setText("Speichere Datenbank");
    menu->layout()->addWidget(save);
    connect(save, &QPushButton::clicked, this, &Regal::saveDatabase);


    Stapel *hauptstapel = new Stapel(this, datenbank);
    hauptstapel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->layout()->addWidget(hauptstapel);
}

Regal::~Regal()
{
}

void Regal::getDatabase() {
    path = QFileDialog::getOpenFileName(this, "Lade Datenbank", ".");
    if(path.size() > 0) {
        datenbank = loadData(path.toStdString());
    } else {
        exit(2);
    }
}

void Regal::saveDatabase() {
    saveData(path.toStdString(), datenbank);
}
