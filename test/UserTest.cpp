//
// Created by Niccoló Scommegna on 28/03/23.
//
#include "gtest/gtest.h"
#include "../User.h"

TEST(User, Constructor) {
    User user("Niccolo");
    ASSERT_EQ(user.getName(), "Niccolo");
    ASSERT_EQ(user.getShoppingListsSize(), 0);
}

TEST(User, InvalidNameConstructor) {
    ASSERT_ANY_THROW(User user(""));
}

TEST(User, AddList) {
    User user("Niccolo");
    ShoppingList shoppingList("Lista della spesa");
    user.addShoppingList(&shoppingList);
    ASSERT_EQ(user.getShoppingListsSize(), 1);
    ASSERT_EQ(user.getShoppingList(&shoppingList), &shoppingList);
}

TEST(User, AddListAlreadyPresent) {
    User user("Niccolo");
    ShoppingList shoppingList("Lista della spesa");
    user.addShoppingList(&shoppingList);
    ASSERT_ANY_THROW(user.addShoppingList(&shoppingList));
}

TEST(User, RemoveList) {
    User user("Niccolo");
    ShoppingList shoppingList("Lista della spesa");
    user.addShoppingList(&shoppingList);
    user.removeShoppingList(&shoppingList);
    ASSERT_EQ(user.getShoppingListsSize(), 0);
}

TEST(User, RemoveListNotPresent) {
    User user("Niccolo");
    ShoppingList shoppingList("Lista della spesa");
    ASSERT_ANY_THROW(user.removeShoppingList(&shoppingList));
}

TEST(User, Update) {
    User user("Niccolo");
    ShoppingList shoppingList("Lista della spesa");
    Item item("Salmone", "Pesce", 5);
    user.addShoppingList(&shoppingList);
    testing::internal::CaptureStdout();
    shoppingList.addItem(item);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output,
              "Hi Niccolo, an item has been added to the list Lista della spesa\nLista della spesa  Total items: 1  Items already bought: 0\n\n");
}