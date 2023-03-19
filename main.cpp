#include <iostream>
#include "Item.h"
#include "ShoppingList.h"
#include "User.h"

int main() {
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


    return 0;
}
