#ifndef STAPELELEMENT_H
#define STAPELELEMENT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMenu>

#include "buch.h"
#include "buchanzeige.h"

class StapelElement : public QWidget
{
    Q_OBJECT
public:
    explicit StapelElement(QWidget *parent, Buch &b);

private:
    Buch *buch;

    Buchanzeige *anzeige;
    QPushButton *knopf;
    QLabel *beschriftung;
    QPixmap icon;

    void clicked();
    void update();
    void showContextMenu(const QPoint &);
    void entferne();
    void setzeTitel();
    void setzeIcon();
};

#endif // STAPELELEMENT_H
