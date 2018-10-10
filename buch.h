#ifndef BUCH_H
#define BUCH_H
#include <string>

class Buch
{
public:
    enum GENRE {SciFi, Fantasy, Literary_Fiction, Thriller, Politics, Philosophy, Biography};
    enum LANGUAGE {English, German};
    Buch()=default;
    Buch(std::string h): handle(h){}
    Buch(std::string& h, std::string& t, std::string& s, std::string& a, GENRE& g, unsigned int& p, unsigned int& sr, unsigned int& er, float& r, LANGUAGE& l):
        handle(h), title(t), subtitle(s), author(a), pagecount(p), startRead(sr), endRead(er), rating(r){
        genre=g;
        language=l;
    }
    std::string& handle() const;
    std::string& title() const;
    std::string& subtitle() const;
    std::string& author() const;
    GENRE& genre() const;
    unsigned int& pagecount() const;
    unsigned int& startRead() const;
    unsigned int& endRead() const;
    float& rating() const;
    LANGUAGE& language() const;
    std::string& notes() const;
    void setTitle(std::string const&);
    void setSubtitle(std::string const&);
    void setAuthor(std::string const&);
    void setGenre(GENRE const&);
    void setPagecount(unsigned int const&);
    void setStart(unsigned int const&);
    void setEnd(unsigned int const&);
    void setRating(float const&);
    void setLanguage(LANGUAGE const&);
    void setNotes(std::string const&);

private:
    std::string handle="";
    std::string title="";
    std::string subtitle="";
    std::string author="";
    GENRE genre=Politics;
    unsigned int pagecount=0;
    unsigned int startRead=0;
    unsigned int endRead=0;
    float rating=0;
    LANGUAGE language=English;
    std::string notes="";

};

#endif // BUCH_H
