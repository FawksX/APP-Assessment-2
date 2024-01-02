//
// Created by Oliver Whitehead on 02/01/2024.
//

#include <ios>
#include <iomanip>

#include "Util.h"

std::string Util::parseNumber(double num) {
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << num;
        std::string s = stream.str();
        return s;
}