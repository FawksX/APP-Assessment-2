//
// Created by Oliver Whitehead on 30/12/2023.
//

#ifndef APP_ASSESSMENT_2_ORDER_H
#define APP_ASSESSMENT_2_ORDER_H

#include "ItemList.h"

class Order : public ItemList {

public:

    Order();

    ~Order();

    /**
     * @brief Displays the items in the order, along with the total price and the savings made.
     * @return
     */
    [[nodiscard]] std::string toString() const override;

    /**
     * @brief Calculates the total price of the order, respecting twoForOne offers in the order.
     * @return
     */
    [[nodiscard]] double calculateTotal() const;

    /**
     * @brief Calculates the raw total of the order, excluding savings
     * @return
     */
    [[nodiscard]] double calculateRawTotal() const;

    [[nodiscard]] double calculateSavings() const;

    /**
     * @brief Prints the receipt of the order to receipt.txt, displaying total and savings in the following order:
     *
     * Savings: £x.xx
     * Total: £x.xx
     */
    void printReceipt() const;

    void add(Item* item);

    void remove(int position);

    [[nodiscard]] Item* getItem(int position) const;

};


#endif //APP_ASSESSMENT_2_ORDER_H
