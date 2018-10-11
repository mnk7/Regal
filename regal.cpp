﻿#include "regal.h"

Regal::Regal(QWidget *parent)
    : QWidget(parent)
{
    //get screen size
    QSize size = qApp->screens()[0]->size();
    this->setGeometry(static_cast<int>(size.width() * 0.25),
                      static_cast<int>(size.height() * 0.25),
                      60 * size.width() / physicalDpiX(),
                      50 * size.height() / physicalDpiY());

    this->setLayout(new QVBoxLayout());
    this->layout()->setContentsMargins(0, 0, 0, 0);

    menu = new QWidget(this);
    menu->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    menu->setLayout(new QHBoxLayout());
    menu->layout()->setContentsMargins(0, 0, 0, 0);
    menu->layout()->setAlignment(Qt::AlignCenter);

    QPushButton *load = new QPushButton(this);
    load->setText("Laden");
    load->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    load->setFixedWidth(physicalDpiX());
    menu->layout()->addWidget(load);
    connect(load, &QPushButton::clicked, this, &Regal::getDatabase);

    QPushButton *save = new QPushButton(this);
    save->setText("Speichern");
    save->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    save->setFixedWidth(physicalDpiX());
    menu->layout()->addWidget(save);
    connect(save, &QPushButton::clicked, this, &Regal::saveDatabase);

    this->layout()->addWidget(menu);

    hauptstapel = new Stapel(this, datenbank);
    hauptstapel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    scroller = new QScrollArea();
    scroller->setWidgetResizable(true);
    scroller->setWidget(hauptstapel);
    this->layout()->addWidget(scroller);

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
        hauptstapel->setSizePolicy(QSizePolicy::Expanding,
                                   QSizePolicy::Expanding);
        scroller->setWidget(hauptstapel);
        this->layout()->addWidget(scroller);
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
