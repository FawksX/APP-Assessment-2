//
// Created by olive on 24/12/2023.
//

#include <sstream>
#include <iomanip>
#include <iostream>
#include "Item.h"

Item::Item(
        const std::string &itemName,
        double itemCalories,
        double itemPrice
) : name(itemName), calories(itemCalories), price(itemPrice) {

};

Item::~Item() = default;

std::string Item::getName() const {
    return name;
}

double Item::getCalories() const {
    return calories;
}

double Item::getPrice() const {
    return price;
}

std::string Item::parseNumber(double num) {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << num;
    std::string s = stream.str();
    std::cout << "DEBUG: ROUNDING " << s << std::endl;
    return s;
}