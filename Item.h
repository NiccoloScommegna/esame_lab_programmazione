//
// Created by Niccoló Scommegna on 15/03/23.
//

#ifndef ESAME_LAB_PROGRAMMAZIONE_ITEM_H
#define ESAME_LAB_PROGRAMMAZIONE_ITEM_H


#include <string>

class Item {
private:
    std::string name;
    std::string category;
    int quantity = 1;
    bool bought = false;

public:
    Item(const std::string &name, const std::string &category, int quantity);

    Item(const std::string &name, const std::string &category);

    ~Item() = default;

    const std::string &getName() const {
        return name;
    }


    const std::string &getCategory() const {
        return category;
    }


    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int newQuantity) {
        if (newQuantity > 0)
            Item::quantity = newQuantity;
        else
            Item::quantity = 1;
    }

    bool isBought() const {
        return bought;
    }

    void setBought(bool boughtStatus) {
        Item::bought = boughtStatus;
    }

    bool operator==(const Item &right) const {
        return name == right.name;
    }

    bool isEquals(const Item &right) const {
        return name == right.name && category == right.category && quantity == right.quantity;
    }

};


#endif //ESAME_LAB_PROGRAMMAZIONE_ITEM_H
