//
// Created by Niccoló Scommegna on 15/03/23.
//

#include <iostream>
#include "User.h"
User::User(const std::string &name) {
    if (name.empty() == true){
        throw std::invalid_argument("Invalid name");
    } else{
        this->name = name;
    }
}

User::~User() {
    for (auto it = shoppingLists.begin(); it != shoppingLists.end(); it++) {
        (*it)->unsubscribe(this);
    }
}

void User::addShoppingList(ShoppingList *shoppingList) {
    auto it = std::find(shoppingLists.begin(), shoppingLists.end(), shoppingList);
    if (it == shoppingLists.end()) {
        shoppingList->subscribe(this);
        shoppingLists.push_back(shoppingList);
    } else
        throw std::logic_error("Shopping list already exists");
}

void User::removeShoppingList(ShoppingList *shoppingList) {
    auto it = std::find(shoppingLists.begin(), shoppingLists.end(), shoppingList);
    if (it != shoppingLists.end()) {
        shoppingList->unsubscribe(this);
        shoppingLists.erase(it);
    } else
        throw std::out_of_range("Shopping list not found");
}

void User::showLists() const {
    std::cout << "Here are the lists of: " << name << std::endl;
    for (auto it = shoppingLists.begin(); it != shoppingLists.end(); it++) {
        std::cout << (*it)->getName() << "  Total items: " << (*it)->getNumberAllItems() << "  Items already bought: "
                  << (*it)->getNumberItemsBought() << std::endl;
    }
    std::cout << std::endl;
}

void User::showItemsList(const std::string &shoppingListName) const {
    bool found = false;
    for (auto it = shoppingLists.begin(); it != shoppingLists.end(); it++) {
        if ((*it)->getName() == shoppingListName) {
            std::cout << "User: " << name << std::endl << "Items on the list: " << (*it)->getName() << std::endl;
            (*it)->showItemsList();
            found = true;
        }
    }
    if (!found)
        std::cout << "Shopping list not found" << std::endl;
    std::cout << std::endl;
}

void User::update(ShoppingList *newList, const std::string &msg) {
    auto it = std::find(shoppingLists.begin(), shoppingLists.end(), newList);
    if (it != shoppingLists.end()) {
        std::cout << "Hi " + User::name + ", " << msg << (*it)->getName() << std::endl;
        std::cout << (*it)->getName() << "  Total items: " << (*it)->getNumberAllItems() << "  Items already bought: "
                  << (*it)->getNumberItemsBought() << std::endl;
    } else
        throw std::out_of_range("Shopping list not found");
    std::cout << std::endl;
}
