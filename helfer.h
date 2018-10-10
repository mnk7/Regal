#ifndef HELFER_H
#define HELFER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "buch.h"

std::vector<Buch> loadData(const std::string path);
void saveData(const std::string path, const std::vector<Buch> &data);
void printBuch(std::ostream&, const Buch&);

#endif // HELFER_H
