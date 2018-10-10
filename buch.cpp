#include "buch.h"

Buch::Buch(std::string& h){
    handle=h;
}

Buch::Buch(std::string &h, std::string &t, std::string &s, std::string &a, GENRE &g, unsigned int &p, unsigned int &sr, unsigned int &er, float &r, LANGUAGE &l){

    handle=h; title=t; subtitle=s;author=a; pagecount=p;
    startRead=sr; endRead=er; rating=r;
    genre=g;
    language=l;
}

std::string& Buch::getHandle() {
    return handle;
}

std::string& Buch::getTitle() const{
    return title;
}

std::string& Buch::getSubtitle() const{
    return subtitle;
}

std::string& Buch::getAuthor() const{
    return author;
}

Buch::GENRE& Buch::getGenre() const{
    return genre;
}

unsigned int& Buch::getPagecount() const{
    return pagecount();
}

unsigned int& Buch::getStartRead() const{
    return startRead;
}

unsigned int& Buch::getEndRead() const{
    return endRead;
}

float& Buch::getRating() const{
    return rating;
}

Buch::LANGUAGE& Buch::getLanguage() const{
    return language;
}

std::string& Buch::getNotes() const{
    return notes;
}

void Buch::setTitle(const std::string &x){
    title=x;
}

void Buch::setSubtitle(const std::string &x){
    subtitle=x;
}

void Buch::setAuthor(const std::string &x){
    author=x;
}

void Buch::setGenre(const GENRE &x){
    genre=x;
}

void Buch::setPagecount(const unsigned int &x){
    pagecount=x;
}

void Buch::setStart(const unsigned int &x){
    startRead=x;
}

void Buch::setEnd(const unsigned int &x){
    endRead=x;
}

void Buch::setRating(const float &x){
    rating=x;
}

void Buch::setLanguage(const LANGUAGE &x){
    language=x;
}

void Buch::setNotes(const std::string &x){
    notes=x;
}
