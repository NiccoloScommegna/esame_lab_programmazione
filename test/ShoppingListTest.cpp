//
// Created by Niccoló Scommegna on 28/03/23.
//
#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../User.h"

TEST(ShoppingList, Constructor) {
    ShoppingList shoppingList("Lista della spesa");
    ASSERT_EQ(shoppingList.getName(), "Lista della spesa");
    ASSERT_EQ(shoppingList.getNumberAllItems(), 0);
}

TEST(ShoppingList, InvalidNameConstructor) {
    ASSERT_ANY_THROW(ShoppingList shoppingList(""));
}

TEST(ShoppingList, AddItem) {
    ShoppingList shoppingList("Lista della spesa");
    Item item("Salmone", "Pesce", 5);
    shoppingList.addItem(item);
    ASSERT_EQ(shoppingList.getNumberAllItems(), 1);
    ASSERT_EQ(shoppingList.getItem(item), item);
}

TEST(ShoppingList, AddItemAlreadyPresent) {
    ShoppingList shoppingList("Lista della spesa");
    Item item("Salmone", "Pesce", 5);
    shoppingList.addItem(item);
    shoppingList.addItem(item);
    ASSERT_EQ(shoppingList.getNumberAllItems(), 1);
    ASSERT_EQ(shoppingList.getItem(item).getQuantity(), 10);
}

TEST(ShoppingList, RemoveItem) {
    ShoppingList shoppingList("Lista della spesa");
    Item item("Salmone", "Pesce", 5);
    shoppingList.addItem(item);
    shoppingList.removeItem(item);
    ASSERT_EQ(shoppingList.getNumberAllItems(), 0);
}

TEST(ShoppingList, RemoveItemNotPresent) {
    ShoppingList shoppingList("Lista della spesa");
    Item item("Salmone", "Pesce", 5);
    ASSERT_ANY_THROW(shoppingList.removeItem(item));
}

TEST(ShoppingList, BuyItem) {
    ShoppingList shoppingList("Lista della spesa");
    Item item("Salmone", "Pesce", 5);
    shoppingList.addItem(item);
    shoppingList.buyItem(item);
    ASSERT_EQ(shoppingList.getItem(item).isBought(), true);
}

TEST(ShoppingList, BuyItemException) {
    ShoppingList shoppingList("Lista della spesa");
    Item item("Salmone", "Pesce", 5);
    ASSERT_ANY_THROW(shoppingList.buyItem(item));   //Provo a comprare l'articolo quando non è presente nella lista
    shoppingList.addItem(item);
    shoppingList.buyItem(item);
    ASSERT_ANY_THROW(shoppingList.buyItem(item));   //Provo a comprare l'articolo quando è già stato comprato
}

TEST(ShoppingList, DecreaseItemQuantity) {
    ShoppingList shoppingList("Lista della spesa");
    Item item("Salmone", "Pesce", 5);
    shoppingList.addItem(item);
    shoppingList.decreaseItemQuantity(item);
    ASSERT_EQ(shoppingList.getNumberAllItems(), 1);
    ASSERT_EQ(shoppingList.getItem(item).getQuantity(), 4);
}

TEST(ShoppingList, DecreaseItemQuantityToZero) {
    ShoppingList shoppingList("Lista della spesa");
    Item item("Salmone", "Pesce", 1);
    shoppingList.addItem(item);
    shoppingList.decreaseItemQuantity(item);
    ASSERT_EQ(shoppingList.getNumberAllItems(), 0);
}

TEST(ShoppingList, IncreaseItemQuantity) {
    ShoppingList shoppingList("Lista della spesa");
    Item item("Salmone", "Pesce", 5);
    shoppingList.addItem(item);
    shoppingList.increaseItemQuantity(item);
    ASSERT_EQ(shoppingList.getNumberAllItems(), 1);
    ASSERT_EQ(shoppingList.getItem(item).getQuantity(), 6);
}

TEST(ShoppingList, ModifyQuantityOfItemNotPresent) {
    ShoppingList shoppingList("Lista della spesa");
    Item item("Salmone", "Pesce", 5);
    ASSERT_ANY_THROW(shoppingList.decreaseItemQuantity(item));
    ASSERT_ANY_THROW(shoppingList.increaseItemQuantity(item));
}

TEST(ShoppingList, EqualityOperator) {
    ShoppingList shoppingList1("Lista della spesa");
    ShoppingList shoppingList2("Lista della spesa");
    ShoppingList shoppingList3("Lista della spesa 2");
    ASSERT_TRUE(shoppingList1 == shoppingList2);
    ASSERT_FALSE(shoppingList1 == shoppingList3);
}

TEST(ShoppingList, SubscribeObserver) {
    ShoppingList shoppingList("Lista della spesa");
    Observer *observer = new User("Niccolo");
    shoppingList.subscribe(observer);
    ASSERT_EQ(shoppingList.getObserversListSize(), 1);
    ASSERT_EQ(shoppingList.getObserver(observer), observer);
}

TEST(ShoppingList, UnsubscribeObserver) {
    ShoppingList shoppingList("Lista della spesa");
    Observer *observer = new User("Niccolo");
    shoppingList.subscribe(observer);
    shoppingList.unsubscribe(observer);
    ASSERT_EQ(shoppingList.getObserversListSize(), 0);
}