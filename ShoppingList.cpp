//
// Created by Niccoló Scommegna on 15/03/23.
//

#include <iostream>
#include "ShoppingList.h"

ShoppingList::ShoppingList(std::string name) {
    this->name = name;
}

void ShoppingList::addItem(Item *item) {
    itemsList.push_back(item);
}

void ShoppingList::removeItem(Item *item) {
    itemsList.remove(item);
}

void ShoppingList::showItemsList() {
    for (std::list<Item *>::iterator it = itemsList.begin(); it != itemsList.end(); it++) {
        std::cout << (*it)->getName() << ": " << (*it)->getQuantity() << std::endl;
    }
}

void ShoppingList::decreaseItemQuantity(Item *item) {
    if (item->getQuantity() > 1) {
        item->setQuantity(item->getQuantity() - 1);
    } else if (item->getQuantity() == 1) {
        removeItem(item);
    } else {
        std::cout << "Error: item quantity is less than 1" << std::endl;
    }
}

void ShoppingList::increaseItemQuantity(Item *item) {
    item->setQuantity(item->getQuantity() + 1);
}