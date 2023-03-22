//
// Created by Niccoló Scommegna on 15/03/23.
//

#include <iostream>
#include "User.h"
/*
User::User(std::string name) {
    this->name = name;
}

void User::addShoppingList(ShoppingList *shoppingList) {
    shoppingLists.push_back(shoppingList);
}

void User::removeShoppingList(ShoppingList *shoppingList) {
    shoppingLists.remove(shoppingList);
}

void User::removeShoppingList(std::string shoppingListName) {
    for (auto it = listaProva.begin(); it != listaProva.end(); it++) {
        if (it->getName() == shoppingListName) {
            listaProva.remove(*it);
        }
    }
}

void User::createShoppingList(std::string shoppingListName) {
    ShoppingList *shoppingList = new ShoppingList(shoppingListName);
    addShoppingList(shoppingList);
}

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

bool User::showItemsList(std::string shoppingListName) {
    for (std::list<ShoppingList *>::iterator it = shoppingLists.begin(); it != shoppingLists.end(); it++) {
        if ((*it)->getName() == shoppingListName) {
            std::cout << "Items from the list " << (*it)->getName() << std::endl;
            (*it)->showItemsList();
            return true;
        }
    }
    std::cout << "Error: shopping list not found" << std::endl;
    return false;
}

 */