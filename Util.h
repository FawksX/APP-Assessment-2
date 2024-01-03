//
// Created by Oliver Whitehead on 02/01/2024.
//

#ifndef APP_ASSESSMENT_2_UTIL_H
#define APP_ASSESSMENT_2_UTIL_H

#include <string>
#include "ItemType.h"

namespace Util {
    std::string parseNumber(double num);
    ItemType parseItemType(const std::string& type);
    int parseNumber(const std::string& num, int defaultNum);
};


#endif //APP_ASSESSMENT_2_UTIL_H
