//
// Created by Niccoló Scommegna on 28/03/23.
//
#include "gtest/gtest.h"
#include "../User.h"

TEST(User, Constructor) {
    User user("Niccolo");
    ASSERT_EQ(user.getName(), "Niccolo");
    ASSERT_EQ(user.getShoppingLists().size(), 0);
}

TEST(User, AddList) {
    User user("Niccolo");
    ShoppingList shoppingList("Lista della spesa");
    user.addShoppingList(shoppingList);
    ASSERT_EQ(user.getShoppingLists().size(), 1);
    ASSERT_EQ(user.getShoppingLists().back(), shoppingList);
}

TEST(User, AddListAlreadyPresent) {
    User user("Niccolo");
    ShoppingList shoppingList("Lista della spesa");
    user.addShoppingList(shoppingList);
    user.addShoppingList(shoppingList);
    ASSERT_EQ(user.getShoppingLists().size(), 1);
}

TEST(User, RemoveList) {
    User user("Niccolo");
    ShoppingList shoppingList("Lista della spesa");
    user.addShoppingList(shoppingList);
    user.removeShoppingList(shoppingList);
    ASSERT_EQ(user.getShoppingLists().size(), 0);
}

TEST(User, Update) {
    User user1("Niccolo");
    User user2("Giovanni");
    ShoppingList shoppingList("Lista della spesa");
    user1.addShoppingList(shoppingList);
    user2.addShoppingList(shoppingList);
    Item item1("Salmone", "Pesce", 5);
    Item item2("Pepe", "Spezie");
    Item item3("Pomodori", "Verdura", 10);
    //Aggiunto i tre prodotti alla lista condivisa
    shoppingList.addItem(item1);
    shoppingList.addItem(item2);
    shoppingList.addItem(item3);
    std::list<Item> sharedListUser1 = user1.getItemsList("Lista della spesa");
    std::list<Item> sharedListUser2 = user2.getItemsList("Lista della spesa");
    ASSERT_EQ(sharedListUser1.size(), sharedListUser2.size());
    auto it1 = sharedListUser1.begin();
    auto it2 = sharedListUser2.begin();
    while (it1 != sharedListUser1.end()) {
        EXPECT_EQ(it1->isEquals(*it2), true);
        it1++;
        it2++;
    }
    //Modifico le quantità dei prodotti della lista condivisa
    shoppingList.increaseItemQuantity(item1);
    shoppingList.increaseItemQuantity(item2);
    shoppingList.decreaseItemQuantity(item3);
    sharedListUser1 = user1.getItemsList("Lista della spesa");
    sharedListUser2 = user2.getItemsList("Lista della spesa");
    ASSERT_EQ(sharedListUser1.size(), sharedListUser2.size());
    it1 = sharedListUser1.begin();
    it2 = sharedListUser2.begin();
    while (it1 != sharedListUser1.end()) {
        EXPECT_EQ(it1->isEquals(*it2), true);
        it1++;
        it2++;
    }
    //Rimuovo un prodotto dalla lista condivisa
    shoppingList.removeItem(item2);
    sharedListUser1 = user1.getItemsList("Lista della spesa");
    sharedListUser2 = user2.getItemsList("Lista della spesa");
    ASSERT_EQ(sharedListUser1.size(), sharedListUser2.size());
    it1 = sharedListUser1.begin();
    it2 = sharedListUser2.begin();
    while (it1 != sharedListUser1.end()) {
        EXPECT_EQ(it1->isEquals(*it2), true);
        it1++;
        it2++;
    }
}