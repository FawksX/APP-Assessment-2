//
// Created by olive on 27/12/2023.
//

#ifndef APP_ASSESSMENT_2_ITEMLIST_H
#define APP_ASSESSMENT_2_ITEMLIST_H

#include <string>
#include <vector>

#include "Item.h"

/**
 * @brief Represents a list of takeaway items.
 */
class ItemList
{
 public:

	ItemList();

	~ItemList();

	/**
	 * @brief Represents a human-readable format of all the items in the list.
	 * @return A string representation of the list of items.
	 */
	[[nodiscard]] virtual std::string toString() const = 0;

 protected:
	// Vector of pointers to instances of the Item class
	std::vector<Item*> itemList;
};

#endif //APP_ASSESSMENT_2_ITEMLIST_H
