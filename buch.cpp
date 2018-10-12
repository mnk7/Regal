#include "buch.h"

Buch::Buch(std::string h){
    handle=h; rating=0;
}

Buch::Buch(const Buch &b){
    this->handle=b.getHandle();
    this->title=b.getTitle();
    this->subtitle=b.getSubtitle();
    this->author=b.getAuthor();
    this->genre=b.getGenre();
    this->pagecount=b.getPagecount();
    this->startRead=b.getStartRead();
    this->endRead=b.getEndRead();
    this->rating=b.getRating();
    this->language=b.getLanguage();
    this->notes=b.getNotes();
    this->deleted=false;
}

Buch::Buch(std::string h, std::string t, std::string s,
           std::string a, GENRE g, unsigned int p,
           std::string sr, std::string er,
           float r, LANGUAGE l){
    handle=h; title=t; subtitle=s;author=a; pagecount=p;
    startRead=sr; endRead=er; rating=r; genre=g;
    language=l; deleted=false;
}

const std::string Buch::getHandle() const {
    return handle;
}

const std::string Buch::getTitle() const{
    return title;
}

const std::string Buch::getSubtitle() const{
    return subtitle;
}

const std::string Buch::getAuthor() const{
    return author;
}

Buch::GENRE Buch::getGenre() const{
    return genre;
}

unsigned int Buch::getPagecount() const{
    return pagecount;
}

const std::string Buch::getStartRead() const{
    return startRead;
}

const std::string Buch::getEndRead() const{
    return endRead;
}

float Buch::getRating() const{
    return rating;
}

Buch::LANGUAGE Buch::getLanguage() const{
    return language;
}

const std::string Buch::getNotes() const{
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

void Buch::setStart(const std::string x){
    startRead=x;
}

void Buch::setEnd(const std::string x){
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

void Buch::setEntfernt(){
    deleted=true;
}

bool Buch::entfernt() const{
    return deleted;
}

Buch::GENRE Buch::stringtogenre(const std::string x){
    if(x=="SciFi") return SciFi;
    else if(x=="Fantasy") return Fantasy;
    else if(x=="Literary Fiction") return Literary_Fiction;
    else if(x=="Crime/Thriller") return Thriller;
    else if(x=="Politics") return Politics;
    else if(x=="Philosophy") return Philosophy;
    else if(x=="Biography") return Biography;
    else return none;
}

Buch::LANGUAGE Buch::stringtolanguage(const std::string x){
    if(x=="English") return English;
    else if (x=="German") return German;
    else return NA;
}

const std::string Buch::genretostring(const GENRE &x) const{
    switch (x) {
    case SciFi:
        return "SciFi";
    case Fantasy:
        return "Fantasy";
    case Literary_Fiction:
        return "Literary Fiction";
    case Thriller:
        return "Crime/Thriller";
    case Politics:
        return "Politics";
    case Philosophy:
        return "Philosophy";
    case Biography:
        return "Biography";
    default:
        return "";
    }
}

const std::string Buch::languagetostring(const LANGUAGE &x) const{
    switch (x) {
    case English:
        return "English";
    case German:
        return "German";
    default:
        return "";
    }
}

Buch& Buch::operator=(const Buch& b){
    this->handle=b.getHandle();
    this->title=b.getTitle();
    this->subtitle=b.getSubtitle();
    this->author=b.getAuthor();
    this->genre=b.getGenre();
    this->pagecount=b.getPagecount();
    this->startRead=b.getStartRead();
    this->endRead=b.getEndRead();
    this->rating=b.getRating();
    this->language=b.getLanguage();
    this->notes=b.getNotes();
    return *this;
}
