//
// Created by olive on 24/12/2023.
//

#ifndef APP_ASSESSMENT_2_ITEM_H
#define APP_ASSESSMENT_2_ITEM_H

#include <string>
#include "ItemType.h"

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
            std::string  itemName,
            double itemCalories,
            double itemPrice
    );

    virtual ~Item();

    /**
     * @brief Gets the name of the takeaway item
     * @return The name of the item
     */
    [[nodiscard]] std::string getName() const;

    /**
     * @brief Gets the calories of the takeaway item
     * @return The calories of the takeaway item
     */
    [[nodiscard]] double getCalories() const;

    /**
     * @brief Gets the price of the takeaway item
     * @return The price of the takeaway item
     */
    [[nodiscard]] double getPrice() const;

    [[nodiscard]] virtual std::string toString() const = 0;

    bool operator>(const Item& other) const;

    bool operator<(const Item& other) const;

    virtual ItemType getType() const = 0;

};

#endif //APP_ASSESSMENT_2_ITEM_H
