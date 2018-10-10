#ifndef STAPEL_H
#define STAPEL_H

#include <QWidget>

#include "buch.h"
#include "buchanzeige.h"

class Stapel : public QWidget
{
    Q_OBJECT
public:
    explicit Stapel(QWidget *parent, std::vector<Buch> &d);
    ~Stapel();

signals:

public slots:

private:
    std::vector<Buch> datenbank;
    std::vector<Buchanzeige*> buecher;
};

#endif // STAPEL_H
