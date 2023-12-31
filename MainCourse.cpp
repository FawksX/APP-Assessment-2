//
// Created by olive on 27/12/2023.
//

#include "MainCourse.h"

MainCourse::MainCourse(
        const std::string &itemName,
        double itemCalories,
        double itemPrice
        ): Item(itemName, itemCalories, itemPrice) {

}

MainCourse::MainCourse(const MainCourse &other) = default;

MainCourse::~MainCourse() = default;

std::string MainCourse::toString() const {
    return getName() + ": £" + parseNumber(getPrice()) + ", " + parseNumber(getCalories()) + " cal";
}