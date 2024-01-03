//
// Created by Oliver Whitehead on 02/01/2024.
//

#ifndef APP_ASSESSMENT_2_UTIL_H
#define APP_ASSESSMENT_2_UTIL_H

#include <string>
#include "ItemType.h"

/**
 * @brief A namespace containing utility methods for the Takeaway App
 */
namespace Util
{

	/**
	 * @brief Parses a number to a string with 2 decimal places
	 * @param num The number to parse
	 * @return The parsed number
	 */
	std::string parseNumber(double num);

	/**
	 * @brief Parses a string to an ItemType
	 * @param type The string to parse
	 * @return The parsed ItemType object
	 * @throws invalid_argument if the string is not a valid ItemType
	 */
	ItemType parseItemType(const std::string& type);

	/**
	 * @brief A utility method to reduce code duplication when parsing ints
	 * @param num The string to parse
	 * @param defaultNum The default number to return if the string is not a valid int
	 * @return The parsed int
	 */
	int parseNumber(const std::string& num, int defaultNum);
};

#endif //APP_ASSESSMENT_2_UTIL_H
