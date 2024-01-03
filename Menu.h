//
// Created by olive on 27/12/2023.
//

#ifndef APP_ASSESSMENT_2_MENU_H
#define APP_ASSESSMENT_2_MENU_H

#include "ItemList.h"

/**
 * @brief Represents a menu of Takeaway items.
 */
class Menu : public ItemList
{
 public:

	/**
	 * @brief Creates a new Menu instance from a file. This will parse the file
	 * and create instances of the Item based on the csv specification for the project.
	 * Any items which cannot be created will be displayed in the console, and skipped.
	 * @param filePath The path to the CSV file to parse
	 */
	explicit Menu(const std::string& filePath);

	// Destructor
	~Menu();

	/**
	 * @brief Creates a String representation of the Menu to be displayed to the user.
	 * This will display the name, price and calories of each item in the menu, and any
	 * specialist information for appetizers and beverages
	 * @return A string representation of the Menu to be displayed to the user
	 */
	[[nodiscard]] std::string toString() const override;

	/**
	 * @brief Gets the item at a specific index in the ItemList
	 * @param position The position of the item to get
	 * @return A pointer to the item at the specified position, or nullptr if the position is invalid
	 */
	[[nodiscard]] Item* getItem(int position) const;

	/**
	 * @brief Sorts the Items in the ItemList by price in ascending or descending order
	 * @param ascending if it should be sorted in ascending order, otherwise descending
	 */
	void sortByPrice(bool ascending = true);

 private:

	/**
	 * @brief Creates a new Item instance from the parameters provided.
	 * This will create an instance based on the ItemType provided
	 * @param itemType The ItemType of the item to create
	 * @param name The name of the Item
	 * @param price The price of the Item
	 * @param calories The calories of the Item
	 * @param params Any additional parameters, ie abv, volume, shareable, twoForOne
	 * @return A pointer to the new Item instance, or nullptr if the ItemType is invalid
	 */
	static Item* createItem(const ItemType itemType,
		const std::string& name,
		double price,
		double calories,
		const std::vector<std::string>& params);

};

#endif //APP_ASSESSMENT_2_MENU_H
