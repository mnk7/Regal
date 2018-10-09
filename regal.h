#ifndef REGAL_H
#define REGAL_H

#include <QWidget>

class Regal : public QWidget
{
    Q_OBJECT

public:
    Regal(QWidget *parent = nullptr);
    ~Regal();
};

#endif // REGAL_H
