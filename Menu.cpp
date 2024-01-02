//
// Created by olive on 27/12/2023.
//

#include "Menu.h"
#include "Appetiser.h"
#include "Beverage.h"
#include "MainCourse.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <functional>

Menu::Menu(const std::string &filePath) {

    std::ifstream file(filePath);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);

        std::vector<std::string> itemResult;
        while (std::getline(iss, line, ',')) {
            itemResult.push_back(line);
        }

        std::string itemType = itemResult[0];
        std::string name = itemResult[1];
        double price = std::stod(itemResult[2]);
        double calories = std::stod(itemResult[3]);

        Item *newItem = nullptr;

        if (itemType == "m") {
            newItem = createMainCourse(name, price, calories);
        } else if (itemType == "a") {

            bool shareable = itemResult[4] == "y";
            bool twoForOne = itemResult[5] == "y";

            newItem = createAppetiser(name, price, calories, shareable, twoForOne);
        } else if (itemType == "b") {

            double volume = std::stod(itemResult[6]);
            double abv = std::stod(itemResult[7]);

            newItem = createBeverage(name, price, calories, abv, volume);
        } else {
            std::cerr << "Unsupported item type: " << itemType << std::endl;
        }

        if (newItem) {
            itemList.push_back(newItem);
        }
    }

    // Order the list by Appetisers, Main Courses, Beverages
    std::sort(itemList.begin(), itemList.end(), [](Item *a, Item *b) {
        return a->getType() < b->getType();
    });

}

// Destroyed in ItemList... no need to worry for now
Menu::~Menu() = default;

std::string Menu::toString() const {

    std::ostringstream result;

    // Item list is sorted appetisers, main courses, beverages, print out the list and insert headings when the type changes
    result << "Menu:\n";

    std::string currentType;

    for (int i = 0; i < itemList.size(); i++) {
        Item *item = itemList[i];

        if (auto *t = dynamic_cast<Appetiser *>(item)) {
            if (currentType != "Appetisers") {
                result << "\nAppetisers:\n";
                currentType = "Appetisers";
            }
        } else if (auto *t = dynamic_cast<MainCourse *>(item)) {
            if (currentType != "Main Courses") {
                result << "\nMain Courses:\n";
                currentType = "Main Courses";
            }
        } else if (auto *t = dynamic_cast<Beverage *>(item)) {
            if (currentType != "Beverages") {
                result << "\nBeverages:\n";
                currentType = "Beverages";
            }
        }

        result << i + 1 << ". " << item->toString() << "\n";
    }

    return result.str();

}

void Menu::sortByPrice(bool ascending) {
    auto compareByCategoryAndPrice = [ascending](Item *a, Item *b) {

        // first ensure we aren't going to swap the categories, then sort by price
        if (a->getType() == b->getType()) {
            return ascending ? (*a < *b) : (*a > *b);
        } else {
            return false; // don't swap categories
        }

    };

    std::sort(itemList.begin(), itemList.end(), compareByCategoryAndPrice);
}

Item *Menu::getItem(int position) const {
    if (position - 1 < itemList.size()) {
        return itemList[position - 1];
    } else {
        return nullptr;
    }
}

Item *Menu::createMainCourse(const std::string &name, double price, double calories) {
    return new MainCourse(name, calories, price);
}

Item *Menu::createAppetiser(const std::string &name, double price, double calories, bool shareable, bool twoForOne) {
    return new Appetiser(name, calories, price, shareable, twoForOne);
}

Item *Menu::createBeverage(const std::string &name, double price, double calories, double abv, double volume) {
    return new Beverage(name, calories, price, abv, volume);
}