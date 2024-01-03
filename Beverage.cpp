//
// Created by olive on 25/12/2023.
//

#include <sstream>
#include "Beverage.h"
#include "Util.h"

Beverage::Beverage(
	const std::string& itemName,
	double itemCalories,
	double itemPrice,
	double abv,
	double volume
) : Item(itemName, itemCalories, itemPrice), abv(abv), volume(volume)
{

}

Beverage::~Beverage() = default;

double Beverage::getAbv() const
{
	return abv;
}

double Beverage::getVolume() const
{
	return volume;
}

std::string Beverage::toString() const
{

	std::ostringstream result;

	result <<
		   getName() << ": £" << Util::parseNumber(getPrice()) << ", " <<
		   Util::parseNumber(getCalories()) << " cal (" <<
		   Util::parseNumber(getVolume()) << "ml";

	if (getAbv() > 0)
	{
		result << ", " << Util::parseNumber(getAbv()) << "% abv";
	}

	result << ")";

	return result.str();
}

ItemType Beverage::getType() const
{
	return ItemType::BEVERAGE;
}