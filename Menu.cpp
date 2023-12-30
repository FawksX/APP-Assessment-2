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

Menu::Menu(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        char itemType;
        iss >> itemType;

        // Assuming item details are provided after the item type
        std::string itemDetails;
        std::getline(iss, itemDetails);

        Item* newItem = createItem(itemType, itemDetails);
        if (newItem) {
            itemList.push_back(newItem);
        }
    }
}

// Destroyed in ItemList... no need to worry for now
Menu::~Menu() = default;

Item* Menu::createItem(char itemType, const std::string &itemDetails) {

    switch (itemType) {
        case 'a': { // Appetizer
            std::string name;
            double price, calories;
            bool shareable, twoForOne;

            std::istringstream iss(itemDetails);
            iss >> name >> price >> calories >> std::boolalpha >> shareable >> twoForOne;

            return new Appetiser(name, calories, price, shareable, twoForOne);
        }

        case 'm': { // Main Course
            std::string name;
            double price, calories;

            std::istringstream iss(itemDetails);
            iss >> name >> price >> calories;

            return new MainCourse(name, calories, price);
        }

        case 'b': { // Beverage
            std::string name;
            double calories, price, volume, abv;

            std::istringstream iss(itemDetails);
            iss >> name >> calories >> price >> volume >> abv;

            return new Beverage(name, calories, price, volume, abv);
        }

        default:
            // Handle unsupported item type
            std::cerr << "Unsupported item type: " << itemType << std::endl;
            return nullptr;
    }
}

std::string Menu::toString() const {
        std::ostringstream result;

        // Map to store items by type
        std::unordered_map<char, std::vector<Item*>> itemsByType;

        // Organize items by type
        for (Item* item : itemList) {
            char itemType = 'u'; // 'u' for unknown type
            if (dynamic_cast<Appetizer*>(item)) {
                itemType = 'a';
            } else if (dynamic_cast<MainCourse*>(item)) {
                itemType = 'm';
            } else if (dynamic_cast<Beverage*>(item)) {
                itemType = 'b';
            }
            itemsByType[itemType].push_back(item);
        }

        // Create a formatted string
        for (const auto& entry : itemsByType) {
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

            for (const Item* item : entry.second) {
                result << item->toString() << "\n";
            }
        }

        return result.str();

}