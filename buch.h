#ifndef BUCH_H
#define BUCH_H
#include <QString>

class Buch
{
public:
    enum GENRE {Sci-Fi, Fantasy, Literary Fiction, Thriller, Politics, Philosophy, Biography};
    enum LANGUAGE {English, German}
    Buch();
private:
    QString handle;
    QString title;
    QString subtitle;
    QString author;
    GENRE genre;
    unsigned int pagecount;
    unsigned int startRead;
    unsigned int endRead;
    float rating;
    LANGUAGE language;
    QString notes;

};

#endif // BUCH_H
