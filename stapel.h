#ifndef STAPEL_H
#define STAPEL_H

#include <QWidget>
#include <QPushButton>

#include "buch.h"
#include "buchanzeige.h"

class Stapel : public QWidget
{
    Q_OBJECT
public:
    explicit Stapel(QWidget *parent, std::vector<Buch> &d);
    ~Stapel();

signals:

private:
    std::vector<Buch> datenbank;
    std::vector<QPushButton*> buecher;
};

#endif // STAPEL_H
