//
// Created by Niccoló Scommegna on 15/03/23.
//

#ifndef ESAME_LAB_PROGRAMMAZIONE_USER_H
#define ESAME_LAB_PROGRAMMAZIONE_USER_H


#include <string>
#include <list>
#include "ShoppingList.h"
#include "Observer.h"

class User : public Observer {
private:
    std::string name;
    std::list<ShoppingList> shoppingLists;
    ShoppingList *subject = nullptr;    //Perché vorrei istaziare un oggetto di tipo User prima di aver creato
    //un oggetto di tipo ShoppingList
    //Dubbio: un User può avere più ShoppingList condivise?

public:
    explicit User(std::string name);

    virtual ~User();

    void addShoppingList(const ShoppingList &shoppingList);

    void removeShoppingList(const ShoppingList &shoppingList);

    void removeShoppingList(const std::string &shoppingListName);

    ShoppingList createShoppingList(const std::string &shoppingListName);

    void showItemsList(const std::string &shoppingListName) const;

    void addItemToShoppingList(const std::string &shoppingListName, const Item &item);

    void removeItemFromShoppingList(const std::string &shoppingListName, const Item &item);

    void decreaseItemQuantity(const std::string &shoppingListName, Item &item);

    void increaseItemQuantity(const std::string &shoppingListName, Item &item);

    void update() override;

    void attach() override;

    void detach() override;

};


#endif //ESAME_LAB_PROGRAMMAZIONE_USER_H
