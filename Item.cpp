//
// Created by Niccoló Scommegna on 15/03/23.
//

#include "Item.h"

Item::Item(const std::string &name, const std::string &category, int quantity) : quantity(quantity > 1 ? quantity : 1) {
    if (name.empty() == true || category.empty() == true){
        throw std::runtime_error("Invalid name");
    } else{
        this->name = name;
        this->category = category;
    }
}

Item::Item(const std::string &name, const std::string &category) {
    if (name.empty() == true || category.empty() == true){
        throw std::runtime_error("Invalid name");
    } else{
        this->name = name;
        this->category = category;
    }
}
