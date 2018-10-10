#include "buch.h"

Buch::Buch(std::string h){
    handle=h;
}

Buch::Buch(std::string h, std::string t, std::string s, std::string a, GENRE g, unsigned int p, unsigned int sr, unsigned int er, float r, LANGUAGE l){
    handle=h; title=t; subtitle=s;author=a; pagecount=p;
    startRead=sr; endRead=er; rating=r;
    genre=g;
    language=l;
}

const std::string& Buch::getHandle() const {
    return handle;
}

const std::string &Buch::getTitle() const{
    return title;
}

const std::string& Buch::getSubtitle() const{
    return subtitle;
}

const std::string& Buch::getAuthor() const{
    return author;
}

const Buch::GENRE& Buch::getGenre() const{
    return genre;
}

const unsigned int& Buch::getPagecount() const{
    return pagecount;
}

const unsigned int& Buch::getStartRead() const{
    return startRead;
}

const unsigned int& Buch::getEndRead() const{
    return endRead;
}

const float& Buch::getRating() const{
    return rating;
}

const Buch::LANGUAGE& Buch::getLanguage() const{
    return language;
}

const std::string& Buch::getNotes() const{
    return notes;
}

void Buch::setTitle(const std::string x){
    title=x;
}

void Buch::setSubtitle(const std::string x){
    subtitle=x;
}

void Buch::setAuthor(const std::string x){
    author=x;
}

void Buch::setGenre(const GENRE x){
    genre=x;
}

void Buch::setPagecount(const unsigned int x){
    pagecount=x;
}

void Buch::setStart(const unsigned int x){
    startRead=x;
}

void Buch::setEnd(const unsigned int x){
    endRead=x;
}

void Buch::setRating(const float x){
    rating=x;
}

void Buch::setLanguage(const LANGUAGE x){
    language=x;
}

void Buch::setNotes(const std::string x){
    notes=x;
}

const Buch::GENRE Buch::stringtogenre(const std::string x) const{
    if(x=="SciFi") return SciFi;
    else if(x=="Fantasy") return Fantasy;
    else if(x=="Literary Fiction") return Literary_Fiction;
    else if(x=="Crime/Thriller") return Thriller;
    else if(x=="Politics") return Politics;
    else if(x=="Philosophy") return Philosophy;
    else if(x=="Biography") return Biography;
    else return none;
}

const Buch::LANGUAGE Buch::stringtolanguage(const std::string x) const{
    if(x=="English") return English;
    else if (x=="German") return German;
    else return NA;
}

const std::string Buch::genretostring(const GENRE &x) const{
    switch (x) {
    case SciFi:
        return "SciFi";
        break;
    case Fantasy:
        return "Fantasy";
        break;
    case Literary_Fiction:
        return "Literary Fiction";
        break;
    case Thriller:
        return "Crime/Thriller";
        break;
    case Politics:
        return "Politics";
        break;
    case Philosophy:
        return "Philosophy";
        break;
    case Biography:
        return "Biography";
        break;
    default:
        return "";
        break;
    }
}

const std::string Buch::languagetostring(const LANGUAGE &x) const{
    switch (x) {
    case English:
        return "English";
        break;
    case German:
        return "German";
        break;
    default:
        return "";
        break;
    }
}
