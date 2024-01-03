//
// Created by olive on 24/12/2023.
//

#ifndef APP_ASSESSMENT_2_APPETISER_H
#define APP_ASSESSMENT_2_APPETISER_H

#include "Item.h"
#include <string>

/**
 * @brief Represents an Appetiser takeaway item.
 */
class Appetiser : public Item
{

 private:
	bool shareable;
	bool twoForOne;

 public:

	Appetiser(
		const std::string& itemName,
		double itemCalories,
		double itemPrice,
		bool shareable,
		bool twoForOne
	);

	~Appetiser() override;

	/**
	 * @brief Gets if the Appetiser is shareable
	 * @return true if the appetiser is shareable, otherwise false
	 */
	[[nodiscard]] bool isShareable() const;

	/**
	 * @brief Get if the Appetiser is apart of a two-for-one deal
	 * @return true if the appetiser has a two-for-one deal, otherwise false
	 */
	[[nodiscard]] bool isTwoForOne() const;

	/**
	 * @brief Gets a string representation of the Appetiser for the Menu. This formats
	 * The name, price, calories and appetiser deals for reading by the user.
	 * @return A string representation of the Appetiser
	 */
	[[nodiscard]] std::string toString() const override;

	/**
	 * @brief Gets the ItemType associated with the Appetiser
	 * @return The ItemType for Appetiser
	 */
	[[nodiscard]] ItemType getType() const override;

};

#endif //APP_ASSESSMENT_2_APPETISER_H
