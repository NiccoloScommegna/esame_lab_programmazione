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

    void addShoppingList(ShoppingList *shoppingList);

    void removeShoppingList(ShoppingList *shoppingList);

    void createShoppingList(std::string shoppingListName);

    void addItemToShoppingList(std::string shoppingListName, Item *item);

    void removeItemFromShoppingList(std::string shoppingListName, Item *item);

    //TODO: metodo che diminuisce la quantità di un item in una shopping list
    //TODO: metodo che aumenta la quantità di un item in una shopping list
    //TODO: metodo che restituisce la lista degli item di una shopping list

};


#endif //ESAME_LAB_PROGRAMMAZIONE_USER_H
