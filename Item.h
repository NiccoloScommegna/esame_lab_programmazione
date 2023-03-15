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

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int newQuantity) {
        Item::quantity = newQuantity;
    }
};


#endif //ESAME_LAB_PROGRAMMAZIONE_ITEM_H
