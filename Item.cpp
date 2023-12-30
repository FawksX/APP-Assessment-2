//
// Created by olive on 24/12/2023.
//

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