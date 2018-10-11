#ifndef STAPELELEMENT_H
#define STAPELELEMENT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

#include "buch.h"
#include "buchanzeige.h"

class StapelElement : public QWidget
{
    Q_OBJECT
public:
    explicit StapelElement(QWidget *parent, Buch &b);

signals:

private:
    Buch *buch;

    Buchanzeige *anzeige;
    QPushButton *knopf;
    QLabel *beschriftung;
    QPixmap icon;

    void clicked();
    void update();
};

#endif // STAPELELEMENT_H
