#ifndef BUCHANZEIGE_H
#define BUCHANZEIGE_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <buch.h>
#include <QPushButton>
#include <QCalendarWidget>
#include <QDate>

class Buchanzeige : public QWidget
{
    Q_OBJECT
public:
    explicit Buchanzeige(QWidget *parent, Buch& book);
    ~Buchanzeige();

signals:

private:
    void openCalendar();
    void changeDate(const QDate&);
};

#endif // BUCHANZEIGE_H
