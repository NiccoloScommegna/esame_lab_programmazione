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
    std::list<Item> itemsList;

public:
    explicit ShoppingList(std::string name);

    ~ShoppingList() = default;

    void addItem(const Item &item);

    void removeItem(const Item &item);

    void removeItem(const std::string &itemName);

    void showItemsList() const;

    void decreaseItemQuantity(Item &item);

    void increaseItemQuantity(Item &item);

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &newName) {
        ShoppingList::name = newName;
    }

    bool operator==(const ShoppingList &right) const {
        return name == right.name;
    }

};


#endif //ESAME_LAB_PROGRAMMAZIONE_SHOPPINGLIST_H
