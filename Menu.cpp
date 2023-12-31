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
        while(std::getline(iss, line, ',')) {
            itemResult.push_back(line);
        }

        std::string itemType = itemResult[0];
        std::string name = itemResult[1];
        double price = std::stod(itemResult[2]);
        double calories = std::stod(itemResult[3]);

        Item* newItem;

        if(itemType == "m") {
            newItem = createMainCourse(name, price, calories);
        } else if(itemType == "a") {

            bool shareable = itemResult[4] == "y";
            bool twoForOne = itemResult[5] == "y";

            newItem = createAppetiser(name, price, calories, shareable, twoForOne);
        } else if(itemType == "b") {

            double volume = std::stod(itemResult[6]);
            double abv = std::stod(itemResult[7]);

            newItem = createBeverage(name, price, calories, abv, volume);
        } else {
            std::cerr << "Unsupported item type: " << itemType << std::endl;
        }

        if(newItem) {
            itemList.push_back(newItem);
        }
    }
}

// Destroyed in ItemList... no need to worry for now
Menu::~Menu() = default;

std::string Menu::toString() const {

    std::ostringstream result;

    // Map to store items by type
    std::unordered_map<char, std::vector<Item *>> itemsByType;

    // Organize items by type
    for (Item *item: itemList) {
        char itemType = 'u'; // 'u' for unknown type
        if (dynamic_cast<Appetiser *>(item)) {
            itemType = 'a';
        } else if (dynamic_cast<MainCourse *>(item)) {
            itemType = 'm';
        } else if (dynamic_cast<Beverage *>(item)) {
            itemType = 'b';
        }
        itemsByType[itemType].push_back(item);
    }

    // Create a formatted string
    for (const auto &entry: itemsByType) {
        switch (entry.first) {
            case 'a':
                result << "Appetizers:\n";
                break;
            case 'm':
                result << "\nMain Courses:\n";
                break;
            case 'b':
                result << "\nBeverages:\n";
                break;
            default:
                continue;
        }

        for (const Item *item: entry.second) {
            result << item->toString() << "\n";
        }

    }

    return result.str();

}

Item *Menu::getItem(int position) const {
    return itemList[position - 1];
}

Item *Menu::createMainCourse(const std::string& name, double price, double calories) {
    return new MainCourse(name, calories, price);
}

Item *Menu::createAppetiser(const std::string& name, double price, double calories, bool shareable, bool twoForOne) {
    return new Appetiser(name, calories, price, shareable, twoForOne);
}

Item *Menu::createBeverage(const std::string& name, double price, double calories, double abv, double volume) {
    return new Beverage(name, calories, price, abv, volume);
}