#ifndef BUCH_H
#define BUCH_H
#include <QString>

class Buch
{
public:
    enum GENRE {Sci-Fi, Fantasy, Literary Fiction, Thriller, Politics, Philosophy, Biography};
    enum LANGUAGE {English, German}
    Buch()=default;
    Buch(QString h): handle(h){}
    Buch(QString& h, QString& t, QString& s, QString& a, GENRE& g, unsigned int& p, unsigned int& sr, unsigned int& er, float& r, LANGUAGE& l):
        handle(h), title(t), subtitle(s), author(a), pagecount(p), startRead(sr), endRead(er), rating(r){
        genre=g;
        language=l;
    }
    QString& handle() const;
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
    QString handle="";
    QString title="";
    QString subtitle="";
    QString author="";
    GENRE genre=Politics;
    unsigned int pagecount=0;
    unsigned int startRead=0;
    unsigned int endRead=0;
    float rating=0;
    LANGUAGE language=English;
    QString notes="";

};

#endif // BUCH_H
