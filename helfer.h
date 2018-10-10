#ifndef HELFER_H
#define HELFER_H

#include <vector>
#include <string>
#include <fstream>

#include "buch.h"

std::vector<Buch>& loadData(const std::string path);
void saveData(const std::string path, std::vector<Buch> &data);

#endif // HELFER_H
