//
// Created by Niccoló Scommegna on 15/03/23.
//

#include <iostream>
#include "ShoppingList.h"

ShoppingList::ShoppingList(const std::string &name) {
    if (name.empty() == true){
        throw std::invalid_argument("Invalid name");
    } else{
        this->name = name;
    }
}

void ShoppingList::addItem(const Item &item) {
    auto it = std::find(itemsList.begin(), itemsList.end(), item);
    if (it == itemsList.end()) {
        itemsList.push_back(item);
        std::string msg = "an item has been added to the list ";
        notify(msg);
    } else {
        it->setQuantity(it->getQuantity() + item.getQuantity());
        std::string msg = "an item quantity has been changed from the list ";
        notify(msg);
    }
}

void ShoppingList::removeItem(const Item &item) {
    auto it = std::find(itemsList.begin(), itemsList.end(), item);
    if (it != itemsList.end()) {
        itemsList.erase(it);
        std::string msg = "an item was removed from the list ";
        notify(msg);
    } else
        throw std::out_of_range("Item is not listed");
}

void ShoppingList::buyItem(const Item &item) {
    auto it = std::find(itemsList.begin(), itemsList.end(), item);
    if (it != itemsList.end()){
        if (it->isBought() == false) {
            it->setBought(true);
            std::string msg = "an item was bought from the list ";
            notify(msg);
        } else
            throw std::logic_error("Item has already been bought");
    } else
        throw std::out_of_range("Item is not listed");
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
            std::string msg = "an item quantity has been changed from the list ";
            notify(msg);
        } else    //Quantity == 1
            removeItem(item);
    } else
        throw std::out_of_range("Item is not listed");
}

void ShoppingList::increaseItemQuantity(Item &item) {
    auto it = std::find(itemsList.begin(), itemsList.end(), item);
    if (it != itemsList.end()) {
        it->setQuantity(it->getQuantity() + 1);
        std::string msg = "an item quantity has been changed from the list ";
        notify(msg);
    } else
        throw std::out_of_range("Item is not listed");
}

int ShoppingList::getNumberItemsBought() const {
    int result = 0;
    for (auto it = itemsList.begin(); it != itemsList.end(); it++) {
        if (it->isBought() == true)
            result++;
    }
    return result;
}

void ShoppingList::subscribe(Observer *o) {
    observers.push_back(o);
}

void ShoppingList::unsubscribe(Observer *o) {
    observers.remove(o);
}

void ShoppingList::notify(const std::string &msg) {
    for (auto observer: observers) {
        observer->update(this, msg);
    }
}
