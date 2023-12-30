//
// Created by olive on 24/12/2023.
//

#ifndef APP_ASSESSMENT_2_ITEM_H
#define APP_ASSESSMENT_2_ITEM_H

#include <string>

/**
 * @brief Represents any takeaway item.
 */
class Item {

private:
    std::string name;
    double calories;
    double price;

public:

    Item(
            const std::string& itemName,
            double itemCalories,
            double itemPrice
    );

    virtual ~Item();

    /**
     * @brief Gets the name of the takeaway item
     * @return The name of the item
     */
    std::string getName() const;

    /**
     * @brief Gets the calories of the takeaway item
     * @return The calories of the takeaway item
     */
    double getCalories() const;

    /**
     * @brief Gets the price of the takeaway item
     * @return The price of the takeaway item
     */
    double getPrice() const;

};

#endif //APP_ASSESSMENT_2_ITEM_H
