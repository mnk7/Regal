#include "helfer.h"

std::vector<Buch> loadData(const std::string path) {
    std::ofstream file;
    file.open(path, std::ios::in);

    std::vector<Buch> data;

    file.close();
    return data;
}


void saveData(const std::string path, std::vector<Buch> &data) {
    std::ofstream file;
    file.open(path, std::ios::trunc);

    file.flush();
    file.close();
}
