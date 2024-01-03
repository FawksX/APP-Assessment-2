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
class Item
{

 private:
	std::string name;
	double calories;
	double price;

 public:

	Item(
		std::string itemName,
		double itemCalories,
		double itemPrice
	);

	virtual ~Item();

	/**
	 * @brief Converts the takeaway item to a human-readable string.
	 * @attention This method is pure virtual and must be implemented by any derived classes.
	 * @return A string representation of the takeaway item.
	 */
	[[nodiscard]] virtual std::string toString() const = 0;

	/**
	 * @brief Gets the type of the takeaway item
	 * @return The type of the item
	 */
	[[nodiscard]] virtual ItemType getType() const = 0;

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

	/**
	 * @brief Compares two takeaway items by price
	 * @param other The other takeaway item to compare to
	 * @return True if this takeaway item is more expensive than the other, otherwise false
	 */
	bool operator>(const Item& other) const;

	/**
	 * @brief Compares two takeaway items by price
	 * @param other The other takeaway item to compare to
	 * @return True if this takeaway item is less expensive than the other, otherwise false
	 */
	bool operator<(const Item& other) const;

	/**
	 * @brief Outputs the takeaway item to the output stream to allow for appending
	 * @param os The output stream to output to
	 * @param item The takeaway item to output
	 * @return The output stream
	 */
	friend std::ostream& operator<<(std::ostream& os, const Item& item);

};

#endif //APP_ASSESSMENT_2_ITEM_H
