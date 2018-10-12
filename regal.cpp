#include "regal.h"

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
    menu->setFixedHeight(physicalDpiY() / 4);

    QPushButton *neu = new QPushButton(this);
    neu->setText("Neues Regal");
    neu->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    neu->setFixedWidth(physicalDpiX());
    menu->layout()->addWidget(neu);
    connect(neu, &QPushButton::clicked, this, &Regal::newDatabase);

    QPushButton *load = new QPushButton(this);
    load->setText("Laden");
    load->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    load->setFixedWidth(physicalDpiX());
    menu->layout()->addWidget(load);
    connect(load, &QPushButton::clicked, this, &Regal::getDatabase);

    menu->layout()->addItem(new QSpacerItem(0, neu->height(),
                                            QSizePolicy::Expanding,
                                            QSizePolicy::Minimum));

    QPushButton *save = new QPushButton(this);
    save->setText("Speichern");
    save->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    save->setFixedWidth(physicalDpiX());
    menu->layout()->addWidget(save);
    connect(save, &QPushButton::clicked, this, &Regal::saveDatabase);

    this->layout()->addWidget(menu);

    hauptstapel = new Stapel(this, &datenbank);
    hauptstapel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    scroller = new QScrollArea();
    scroller->setWidgetResizable(true);
    scroller->setFrameShape(QFrame::NoFrame);
    scroller->setWidget(hauptstapel);
    this->layout()->addWidget(scroller);

    this->resize(this->width(), this->height());
}

Regal::~Regal()
{
}

void Regal::newDatabase() {
    path = QFileDialog::getSaveFileName(this, "Neue Datenbank",
                                        QDir::home().absolutePath());
}

void Regal::getDatabase() {
    path = QFileDialog::getOpenFileName(this, "Lade Datenbank",
                                        QDir::home().absolutePath());
    if(path.size() > 0) {
        datenbank = loadData(path.toStdString());
        this->layout()->removeWidget(hauptstapel);
        delete hauptstapel;
        hauptstapel = new Stapel(this, &datenbank);
        hauptstapel->setSizePolicy(QSizePolicy::Expanding,
                                   QSizePolicy::Expanding);
        scroller->setWidget(hauptstapel);
        this->layout()->addWidget(scroller);
    }
}

void Regal::saveDatabase() {
    if(path.size() < 1) {
        path = QFileDialog::getSaveFileName(this, "Neue Datenbank",
                                            QDir::home().absolutePath());
    }
    saveData(path.toStdString(), datenbank);
}
