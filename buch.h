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
    Buch(std::string h, std::string t, std::string s, std::string a, GENRE g, unsigned int p, unsigned int sr, unsigned int er, float r, LANGUAGE l);
    const std::string& getHandle() const ;
    const std::string& getTitle() const;
    const std::string& getSubtitle() const;
    const std::string& getAuthor() const;
    const GENRE& getGenre() const;
    const unsigned int& getPagecount() const;
    const unsigned int& getStartRead() const;
    const unsigned int& getEndRead() const;
    const float& getRating() const;
    const LANGUAGE& getLanguage() const;
    const std::string& getNotes() const;
    void setTitle(std::string const);
    void setSubtitle(std::string const);
    void setAuthor(std::string const);
    void setGenre(GENRE const);
    void setPagecount(unsigned int const);
    void setStart(unsigned int const);
    void setEnd(unsigned int const);
    void setRating(float const);
    void setLanguage(LANGUAGE const);
    void setNotes(std::string const);

    GENRE stringtogenre(const std::string);
    LANGUAGE stringtolanguage(const std::string);
    const std::string genretostring(const GENRE&) const;
    const std::string languagetostring(const LANGUAGE&) const;

    Buch& operator=(const Buch&);
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
