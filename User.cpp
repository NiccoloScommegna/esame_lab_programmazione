//
// Created by Niccoló Scommegna on 15/03/23.
//

#include "User.h"

User::User(std::string name) {
    this->name = name;
}

void User::addShoppingList(ShoppingList *shoppingList) {
    shoppingLists.push_back(shoppingList);
}

void User::removeShoppingList(ShoppingList *shoppingList) {
    shoppingLists.remove(shoppingList);
}

void User::createShoppingList(std::string shoppingListName) {
    ShoppingList *shoppingList = new ShoppingList(shoppingListName);
    addShoppingList(shoppingList);
}

void User::addItemToShoppingList(std::string shoppingListName, Item *item) {
    for (std::list<ShoppingList *>::iterator it = shoppingLists.begin(); it != shoppingLists.end(); ++it) {
        if ((*it)->getName() == shoppingListName) {
            (*it)->addItem(item);
        }
    }
}

void User::removeItemFromShoppingList(std::string shoppingListName, Item *item) {
    for (std::list<ShoppingList *>::iterator it = shoppingLists.begin(); it != shoppingLists.end(); ++it) {
        if ((*it)->getName() == shoppingListName) {
            (*it)->removeItem(item);
        }
    }
}