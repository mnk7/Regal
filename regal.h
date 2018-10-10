#ifndef REGAL_H
#define REGAL_H

#include <QWidget>
#include <QFileDialog>

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
    QString path;

};

#endif // REGAL_H
