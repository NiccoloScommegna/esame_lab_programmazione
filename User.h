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
    std::list<ShoppingList *> shoppingLists;

public:
    explicit User(std::string name);

    ~User() = default;

    void addShoppingList(ShoppingList *shoppingList);

    void removeShoppingList(ShoppingList *shoppingList);
    //void removeShoppingList(std::string shoppingListName);

    void createShoppingList(std::string shoppingListName);

    void addItemToShoppingList(std::string shoppingListName, Item *item);

    void removeItemFromShoppingList(std::string shoppingListName, Item *item);

    void decreaseItemQuantity(std::string shoppingListName, Item *item);

    void increaseItemQuantity(std::string shoppingListName, Item *item);

    bool showItemsList(std::string shoppingListName);

};


#endif //ESAME_LAB_PROGRAMMAZIONE_USER_H
