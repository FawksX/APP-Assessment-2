//
// Created by olive on 24/12/2023.
//

#include <sstream>
#include "Appetiser.h"
#include "Util.h"

Appetiser::Appetiser(
	const std::string& itemName,
	double itemCalories,
	double itemPrice,
	bool shareable,
	bool twoForOne
) : Item(itemName, itemCalories, itemPrice), twoForOne(twoForOne), shareable(shareable)
{

}

Appetiser::~Appetiser() = default;

bool Appetiser::isShareable() const
{
	return shareable;
}

bool Appetiser::isTwoForOne() const
{
	return twoForOne;
}

std::string Appetiser::toString() const
{

	std::ostringstream result;

	result << getName() << ": £" << Util::parseNumber(getPrice()) << ", " << Util::parseNumber(getCalories()) << " cal";

	if (isShareable())
	{
		result << " (shareable) ";
	}

	if (isTwoForOne())
	{
		result << " (2-4-1)";
	}

	return result.str();
}

ItemType Appetiser::getType() const
{
	return ItemType::APPETISER;
}