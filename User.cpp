//
// Created by Niccoló Scommegna on 15/03/23.
//

#include <iostream>
#include "User.h"

User::User(std::string name) {
    this->name = name;
}

void User::addShoppingList(const ShoppingList &shoppingList) {
    auto it = std::find(shoppingLists.begin(), shoppingLists.end(), shoppingList);
    if (it == shoppingLists.end())
        shoppingLists.push_back(shoppingList);
    else
        std::cout << "Shopping list already exists" << std::endl;
}

void User::removeShoppingList(const ShoppingList &shoppingList) {
    auto it = std::find(shoppingLists.begin(), shoppingLists.end(), shoppingList);
    if (it != shoppingLists.end())
        shoppingLists.erase(it);
    else
        std::cout << "Shopping list not found" << std::endl;
}

void User::removeShoppingList(const std::string &shoppingListName) {
    //TODO: da implementare
}

ShoppingList User::createShoppingList(const std::string &shoppingListName) {
    ShoppingList shoppingList(shoppingListName);
    addShoppingList(shoppingList);
    return shoppingList;
}

void User::showItemsList(const std::string &shoppingListName) const {
    bool found = false;
    for (auto it = shoppingLists.begin(); it != shoppingLists.end(); it++) {
        if (it->getName() == shoppingListName) {
            std::cout << "Items from the list " << it->getName() << std::endl;
            it->showItemsList();
            found = true;
        }
    }
    if (!found)
        std::cout << "Shopping list not found" << std::endl;
}

void User::addItemToShoppingList(const std::string &shoppingListName, const Item &item) {
    bool found = false;
    for (auto it = shoppingLists.begin(); it != shoppingLists.end(); it++) {
        if (it->getName() == shoppingListName) {
            it->addItem(item);
            found = true;
        }
    }
    if (!found)
        std::cout << "Shopping list not found" << std::endl;
}

void User::removeItemFromShoppingList(const std::string &shoppingListName, const Item &item) {
    bool found = false;
    for (auto it = shoppingLists.begin(); it != shoppingLists.end(); it++) {
        if (it->getName() == shoppingListName) {
            it->removeItem(item);
            found = true;
        }
    }
    if (!found)
        std::cout << "Shopping list not found" << std::endl;
}

void User::decreaseItemQuantity(const std::string &shoppingListName, Item &item) {
    bool found = false;
    for (auto it = shoppingLists.begin(); it != shoppingLists.end(); it++) {
        if (it->getName() == shoppingListName) {
            it->decreaseItemQuantity(item);
            found = true;
        }
    }
    if (!found)
        std::cout << "Shopping list not found" << std::endl;
}

void User::increaseItemQuantity(const std::string &shoppingListName, Item &item) {
    bool found = false;
    for (auto it = shoppingLists.begin(); it != shoppingLists.end(); it++) {
        if (it->getName() == shoppingListName) {
            it->increaseItemQuantity(item);
            found = true;
        }
    }
    if (!found)
        std::cout << "Shopping list not found" << std::endl;
}

/*
void User::addItemToShoppingList(std::string shoppingListName, Item *item) {
    for (std::list<ShoppingList *>::iterator it = shoppingLists.begin(); it != shoppingLists.end(); it++) {
        if ((*it)->getName() == shoppingListName) {
            (*it)->addItem(item);
        }
    }
}

void User::removeItemFromShoppingList(std::string shoppingListName, Item *item) {
    for (std::list<ShoppingList *>::iterator it = shoppingLists.begin(); it != shoppingLists.end(); it++) {
        if ((*it)->getName() == shoppingListName) {
            (*it)->removeItem(item);
        }
    }
}

void User::decreaseItemQuantity(std::string shoppingListName, Item *item) {
    for (std::list<ShoppingList *>::iterator it = shoppingLists.begin(); it != shoppingLists.end(); it++) {
        if ((*it)->getName() == shoppingListName) {
            (*it)->decreaseItemQuantity(item);
        }
    }
}

void User::increaseItemQuantity(std::string shoppingListName, Item *item) {
    for (std::list<ShoppingList *>::iterator it = shoppingLists.begin(); it != shoppingLists.end(); it++) {
        if ((*it)->getName() == shoppingListName) {
            (*it)->increaseItemQuantity(item);
        }
    }
}

 */