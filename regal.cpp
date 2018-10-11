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

    this->setLayout(new QVBoxLayout());

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

    this->layout()->addWidget(menu);

    hauptstapel = new Stapel(this, datenbank);
    hauptstapel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->layout()->addWidget(hauptstapel);

    this->resize(this->width(), this->height());
}

Regal::~Regal()
{
}

void Regal::getDatabase() {
    path = QFileDialog::getOpenFileName(this, "Lade Datenbank", ".");
    if(path.size() > 0) {
        datenbank = loadData(path.toStdString());
        this->layout()->removeWidget(hauptstapel);
        delete hauptstapel;
        hauptstapel = new Stapel(this, datenbank);
        this->layout()->addWidget(hauptstapel);
        hauptstapel->setSizePolicy(QSizePolicy::Expanding,
                                   QSizePolicy::Expanding);
    } else {
        if(datenbank.size() == 0) {
            exit(2);
        }
    }
}

void Regal::saveDatabase() {
    if(path.size() != 0) {
        saveData(path.toStdString(), datenbank);
    }
}
