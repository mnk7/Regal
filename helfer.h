#ifndef HELFER_H
#define HELFER_H

#include <vector>
#include <string>

#include "buch.h"

std::vector<Buch> loadData(std::string path);
void saveData(std::string path, std::vector<Buch> data);

#endif // HELFER_H
