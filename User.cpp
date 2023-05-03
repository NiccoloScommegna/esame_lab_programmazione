//
// Created by Niccoló Scommegna on 15/03/23.
//

#include <iostream>
#include "User.h"
User::User(const std::string &name) {
    if (name.empty() == true){
        throw std::runtime_error("Invalid name");
    } else{
        this->name = name;
    }
}

User::~User() {
    for (auto it = shoppingLists.begin(); it != shoppingLists.end(); it++) {
        it->unsubscribe(this);
    }
}

void User::addShoppingList(ShoppingList &shoppingList) {
    auto it = std::find(shoppingLists.begin(), shoppingLists.end(), shoppingList);
    if (it == shoppingLists.end()) {
        shoppingList.subscribe(this);
        shoppingLists.push_back(shoppingList);
    } else
        std::cout << "Shopping list already exists" << std::endl;
}

void User::removeShoppingList(ShoppingList &shoppingList) {
    auto it = std::find(shoppingLists.begin(), shoppingLists.end(), shoppingList);
    if (it != shoppingLists.end()) {
        shoppingList.unsubscribe(this);
        shoppingLists.erase(it);
    } else
        std::cout << "Shopping list not found" << std::endl;
}

void User::showLists() const {
    std::cout << "Here are the lists of: " << name << std::endl;
    for (auto it = shoppingLists.begin(); it != shoppingLists.end(); it++) {
        std::cout << it->getName() << std::endl;
    }
    std::cout << std::endl;
}

void User::showItemsList(const std::string &shoppingListName) const {
    bool found = false;
    for (auto it = shoppingLists.begin(); it != shoppingLists.end(); it++) {
        if (it->getName() == shoppingListName) {
            std::cout << "User: " << name << std::endl << "Items on the list: " << it->getName() << std::endl;
            it->showItemsList();
            found = true;
        }
    }
    if (!found)
        std::cout << "Shopping list not found" << std::endl;
    std::cout << std::endl;
}

void User::update(ShoppingList newList) {
    auto it = std::find(shoppingLists.begin(), shoppingLists.end(), newList);
    if (it != shoppingLists.end()) {
        it->unsubscribe(this);
        shoppingLists.erase(it);
        shoppingLists.push_back(newList);
        newList.subscribe(this);
    }
}

std::list<Item> User::getItemsList(const std::string &shoppingListName) const {
    for (auto it = shoppingLists.begin(); it != shoppingLists.end(); it++) {
        if (it->getName() == shoppingListName) {
            return it->getItemsList();
        }
    }
    std::cout << "Shopping list not found" << std::endl;
    return {};
}
