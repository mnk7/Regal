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
#include <QDateEdit>
#include <QDate>
#include <QtGlobal>

class Buchanzeige : public QWidget
{
    Q_OBJECT
public:
    explicit Buchanzeige(QWidget *parent, Buch& b);
    ~Buchanzeige()=default;

signals:
    void changeSignal(const QString& m);

private:
    void changeNoteText();
    QGridLayout *layout;
    QTextEdit *notesIn;
    QDateEdit *startCalendar;
    QDateEdit *endCalendar;
};

#endif // BUCHANZEIGE_H
