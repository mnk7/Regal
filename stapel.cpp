#include "stapel.h"
#include <iostream>

Stapel::Stapel(QWidget *parent, std::vector<Buch> &d) : QWidget(parent)
{
    datenbank = &d;

    this->setLayout(new FlowLayout());

    buecher.resize(datenbank->size());
    for(decltype (datenbank->size()) i = 0; i < datenbank->size(); ++i) {
        //the first button is related to the first book etc.
        buecher[i] = new StapelElement(this, datenbank->at(i));
        this->layout()->addWidget(buecher[i]);
    }

    this->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(this, &Stapel::customContextMenuRequested,
            this, &Stapel::showContextMenu);
}

Stapel::~Stapel() {
}

void Stapel::showContextMenu(const QPoint &p) {
    QMenu contextMenu(tr("Context menu"), this);

    QAction action1("Neues Buch", this);
    connect(&action1, &QAction::triggered, this, &Stapel::neuesBuch);
    contextMenu.addAction(&action1);

    contextMenu.exec(mapToGlobal(p));
}

void Stapel::neuesBuch() {
    bool ok;
    QString text = QInputDialog::getText(this, "Kürzel für Buch angeben",
                                         "Kürzel für Buch:",
                                         QLineEdit::Normal,
                                         "Goethe-Faust", &ok);

    if (ok && !text.isEmpty()) {
        Buch b(text.toStdString());
        datenbank->push_back(b);
        buecher.push_back(new StapelElement(this, b));
        this->layout()->addWidget(buecher.at(buecher.size() - 1));
    }
}
