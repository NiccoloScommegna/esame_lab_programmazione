//
// Created by Niccoló Scommegna on 15/03/23.
//

#ifndef ESAME_LAB_PROGRAMMAZIONE_SHOPPINGLIST_H
#define ESAME_LAB_PROGRAMMAZIONE_SHOPPINGLIST_H


#include <string>
#include <list>
#include "Item.h"

class ShoppingList {
private:
    std::string name;
    std::list<Item *> itemsList;

public:
    explicit ShoppingList(std::string name);

    void addItem(Item *item);

    void removeItem(Item *item);

    //TODO: metodo che mostra la lista degli item

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &newName) {
        ShoppingList::name = newName;
    }

};


#endif //ESAME_LAB_PROGRAMMAZIONE_SHOPPINGLIST_H
