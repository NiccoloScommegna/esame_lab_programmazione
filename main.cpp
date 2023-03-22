#include <iostream>
#include "Item.h"
#include "ShoppingList.h"
#include "User.h"

int main() {
    ShoppingList sl = ShoppingList("Casa");
    Item item1 = Item("Spaghetti", "Pasta");
    Item item2 = Item("Latte", "Latticini", 2);
    Item item3 = Item("Pomodori", "Frutta e Verdura", 10);
    sl.addItem(item1);
    sl.addItem(item2);
    sl.addItem(item3);
    sl.showItemsList();
    sl.addItem(item1);
    sl.decreaseItemQuantity(item2);
    sl.showItemsList();
    sl.removeItem(item3);
    sl.showItemsList();

    std::cout << "-----------------------" << std::endl;

    User u = User("Niccoló");
    u.addShoppingList(sl);
    u.showItemsList("Casa");
    ShoppingList sl1 = u.createShoppingList("Natale");
    Item item4 = Item("Salmone", "Pesce", 2);
    Item item5 = Item("Panna", "Latticini", 1);
    u.addItemToShoppingList("Natale", item4);
    u.addItemToShoppingList("Natale", item5);
    u.showItemsList("Natale");
    u.decreaseItemQuantity("Natale", item4);
    u.showItemsList("Natale");
    u.removeItemFromShoppingList("Natale", item5);
    u.showItemsList("Natale");

    return 0;
}
