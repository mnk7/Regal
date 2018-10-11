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
    Buchanzeige *anzeige;
    QPushButton *knopf;
    QLabel *beschriftung;
    QSize standard;
    QPixmap icon;

    void clicked();
};

#endif // STAPELELEMENT_H
