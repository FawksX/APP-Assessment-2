//
// Created by olive on 27/12/2023.
//

#include <sstream>
#include "MainCourse.h"
#include "Util.h"

MainCourse::MainCourse(
	const std::string& itemName,
	double itemCalories,
	double itemPrice
) : Item(itemName, itemCalories, itemPrice)
{

}

MainCourse::~MainCourse() = default;

std::string MainCourse::toString() const
{
	std::ostringstream result;
	result << getName() << ": £" << Util::parseNumber(getPrice()) << ", " << Util::parseNumber(getCalories()) << " cal";
	return result.str();
}

ItemType MainCourse::getType() const
{
	return ItemType::MAIN_COURSE;
}