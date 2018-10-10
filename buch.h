#ifndef BUCH_H
#define BUCH_H
#include <string>

class Buch
{
public:
    enum GENRE {SciFi, Fantasy, Literary_Fiction, Thriller, Politics, Philosophy, Biography};
    enum LANGUAGE {English, German};
//    Buch()=default;
    Buch(std::string& h);
    Buch(std::string& h, std::string& t, std::string& s, std::string& a, GENRE& g, unsigned int& p, unsigned int& sr, unsigned int& er, float& r, LANGUAGE& l);
    std::string& getHandle() ;
    std::string& getTitle() const;
    std::string& getSubtitle() const;
    std::string& getAuthor() const;
    GENRE& getGenre() const;
    unsigned int& getPagecount() const;
    unsigned int& getStartRead() const;
    unsigned int& getEndRead() const;
    float& getRating() const;
    LANGUAGE& getLanguage() const;
    std::string& getNotes() const;
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
    std::string handle;
    std::string title;
    std::string subtitle;
    std::string author;
    GENRE genre;
    unsigned int pagecount;
    unsigned int startRead;
    unsigned int endRead;
    float rating;
    LANGUAGE language;
    std::string notes;

};

#endif // BUCH_H
