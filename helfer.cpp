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
        if(auto pos = input.find('=') != input.npos) {
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

            } else if(label.compare("pagecount")) {
                b.setPagecount(static_cast<unsigned int>(std::stoul(value)));
            } else if(label.compare("startRead")) {
                b.setStart(static_cast<unsigned int>(std::stoul(value)));
            } else if(label.compare("rating")) {

            } else if(label.compare("language")) {

            } else if(label.compare("fiction")) {

            } else if(label.compare("notes")) {

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

    file.flush();
    file.close();
}
