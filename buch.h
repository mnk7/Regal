#ifndef BUCH_H
#define BUCH_H
#include <QString>

class Buch
{
public:
    enum GENRE {Sci-Fi, Fantasy, Literary Fiction, Thriller, Politics, Philosophy, Biography};
    enum LANGUAGE {English, German}
    Buch();
    QString& title() const;
    QString& subtitle() const;
    QString& author() const;
    GENRE& genre() const;
    unsigned int& pagecount() const;
    unsigned int& startRead() const;
    unsigned int& endRead() const;
    float& rating() const;
    LANGUAGE& language() const;
    QString& notes() const;
    void setTitle(QString const&);
    void setSubtitle(QString const&);
    void setAuthor(QString const&);
    void setGenre(GENRE const&);
    void setPagecount(unsigned int const&);
    void setStart(unsigned int const&);
    void setEnd(unsigned int const&);
    void setRating(float const&);
    void setLanguage(LANGUAGE const&);
    void setNotes(QString const&);

private:
    QString const handle;
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
