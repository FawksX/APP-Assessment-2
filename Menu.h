//
// Created by olive on 27/12/2023.
//

#ifndef APP_ASSESSMENT_2_MENU_H
#define APP_ASSESSMENT_2_MENU_H


#include "ItemList.h"

class Menu : public ItemList {
public:
    // Constructor that takes a file path to load the menu
    Menu(const std::string& filePath);

    // Destructor
    ~Menu();

    // Function to display the menu
    std::string toString() const override;

private:
    // Private helper function to create a menu item based on the type
    static Item* createItem(char itemType, const std::string& itemDetails);

    // Other private helper functions as needed
};


#endif //APP_ASSESSMENT_2_MENU_H
