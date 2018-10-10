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
            data.push_back(new Buch(input.substr(0, pos - 1)));
        }
        //find equal sign
        if(auto pos = input.find('=') != input.npos) {
            std::string label = input.substr(0, pos - 1);
            //remove spaces
            label.erase(remove_if(label.begin(), label.end(), isspace),
                         label.end());
            std::string value = input.substr(pos + 1, input.size());

            if(label.compare("title")) {

            } else if(label.compare("subtitle")) {

            } else if(label.compare("author")) {

            } else if(label.compare("genre")) {

            } else if(label.compare("pagecount")) {

            } else if(label.compare("read")) {

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
