#ifndef BUCH_H
#define BUCH_H
#include <string>

class Buch
{
public:
    enum GENRE {SciFi, Fantasy, Literary_Fiction, Thriller, Politics, Philosophy, Biography, none};
    enum LANGUAGE {English, German, NA};
    Buch()=default;
    Buch(std::string h);
    Buch(const Buch &b);
    Buch(std::string h, std::string t, std::string s, std::string a, GENRE g, unsigned int p, std::string sr, std::string er, float r, LANGUAGE l);
    const std::string getHandle() const ;
    const std::string getTitle() const;
    const std::string getSubtitle() const;
    const std::string getAuthor() const;
    GENRE getGenre() const;
    unsigned int getPagecount() const;
    const std::string getStartRead() const;
    const std::string getEndRead() const;
    float getRating() const;
    LANGUAGE getLanguage() const;
    const std::string getNotes() const;
    void setTitle(std::string const);
    void setSubtitle(std::string const);
    void setAuthor(std::string const);
    void setGenre(GENRE const);
    void setPagecount(unsigned int const);
    void setStart(std::string const);
    void setEnd(std::string const);
    void setRating(float const);
    void setLanguage(LANGUAGE const);
    void setNotes(std::string const);

    void setEntfernt();
    bool entfernt() const;

    GENRE stringtogenre(const std::string);
    LANGUAGE stringtolanguage(const std::string);
    const std::string genretostring(const GENRE&) const;
    const std::string languagetostring(const LANGUAGE&) const;

    Buch& operator=(const Buch&);
private:
    std::string handle="";
    std::string title="";
    std::string subtitle="";
    std::string author="";
    GENRE genre=none;
    unsigned int pagecount=0;
    std::string startRead="0000.00.00";
    std::string endRead="0000.00.00";
    float rating=0;
    LANGUAGE language=NA;
    std::string notes="";
    bool deleted=false;

};

#endif // BUCH_H
