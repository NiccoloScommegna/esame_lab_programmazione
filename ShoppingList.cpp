//
// Created by Niccoló Scommegna on 15/03/23.
//

#include <iostream>
#include "ShoppingList.h"

ShoppingList::ShoppingList(const std::string &name) {
    this->name = name;
}

void ShoppingList::addItem(const Item &item) {
    auto it = std::find(itemsList.begin(), itemsList.end(), item);
    if (it == itemsList.end()) {
        itemsList.push_back(item);
        notify(*this);
    } else {
        it->setQuantity(it->getQuantity() + item.getQuantity());
        //std::cout << "Item is already on the list, now its new quantity is: " << it->getQuantity() << std::endl;
        notify(*this);
    }
}

void ShoppingList::removeItem(const Item &item) {
    auto it = std::find(itemsList.begin(), itemsList.end(), item);
    if (it != itemsList.end()) {
        itemsList.erase(it);
        notify(*this);
    } else
        std::cout << "Item not found" << std::endl;
}

void ShoppingList::buyItem(const Item &item) {
    auto it = std::find(itemsList.begin(), itemsList.end(), item);
    if (it != itemsList.end()){
        if (it->isBought() == false){
            it->setBought(true);
            notify(*this);
        } else
            std::cout << "Item has already been bought" << std::endl;
    } else
        std::cout << "Item not found" << std::endl;
}

void ShoppingList::showItemsList() const {
    for (auto it = itemsList.begin(); it != itemsList.end(); it++) {
        std::cout << it->getName() << " " << it->getQuantity();
        if (it->isBought() == false){
            std::cout << " da comprare" << std::endl;
        } else
            std::cout << " già comprato" << std::endl;
    }
}

void ShoppingList::decreaseItemQuantity(Item &item) {
    auto it = std::find(itemsList.begin(), itemsList.end(), item);
    if (it != itemsList.end()) {
        if (it->getQuantity() > 1) {
            it->setQuantity(it->getQuantity() - 1);
            notify(*this);
        } else    //Quantity == 1
            removeItem(item);
    } else
        std::cout << "Item not found" << std::endl;
}

int ShoppingList::getNumberItemsBought() const {
    int result = 0;
    for (auto it = itemsList.begin(); it != itemsList.end(); it++){
        if (it->isBought() == true)
            result++;
    }
    return result;
}


void ShoppingList::increaseItemQuantity(Item &item) {
    auto it = std::find(itemsList.begin(), itemsList.end(), item);
    if (it != itemsList.end()) {
        it->setQuantity(it->getQuantity() + 1);
        notify(*this);
    } else
        std::cout << "Item not found" << std::endl;
}

void ShoppingList::subscribe(Observer *o) {
    observers.push_back(o);
}

void ShoppingList::unsubscribe(Observer *o) {
    observers.remove(o);
}

void ShoppingList::notify(ShoppingList newList) {
    for (auto observer: observers) {
        observer->update(newList);
    }
}
