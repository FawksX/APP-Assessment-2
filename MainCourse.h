//
// Created by olive on 27/12/2023.
//

#ifndef APP_ASSESSMENT_2_MAINCOURSE_H
#define APP_ASSESSMENT_2_MAINCOURSE_H

#include "Item.h"
#include <string>

class MainCourse : public Item
{

 public:

	MainCourse(
		const std::string& itemName,
		double itemCalories,
		double itemPrice
	);

	MainCourse(const MainCourse& other);

	~MainCourse() override;

	[[nodiscard]] std::string toString() const override;

	ItemType getType() const override;
};

#endif //APP_ASSESSMENT_2_MAINCOURSE_H
