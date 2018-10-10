#include "buch.h"

std::string& Buch::handle() const{
    return handle;
}

std::string& Buch::title() const{
    return title;
}

std::string& Buch::subtitle() const{
    return subtitle;
}

std::string& Buch::author() const{
    return author;
}

GENRE& Buch::genre() const{
    return genre;
}

unsigned int& Buch::pagecount() const{
    return pagecount();
}

unsigned int& Buch::startRead() const{
    return startRead;
}

unsigned int& Buch::endRead() const{
    return endRead;
}

float& Buch::rating() const{
    return rating;
}

LANGUAGE& Buch::language() const{
    return language;
}

std::string& Buch::notes() const{
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
