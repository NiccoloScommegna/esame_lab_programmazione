//
// Created by Niccoló Scommegna on 15/03/23.
//

#ifndef ESAME_LAB_PROGRAMMAZIONE_SHOPPINGLIST_H
#define ESAME_LAB_PROGRAMMAZIONE_SHOPPINGLIST_H


#include <string>
#include <list>
#include "Item.h"
#include "Subject.h"

class ShoppingList : public Subject {
private:
    std::string name;
    std::list<Item> itemsList;
    std::list<Observer *> observers;

public:
    explicit ShoppingList(const std::string &name);

    virtual ~ShoppingList() = default;

    void addItem(const Item &item);

    void removeItem(const Item &item);

    void buyItem(const Item &item);

    void showItemsList() const;

    void decreaseItemQuantity(Item &item);

    void increaseItemQuantity(Item &item);

    int getNumberItemsBought() const;

    int getNumberAllItems() const {
        return itemsList.size();
    }

    const std::string &getName() const {
        return name;
    }

    Item getItem(const Item &item) {
        auto it = std::find(itemsList.begin(), itemsList.end(), item);
        return (*it);
    }

    int getObserversListSize() const {
        return observers.size();
    }

    Observer *getObserver(const Observer *observer) {
        auto it = std::find(observers.begin(), observers.end(), observer);
        return (*it);
    }

    bool operator==(const ShoppingList &right) const {
        return name == right.name;
    }

    void subscribe(Observer *o) override;

    void unsubscribe(Observer *o) override;

    void notify(const std::string &msg) override;

};


#endif //ESAME_LAB_PROGRAMMAZIONE_SHOPPINGLIST_H
