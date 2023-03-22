//
// Created by Niccoló Scommegna on 15/03/23.
//

#include <iostream>
#include "ShoppingList.h"

ShoppingList::ShoppingList(std::string name) {
    this->name = name;
}

void ShoppingList::addItem(const Item &item) {
    auto it = std::find(itemsList.begin(), itemsList.end(), item);
    if (it == itemsList.end())
        itemsList.push_back(item);
    else {
        it->setQuantity(it->getQuantity() + item.getQuantity());
        std::cout << "Item is already on the list, now its new quantity is: " << it->getQuantity() << std::endl;
    }
}

void ShoppingList::removeItem(const Item &item) {
    auto it = std::find(itemsList.begin(), itemsList.end(), item);
    if (it != itemsList.end())
        itemsList.erase(it);
    else
        std::cout << "Item not found" << std::endl;
}

void ShoppingList::removeItem(const std::string &itemName) {
    //TODO: da implementare
}

void ShoppingList::showItemsList() const {
    for (auto it = itemsList.begin(); it != itemsList.end(); it++) {
        std::cout << it->getName() << " " << it->getQuantity() << std::endl;
    }
}

void ShoppingList::decreaseItemQuantity(Item &item) {
    auto it = std::find(itemsList.begin(), itemsList.end(), item);
    if (it != itemsList.end()) {
        if (it->getQuantity() > 1)
            it->setQuantity(it->getQuantity() - 1);
        else    //Quantity == 1
            removeItem(item);
    } else
        std::cout << "Item not found" << std::endl;
}

void ShoppingList::increaseItemQuantity(Item &item) {
    auto it = std::find(itemsList.begin(), itemsList.end(), item);
    if (it != itemsList.end())
        it->setQuantity(it->getQuantity() + 1);
    else
        std::cout << "Item not found" << std::endl;
}

void ShoppingList::subscribe(Observer *o) {
    observers.push_back(o);
}

void ShoppingList::unsubscribe(Observer *o) {
    observers.remove(o);
}

void ShoppingList::notify() {
    for (auto observer: observers) {
        observer->update();
    }
}
