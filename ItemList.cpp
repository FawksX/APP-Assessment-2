//
// Created by olive on 27/12/2023.
//

#include <iostream>
#include "ItemList.h"

ItemList::ItemList() = default;

ItemList::~ItemList() {
    for (Item* item : itemList) {
        delete item;
    }
}