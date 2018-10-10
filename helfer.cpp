#include "helfer.h"

std::vector<Buch> loadData(const std::string path) {
    std::ifstream file;
    file.open(path, std::ios::in);

    std::vector<Buch> data;
    std::string input;
    while(!file.eof()) {
        getline(file, input);
        //remove tabs
        input.erase(std::remove(input.begin(), input.end(), '\t'), input.end());
        //find starting point of book entry
        if(auto pos = input.find('{') != input.npos) {
            data.push_back(Buch(input.substr(0, pos - 1)));
        }
        //find equal sign
        if(int pos = input.find('=') != input.npos) {
            std::string label = input.substr(0, pos - 1);
            std::string value = input.substr(pos + 1, input.size());
            //remove spaces
            label.erase(remove_if(label.begin(), label.end(), isspace),
                         label.end());

            Buch &b = data[data.size() - 1];

            if(label.compare("title")) {
                b.setTitle(value);
            } else if(label.compare("subtitle")) {
                b.setSubtitle(value);
            } else if(label.compare("author")) {
                b.setAuthor(value);
            } else if(label.compare("genre")) {
                b.setGenre(b.stringtogenre(value));
            } else if(label.compare("pagecount")) {
                b.setPagecount(static_cast<unsigned int>(std::stoul(value)));
            } else if(label.compare("startread")) {
                b.setStart(static_cast<unsigned int>(std::stoul(value)));
            } else if(label.compare("endread")) {
                b.setEnd(static_cast<unsigned int>(std::stoul(value)));
            } else if(label.compare("rating")) {
                b.setRating(static_cast<float>(std::stof(value)));
            } else if(label.compare("language")) {
                b.setLanguage(b.stringtolanguage(value));
            } else if(label.compare("notes")) {
                b.setNotes(value);
            }
        } else {
            continue;
        }
    }

    file.close();
    return data;
}


void saveData(const std::string path, std::vector<Buch> &data) {
    std::ofstream file;
    file.open(path, std::ios::trunc);

    for(const Buch& b: data) {
        file << b.getHandle() << "{" << std::endl;
        file << "\t" << b.getTitle() << std::endl;
        file << "\t" << b.getSubtitle() << std::endl;
        file << "\t" << b.getAuthor() << std::endl;
        file << "\t" << b.genretostring(b.getGenre()) << std::endl;
        file << "\t" << b.getPagecount() << std::endl;
        file << "\t" << b.getStartRead() << std::endl;
        file << "\t" << b.getEndRead() << std::endl;
        file << "\t" << b.getRating() << std::endl;
        file << "\t" << b.languagetostring(b.getLanguage()) << std::endl;
        file << "\t" << b.getNotes() << std::endl << "}" << std::endl;
    }

    file.flush();
    file.close();
}
