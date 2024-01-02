//
// Created by olive on 27/12/2023.
//

#ifndef APP_ASSESSMENT_2_ITEMLIST_H
#define APP_ASSESSMENT_2_ITEMLIST_H

#include <string>
#include <vector>

#include "Item.h"

class ItemList {
public:

    ItemList();

    ~ItemList();

    [[nodiscard]] virtual std::string toString() const = 0;

protected:
    // Vector of pointers to instances of the Item class
    std::vector<Item*> itemList;
};


#endif //APP_ASSESSMENT_2_ITEMLIST_H
