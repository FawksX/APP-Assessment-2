//
// Created by olive on 27/12/2023.
//

#ifndef APP_ASSESSMENT_2_MAINCOURSE_H
#define APP_ASSESSMENT_2_MAINCOURSE_H

#include "Item.h"
#include <string>

/**
 * @brief Represents a main course takeaway item
 */
class MainCourse : public Item
{

 public:

	MainCourse(
		const std::string& itemName,
		double itemCalories,
		double itemPrice
	);

	~MainCourse() override;

	/**
	 * @brief Gets a string representation of the Appetiser for the Menu. This formats
	 * The name, price, calories for reading by the user.
	 * @return A string representation of the Main Course
	 */
	[[nodiscard]] std::string toString() const override;

	/**
	 * @brief Gets the ItemType associated with the Main Course
	 * @return The ItemType for Main Course
	 */
	[[nodiscard]] ItemType getType() const override;
};

#endif //APP_ASSESSMENT_2_MAINCOURSE_H
