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
    int quantity = 1;   //TODO: devo controllare che il valore sia sempre maggiore di 0

public:
    Item(std::string name, std::string category, int quantity);

    Item(std::string name, std::string category);

    ~Item() = default;

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int newQuantity) {
        Item::quantity = newQuantity;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &newName) {
        Item::name = newName;
    }

    bool operator==(const Item &right) const {
        return name == right.name;
    }

};


#endif //ESAME_LAB_PROGRAMMAZIONE_ITEM_H
