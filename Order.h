//
// Created by Oliver Whitehead on 30/12/2023.
//

#ifndef APP_ASSESSMENT_2_ORDER_H
#define APP_ASSESSMENT_2_ORDER_H

#include "ItemList.h"

/**
 * @brief Represents an order made by a user of the app.
 */
class Order : public ItemList
{

 public:

	Order();

	~Order();

	/**
	 * @brief Displays the items in the order, along with the total price and the savings made.
	 * @return A string representation of the order.
	 */
	[[nodiscard]] std::string toString() const override;

	/**
	 * @brief Calculates the total price of the order, respecting twoForOne offers in the order.
	 * and any savings made
	 * @return The total price of the order as a double, payable by the user.
	 */
	[[nodiscard]] double calculateTotal() const;

	/**
	 * @brief Calculates the total price of the order, ignoring any
	 * savings made by the user through two-for-one deals.
	 * @return The total price of the order as a double, excluding savings
	 */
	[[nodiscard]] double calculateRawTotal() const;

	/**
	 * @brief Calculates the savings made by the user through two-for-one deals.
	 * @return The savings made by the user as a double.
	 */
	[[nodiscard]] double calculateSavings() const;

	/**
	 * @brief Prints the receipt of the order to receipt.txt, displaying total and savings in the following order:
	 *
	 * Savings: £x.xx
	 * Total: £x.xx
	 */
	void printReceipt() const;

	/**
	 * @brief Adds an item to the order
	 * @param item The item to add to the order
	 */
	void add(Item* item);

	/**
	 * @brief Removes an item from the order
	 * @param position The index of the item in the order to remove
	 */
	void remove(int position);

	/**
	 * @brief Gets the item at a specific index in the ItemList
	 * @param position The position of the item to get
	 * @return A pointer to the item at the specified position, or nullptr if the position is invalid
	 */
	[[nodiscard]] Item* getItem(int position) const;

};

#endif //APP_ASSESSMENT_2_ORDER_H
