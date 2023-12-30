//
// Created by olive on 25/12/2023.
//

#include "Beverage.h"

Beverage::Beverage(
        const std::string &itemName,
        double itemCalories,
        double itemPrice,
        double abv,
        double volume
) : Item(itemName, itemCalories, itemPrice), abv(abv), volume(volume) {

};

Beverage::Beverage(const Beverage &other) = default;

Beverage::~Beverage() = default;

double Beverage::getAbv() const {
    return abv;
}

double Beverage::getVolume() const {
    return volume;
}