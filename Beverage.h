//
// Created by olive on 25/12/2023.
//

#ifndef APP_ASSESSMENT_2_BEVERAGE_H
#define APP_ASSESSMENT_2_BEVERAGE_H

#include "Item.h"
#include <string>

/**
 * @brief Represents a drink takeaway item
 */
class Beverage : public Item
{

 private:
	double abv;
	double volume;

 public:

	Beverage(
		const std::string& itemName,
		double itemCalories,
		double itemPrice,
		double abv,
		double volume
	);

	~Beverage() override;

	/**
	 * @brief Get the alcohol by volume of the beverage
	 * @return The alcohol by volume of the beverage as a double
	 */
	[[nodiscard]] double getAbv() const;

	/**
	 * @brief Get the volume of the beverage
	 * @return The volume of the beverage as a double
	 */
	[[nodiscard]] double getVolume() const;

/**
	 * @brief Get a string representation of the Beverage for the menu. This formats
	 * The name, price, calories, volume and abv (if present) for reading by the user.
	 * @return A string representation of the beverage
	 */
	[[nodiscard]] std::string toString() const override;

	/**
	 * @brief Gets the ItemType associated with the Beverage
	 * @return The ItemType for Beverage
	 */
	[[nodiscard]] ItemType getType() const override;

};

#endif //APP_ASSESSMENT_2_BEVERAGE_H
