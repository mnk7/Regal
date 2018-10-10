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
    ~Buchanzeige()=default;

signals:

private:
    void openCalendar();
    void changeTitle(const QString&);
    void changeSubtitle(const QString&);
    void changeAuthor(const QString&);
    void changeGenre(const int&);
    void changePagecount(const unsigned int&);
    void changeStartRead(const QDate&);
    void changeEndRead(const QDate&);
    void changeRating(const float&);
    void changeLanguage(const int&);
    void changeNotes(const QString&);
};

#endif // BUCHANZEIGE_H
