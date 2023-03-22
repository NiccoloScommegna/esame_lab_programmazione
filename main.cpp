#include <iostream>
#include "Item.h"
#include "ShoppingList.h"
#include "User.h"

int main() {
/*
    std::cout << "Creazione del primo utente e della prima lista" << std::endl;
    User niccolo("Niccoló");
    niccolo.createShoppingList("Casa");
    niccolo.addItemToShoppingList("Casa", new Item("Spaghetti", "Pasta"));
    niccolo.addItemToShoppingList("Casa", new Item("Latte", "Latticini", 2));
    niccolo.addItemToShoppingList("Casa", new Item("Pomodori", "Frutta e Verdura", 10));
    niccolo.addItemToShoppingList("Casa", new Item("Gelato", "Surgelati", 2));
    niccolo.showItemsList("Casa");
    std::cout << std::endl;

    std::cout << "Creazione di un articolo e di una lista, aggiunta della lista nella lista delle liste dell'utente"
              << std::endl;
    Item *pollo = new Item("Pollo", "Carne", 1);
    ShoppingList *compleanno = new ShoppingList("Compleanno");
    compleanno->addItem(pollo);
    niccolo.addShoppingList(compleanno);
    niccolo.showItemsList("Compleanno");
    std::cout << std::endl;

    std::cout << "Semplici test su alcuni metodi della classe User" << std::endl;
    niccolo.showItemsList("Ufficio");
    niccolo.increaseItemQuantity("Compleanno", pollo);
    niccolo.showItemsList("Compleanno");
    niccolo.decreaseItemQuantity("Compleanno", pollo);
    niccolo.showItemsList("Compleanno");
    niccolo.removeItemFromShoppingList("Compleanno", pollo);
    niccolo.showItemsList("Compleanno");
    Item *prosciutto = new Item("Prosciutto", "Salumi");
    niccolo.addItemToShoppingList("Compleanno", prosciutto);
    niccolo.showItemsList("Compleanno");
    niccolo.decreaseItemQuantity("Compleanno", prosciutto);
    niccolo.showItemsList("Compleanno");
    niccolo.removeShoppingList(compleanno);
    niccolo.showItemsList("Compleanno");

    std::cout << std::endl;
    std::cout << "Test sui metodi della classe User con possibilità di usate il nome dell'articolo" << std::endl;
    //niccolo.showItemsList("Casa");
    //niccolo.removeShoppingList("Casa");
    //TODO non funziona il metodo removeShoppingList(std::string shoppingListName) e c'è da gestire il caso
    // in cui eliminata la lista vanno eliminati anche gli artioli
    //niccolo.showItemsList("Casa");
    Item latte("Latte", "Latticini", 2);
    niccolo.createShoppingList("Natale");
    niccolo.addItemToShoppingList("Natale", &latte);
    niccolo.showItemsList("Natale");
*/
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


    return 0;
}
