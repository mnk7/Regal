#ifndef REGAL_H
#define REGAL_H

#include <QWidget>

#include <vector>

#include "buch.h"

class Regal : public QWidget
{
    Q_OBJECT

public:
    Regal(QWidget *parent = nullptr);
    ~Regal();

private:
    std::vector<Buch> datenbank;

};

#endif // REGAL_H
