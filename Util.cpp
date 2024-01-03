//
// Created by Oliver Whitehead on 02/01/2024.
//

#include <ios>
#include <iomanip>

#include "Util.h"

std::string Util::parseNumber(double num)
{
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << num;
	std::string s = stream.str();
	return s;
}

ItemType Util::parseItemType(const std::string& type)
{
	if (type == "a")
	{
		return ItemType::APPETISER;
	}
	else if (type == "m")
	{
		return ItemType::MAIN_COURSE;
	}
	else if (type == "b")
	{
		return ItemType::BEVERAGE;
	}
	else
	{
		throw std::invalid_argument("Invalid item type");
	}
}

int Util::parseNumber(const std::string& num, int defaultNum)
{
	try
	{
		return std::stoi(num);
	}
	catch (std::invalid_argument& e)
	{
		return defaultNum;
	}
}