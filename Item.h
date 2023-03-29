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

public:
    Item(std::string name, std::string category, int quantity);

    Item(std::string name, std::string category);

    ~Item() = default;

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &newName) {
        Item::name = newName;
    }

    const std::string &getCategory() const {
        return category;
    }

    void setCategory(const std::string &category) {
        Item::category = category;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int newQuantity) {
        Item::quantity = newQuantity;
    }

    bool operator==(const Item &right) const {
        return name == right.name;
    }

    bool isEquals(const Item &right) const {
        return name == right.name && category == right.category && quantity == right.quantity;
    }

};


#endif //ESAME_LAB_PROGRAMMAZIONE_ITEM_H
