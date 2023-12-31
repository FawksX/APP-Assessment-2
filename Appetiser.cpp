//
// Created by olive on 24/12/2023.
//

#include "Appetiser.h"

Appetiser::Appetiser(
        const std::string &itemName,
        double itemCalories,
        double itemPrice,
        bool shareable,
        bool twoForOne
) : Item(itemName, itemCalories, itemPrice), twoForOne(twoForOne), shareable(shareable) {

};

Appetiser::Appetiser(const Appetiser& other) = default;

Appetiser::~Appetiser() = default;

bool Appetiser::isShareable() const {
    return shareable;
}

bool Appetiser::isTwoForOne() const {
    return twoForOne;
}

std::string Appetiser::toString() const {
    std::string string = getName() + ": £" + parseNumber(getPrice()) + ", " + parseNumber(getCalories()) + " cal";

    if (isShareable()) {
        string += " (shareable) ";
    }

    if (isTwoForOne()) {
        string += " (2-4-1)";
    }

    return string;
}