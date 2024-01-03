//
// Created by olive on 24/12/2023.
//

#include <iostream>
#include <utility>
#include "Item.h"

Item::Item(
	std::string itemName,
	double itemCalories,
	double itemPrice
) : name(std::move(itemName)), calories(itemCalories), price(itemPrice)
{

};

Item::~Item() = default;

std::string Item::getName() const
{
	return name;
}

double Item::getCalories() const
{
	return calories;
}

double Item::getPrice() const
{
	return price;
}

bool Item::operator>(const Item& other) const
{
	return price > other.price;
}

bool Item::operator<(const Item& other) const
{
	return price < other.price;
}

std::ostream& operator<<(std::ostream& os, const Item& item)
{
	os << item.toString();
	return os;
}
