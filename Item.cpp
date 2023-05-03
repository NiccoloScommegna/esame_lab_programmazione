//
// Created by Niccoló Scommegna on 15/03/23.
//

#include "Item.h"

Item::Item(const std::string &name, const std::string &category, int quantity) : quantity(quantity > 1 ? quantity : 1) {
    this->name = name;
    this->category = category;
}

Item::Item(const std::string &name, const std::string &category) {
    this->name = name;
    this->category = category;
}
