//
// Created by Oliver Whitehead on 30/12/2023.
//

#include <algorithm>
#include <fstream>
#include "Order.h"
#include "Appetiser.h"
#include "Util.h"

Order::Order() = default;

Order::~Order() = default;

std::string Order::toString() const {
    std::string orderString;

    orderString += "Order:\n";

    for(int i = 0; i < itemList.size(); i++) {
        orderString += std::to_string(i + 1) + ". " + itemList[i]->toString() + "\n";
    }

    orderString += "\nSavings: £" + Util::parseNumber(calculateSavings()) + "\n";
    orderString += "Total: £" + Util::parseNumber(calculateTotal()) + "\n";

    return orderString;
}

/**
* @brief Calculates the total price of the order, respecting twoForOne offers in the order.
 * This method must ensure that only the cheapest eligible items are free.
*/
double Order::calculateTotal() const {
    double total = 0.0;

    std::vector<Item *> nonTwoForOneItems;
    std::vector<Item *> twoForOneItems;

    for (Item *item: itemList) {

        if(item->getType() == ItemType::APPETISER) {
            if(dynamic_cast<Appetiser *>(item)->isTwoForOne()) {
                twoForOneItems.push_back(item);
                continue;
            }
        }

        nonTwoForOneItems.push_back(item);
    }

    for (Item *item: nonTwoForOneItems) {
        total += item->getPrice();
    }

    // Order the twoForOneItems by price
    std::sort(twoForOneItems.begin(), twoForOneItems.end(), [](Item *a, Item *b) {
        return a > b; // most expensive first
    });

    // Calculate how many two-for-one offers apply, and add the price of the expensive items to the total
    // For any without a pair, add the price to the total
    int twoForOneCount = twoForOneItems.size() / 2;
    for (int i = 0; i < twoForOneCount; i++) {
        total += twoForOneItems[i]->getPrice();
    }

    if (twoForOneItems.size() % 2 != 0) {
        total += twoForOneItems[twoForOneItems.size() - 1]->getPrice();
    }

    return total;
}

double Order::calculateRawTotal() const {
    double total = 0.0;

    for (Item *item: itemList) {
        total += item->getPrice();
    }

    return total;
}

double Order::calculateSavings() const {
    return calculateRawTotal() - calculateTotal();
}

void Order::printReceipt() const {
    std::ofstream receiptFile;
    receiptFile.open("receipt.txt");

    receiptFile << toString();

    receiptFile.close();
}

void Order::add(Item *item) {
    itemList.push_back(item);
}

void Order::remove(int position) {
    itemList.erase(itemList.begin() + position);
}

Item *Order::getItem(int position) const {
    if (position - 1 < itemList.size()) {
        return itemList[position - 1];
    } else {
        return nullptr;
    }
}