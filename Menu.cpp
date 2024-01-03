//
// Created by olive on 27/12/2023.
//

#include "Menu.h"
#include "Appetiser.h"
#include "Beverage.h"
#include "MainCourse.h"
#include "Util.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>

Menu::Menu(const std::string& filePath)
{

	std::ifstream file(filePath);
	std::string line;

	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::vector<std::string> itemResult;

		while (std::getline(iss, line, ','))
		{
			itemResult.push_back(line);
		}

		if (itemResult.size() < 4)
		{
			// Invalid item format, handle appropriately
			std::cerr << "Invalid item format: " << line << std::endl;
			continue;
		}

		ItemType itemType = Util::parseItemType(itemResult[0]);
		std::string name = itemResult[1];
		double price = std::stod(itemResult[2]);
		double calories = std::stod(itemResult[3]);

		Item* newItem = createItem(itemType, name, price, calories, itemResult);

		if (newItem)
		{
			itemList.push_back(newItem);
		}
		else
		{
			std::cerr << "Failed to create item: " << line << std::endl;
		}
	}

	// Order the list by Appetisers, Main Courses, Beverages
	std::sort(itemList.begin(), itemList.end(), [](Item* a, Item* b)
	{
	  return a->getType() < b->getType();
	});

}

Item* Menu::createItem(const ItemType itemType,
	const std::string& name,
	double price,
	double calories,
	const std::vector<std::string>& params)
{

	switch (itemType)
	{
	case ItemType::MAIN_COURSE:
		return new MainCourse(name, calories, price);

	case ItemType::APPETISER:
		return new Appetiser(
			name,
			calories,
			price,
			params[4] == "y",
			params[5] == "y"
		);

	case ItemType::BEVERAGE:
		return new Beverage(
			name,
			calories,
			price,
			Util::parseNumber(params[7], 0),
			Util::parseNumber(params[6], 0)
		);

	default:
		return nullptr;
	}
}

// Destroyed in ItemList... no need to worry for now
Menu::~Menu() = default;

std::string Menu::toString() const
{

	std::ostringstream result;

	// Item list is sorted appetisers, main courses, beverages, print out the list and insert headings when the type changes
	result << "Menu:\n";

	ItemType currentType;

	for (int i = 0; i < itemList.size(); i++)
	{
		Item* item = itemList[i];

		ItemType itemType = item->getType();

		if (itemType != currentType)
		{
			result << "\n";
			switch (itemType)
			{
			case ItemType::APPETISER:
				result << "Appetisers:\n";
				break;
			case ItemType::MAIN_COURSE:
				result << "Main Courses:\n";
				break;
			case ItemType::BEVERAGE:
				result << "Beverages:\n";
				break;
			default:
				break;
			}
			currentType = itemType;
		}

		result << i + 1 << ". " << item->toString() << "\n";
	}

	return result.str();

}

void Menu::sortByPrice(bool ascending)
{
	auto compareByCategoryAndPrice = [ascending](Item* a, Item* b)
	{

	  // first ensure we aren't going to swap the categories, then sort by price
	  if (a->getType() == b->getType())
	  {
		  return ascending ? (*a < *b) : (*a > *b);
	  }
	  else
	  {
		  return false; // don't swap categories
	  }

	};

	std::sort(itemList.begin(), itemList.end(), compareByCategoryAndPrice);
}

Item* Menu::getItem(int position) const
{
	if (position - 1 < itemList.size())
	{
		return itemList[position - 1];
	}
	else
	{
		return nullptr;
	}
}