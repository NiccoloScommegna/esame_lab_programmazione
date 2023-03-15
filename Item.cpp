//
// Created by Niccoló Scommegna on 15/03/23.
//

#include "Item.h"

Item::Item(std::string name, std::string category, int quantity) {
    this->name = name;
    this->category = category;
    this->quantity = quantity;
}

Item::Item(std::string name, std::string category) {
    this->name = name;
    this->category = category;
}
