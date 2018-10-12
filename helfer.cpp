#include "helfer.h"

std::vector<Buch> loadData(const std::string path) {
    std::ifstream file;
    file.open(path, std::ios::in);

    std::vector<Buch> data;
    std::string input;
    while(!file.eof()) {
        getline(file, input);
        //find starting point of book entry
        auto pos = input.find('{');
        if(pos != std::string::npos) {
            data.push_back(Buch(input.substr(0, pos)));
        }
        //find equal sign
        pos = input.find('=');
        if(pos != std::string::npos) {
            std::string label = input.substr(0, pos);
            std::string value = input.substr(pos + 1, input.size());

            Buch &b = data[data.size() - 1];

            if(label == "title") {
                b.setTitle(value);
            } else if(label == "subtitle") {
                b.setSubtitle(value);
            } else if(label == "author") {
                b.setAuthor(value);
            } else if(label == "genre") {
                b.setGenre(b.stringtogenre(value));
            } else if(label == "pagecount") {
                b.setPagecount(static_cast<unsigned int>(std::stoul(value)));
            } else if(label == "startread") {
                b.setStart(value);
            } else if(label == "endread") {
                b.setEnd(value);
            } else if(label == "rating") {
                std::setlocale(LC_NUMERIC,"en_US.UTF-8");
                b.setRating(static_cast<float>(std::stof(value)));
                std::setlocale(LC_NUMERIC,"de_DE.UTF-8");
            } else if(label == "language") {
                b.setLanguage(b.stringtolanguage(value));
            } else if(label == "notes") {
                b.setNotes(value);
            }
        } else {
            continue;
        }
    }

    file.close();
    return data;
}


void saveData(const std::string path, const std::vector<Buch> &data) {
    std::ofstream file;
    file.open(path, std::ios::trunc);

    for(const Buch& b: data) {
        //deleted books have no handle
        if(b.getHandle() == "") {
            continue;
        }
        printBuch(file, b);
    }

    file.flush();
    file.close();
}

void printBuch(std::ostream &os, const Buch &b) {
    os << b.getHandle() << "{" << std::endl;
    os << "title=" << b.getTitle() << std::endl;
    os << "subtitle=" << b.getSubtitle() << std::endl;
    os << "author=" << b.getAuthor() << std::endl;
    os << "genre=" << b.genretostring(b.getGenre()) << std::endl;
    os << "pagecount=" << b.getPagecount() << std::endl;
    os << "startread=" << b.getStartRead() << std::endl;
    os << "endread=" << b.getEndRead() << std::endl;  
    os << "rating=" << b.getRating() << std::endl;
    os << "language=" << b.languagetostring(b.getLanguage()) << std::endl;
    os << "notes=" << b.getNotes() << std::endl << "}" << std::endl;
}
