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
    std::list<ShoppingList *> shoppingLists;

public:
    explicit User(const std::string &name);

    virtual ~User();

    void addShoppingList(ShoppingList *shoppingList);

    void removeShoppingList(ShoppingList *shoppingList);

    void showLists() const;

    void showItemsList(const std::string &shoppingListName) const;

    void update(ShoppingList *newList, const std::string &msg) override;

    const std::string &getName() const {
        return name;
    }

    int getShoppingListsSize() const {
        return shoppingLists.size();
    }

    ShoppingList *getShoppingList(ShoppingList *shoppingList) {
        auto it = std::find(shoppingLists.begin(), shoppingLists.end(), shoppingList);
        return (*it);
    }

};


#endif //ESAME_LAB_PROGRAMMAZIONE_USER_H
