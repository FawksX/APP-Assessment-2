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

	Beverage(const Beverage& other);

	~Beverage() override;

	[[nodiscard]] double getAbv() const;

	[[nodiscard]] double getVolume() const;

	[[nodiscard]] std::string toString() const override;

	ItemType getType() const override;

};

#endif //APP_ASSESSMENT_2_BEVERAGE_H
