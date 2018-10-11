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

private:
    Buch *b;
    QGridLayout *layout;
    QTextEdit *notesIn;
    QDateEdit *startCalendar;
    QDateEdit *endCalendar;

    void changeTitle(const QString &t);
    void changeSubtitle(const QString&);
    void changeAuthor(const QString&);
    void changeGenre(const int&);
    void changePagecount(const QString&);
    void changeStartRead(const QDate&);
    void changeEndRead(const QDate&);
    void changeRating(const QString&);
    void changeLanguage(const int&);
    void changeNotes();
};

#endif // BUCHANZEIGE_H
