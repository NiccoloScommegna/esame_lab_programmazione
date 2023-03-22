//
// Created by Niccoló Scommegna on 15/03/23.
//

#ifndef ESAME_LAB_PROGRAMMAZIONE_USER_H
#define ESAME_LAB_PROGRAMMAZIONE_USER_H


#include <string>
#include <list>
#include "ShoppingList.h"

class User {
private:
    std::string name;
    std::list<ShoppingList> shoppingLists;

public:
    explicit User(std::string name);

    ~User() = default;

    void addShoppingList(const ShoppingList &shoppingList);

    void removeShoppingList(const ShoppingList &shoppingList);

    void removeShoppingList(const std::string &shoppingListName);

    ShoppingList createShoppingList(const std::string &shoppingListName);

    void showItemsList(const std::string &shoppingListName) const;

    void addItemToShoppingList(const std::string &shoppingListName, const Item &item);

    void removeItemFromShoppingList(const std::string &shoppingListName, const Item &item);

    void decreaseItemQuantity(const std::string &shoppingListName, Item &item);

    void increaseItemQuantity(const std::string &shoppingListName, Item &item);

};


#endif //ESAME_LAB_PROGRAMMAZIONE_USER_H
