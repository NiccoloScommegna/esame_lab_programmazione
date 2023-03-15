//
// Created by Niccoló Scommegna on 15/03/23.
//

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