//
// Created by Niccoló Scommegna on 28/03/23.
//
#include "gtest/gtest.h"
#include "../Item.h"

TEST(Item, Constructor) {
    Item item("Salmone", "Pesce", 5);
    ASSERT_EQ(item.getName(), "Salmone");
    ASSERT_EQ(item.getCategory(), "Pesce");
    ASSERT_EQ(item.getQuantity(), 5);
    ASSERT_EQ(item.isBought(), false);
}

TEST(Item, InvalidNameConstructor) {
    ASSERT_THROW(Item item("", "Pesce", 5), std::invalid_argument);
    ASSERT_THROW(Item item("Salmone", "", 5), std::invalid_argument);
    ASSERT_THROW(Item item("", "", 5), std::invalid_argument);
}

TEST(Item, DefaultQuantity) {
    Item item("Pepe", "Spezie");
    ASSERT_EQ(item.getQuantity(), 1);
}

TEST(Item, ConstructorWithNegativeQuantity) {
    Item item("Salmone", "Pesce", -5);
    ASSERT_EQ(item.getQuantity(), 1);
}

TEST(Item, EqualityOperator) {
    Item item1("Salmone", "Pesce", 5);
    Item item2("Salmone", "Pesce", 2);
    Item item3("Pepe", "Spezie");
    ASSERT_TRUE(item1 == item2);
    ASSERT_FALSE(item1 == item3);
}