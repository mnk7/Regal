#ifndef REGAL_H
#define REGAL_H

#include <QWidget>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>
#include <QScreen>

#include <vector>

#include "buch.h"
#include "stapel.h"
#include "helfer.h"

class Regal : public QWidget
{
    Q_OBJECT

public:
    Regal(QWidget *parent = nullptr);
    ~Regal();

private:
    std::vector<Buch> datenbank;
    QString path;

    void getDatabase();
    void saveDatabase();

};

#endif // REGAL_H
