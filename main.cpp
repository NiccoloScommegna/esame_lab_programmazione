#include <iostream>
#include "Item.h"
#include "ShoppingList.h"
#include "User.h"

int main() {
    Item item1("Pasta", "Pasta", 1);
    Item item2("Sale", "Spezie");
    Item item3("Salmone", "Pesce", 2);

    Item item4("Pomodori", "Verdura", 3);
    Item item5("Prosciutto", "Salumi", 4);
    Item item6("Pane", "Pane", 5);

    Item item7("Latte", "Latticini", 6);
    Item item8("Uova", "Uova", 5);
    Item item9("Zucchine", "Verdura", 4);

    ShoppingList list1("Casa");
    ShoppingList list2("Compleanno");
    ShoppingList list3("Natale");

    User user1("Niccolo");
    User user2("Francesco");
    User user3("Chiara");

    list1.addItem(item1);
    list2.addItem(item4);
    list3.addItem(item7);

    user1.addShoppingList(list1);
    user2.addShoppingList(list1);
    user3.addShoppingList(list1);
    user1.addShoppingList(list2);
    user2.addShoppingList(list2);
    user3.addShoppingList(list2);
    user1.addShoppingList(list3);
    user2.addShoppingList(list3);
    user3.addShoppingList(list3);

    user1.showLists();
    user2.showLists();
    user3.showLists();

    list1.addItem(item2);
    list1.addItem(item3);

    user1.showItemsList("Casa");
    user2.showItemsList("Casa");
    user3.showItemsList("Casa");

    list2.addItem(item5);
    list2.addItem(item6);
    list3.addItem(item8);
    list3.addItem(item9);

    user1.showItemsList("Compleanno");
    user2.showItemsList("Compleanno");
    user3.showItemsList("Compleanno");

    user1.showItemsList("Natale");
    user2.showItemsList("Natale");
    user3.showItemsList("Natale");

    list1.removeItem(item1);
    list1.increaseItemQuantity(item2);
    list1.decreaseItemQuantity(item3);

    user1.showItemsList("Casa");
    user2.showItemsList("Casa");
    user3.showItemsList("Casa");

    list1.decreaseItemQuantity(item3);

    user1.showItemsList("Casa");
    user2.showItemsList("Casa");
    user3.showItemsList("Casa");

    user3.removeShoppingList(list1);

    list1.addItem(item1);
    list1.addItem(item2);

    user1.showItemsList("Casa");
    user2.showItemsList("Casa");
    user3.showItemsList("Casa");
    user3.showLists();

    return 0;
}
