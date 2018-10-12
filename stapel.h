#ifndef STAPEL_H
#define STAPEL_H

#include <QWidget>
#include <QPushButton>
#include <flowlayout.h>

#include "buch.h"
#include "buchanzeige.h"
#include "stapelelement.h"

class Stapel : public QWidget
{
    Q_OBJECT
public:
    explicit Stapel(QWidget *parent, std::vector<Buch> &d);
    ~Stapel();

private:
    std::vector<Buch> *datenbank;
    std::vector<StapelElement*> buecher;
};

#endif // STAPEL_H
