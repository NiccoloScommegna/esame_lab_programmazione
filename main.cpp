#include <iostream>
#include "Item.h"
#include "ShoppingList.h"
#include "User.h"

int main() {
    //Creo gli articoli
    Item item1("Pasta", "Pasta", 1);
    Item item2("Sale", "Spezie");
    Item item3("Salmone", "Pesce", 2);

    Item item4("Pomodori", "Verdura", 3);
    Item item5("Prosciutto", "Salumi", 4);
    Item item6("Pane", "Pane", 5);

    Item item7("Latte", "Latticini", 6);
    Item item8("Uova", "Uova", 5);
    Item item9("Zucchine", "Verdura", 4);

    //Creo le liste
    ShoppingList list1("Casa");
    ShoppingList list2("Compleanno");
    ShoppingList list3("Natale");

    //Creo gli utenti
    User user1("Niccolo");
    User user2("Francesco");
    User user3("Chiara");

    //Aggiungo i primi articoli alle liste
    list1.addItem(item1);
    list2.addItem(item4);
    list3.addItem(item7);

    //Aggiungo tutte le liste agli utenti
    user1.addShoppingList(&list1);
    user2.addShoppingList(&list1);
    user3.addShoppingList(&list1);
    user1.addShoppingList(&list2);
    user2.addShoppingList(&list2);
    user3.addShoppingList(&list2);
    user1.addShoppingList(&list3);
    user2.addShoppingList(&list3);
    user3.addShoppingList(&list3);

    //Ogni utente stampa i nomi di tutte le sue liste
    std::cout << "1) Ogni utente stampa i nomi di tutte le sue liste" << std::endl;
    user1.showLists();
    user2.showLists();
    user3.showLists();

    //Aggiungo altri articoli alla lista 1 che è quella con nome Casa
    list1.addItem(item2);
    list1.addItem(item3);

    //Ogni utente stampa la sua lista Casa e verifica che siano uguali
    std::cout << "2) Ogni utente stampa la sua lista Casa e verifica che siano uguali" << std::endl;
    user1.showItemsList("Casa");
    user2.showItemsList("Casa");
    user3.showItemsList("Casa");

    //Aggiungo i restanti articoli alle altre liste, lista 2 ha nome Compleanno e lista 3 ha nome Natale
    list2.addItem(item5);
    list2.addItem(item6);
    list3.addItem(item8);
    list3.addItem(item9);

    //Ogni utente stampa la lista Compleanno e verifica che siano uguali
    std::cout << "3) Ogni utente stampa la lista Compleanno e verifica che siano uguali" << std::endl;
    user1.showItemsList("Compleanno");
    user2.showItemsList("Compleanno");
    user3.showItemsList("Compleanno");

    //Ogni utente stampa la lista Natale e verifica che siano uguali
    std::cout << "4) Ogni utente stampa la lista Natale e verifica che siano uguali" << std::endl;
    user1.showItemsList("Natale");
    user2.showItemsList("Natale");
    user3.showItemsList("Natale");

    //Modifico la lista 1 che ha nome Casa
    list1.removeItem(item1);    //Rimuovo l'articolo 1 che è la pasta
    list1.increaseItemQuantity(item2);  //Aumento la quantità dell'articolo 2 che è il sale, aveva quantità 1 e ora ha 2
    list1.decreaseItemQuantity(item3);  //Decremento la quantità dell'articolo 3 che è il salmone, aveva quantità 2 e ora ha 1

    //Ogni utente stampa la sua lista Casa e verifica che siano uguali
    std::cout << "5) Ogni utente stampa la sua lista Casa e verifica che siano uguali" << std::endl;
    user1.showItemsList("Casa");
    user2.showItemsList("Casa");
    user3.showItemsList("Casa");

    //Decremento l'articolo 3 che ha quantità 1 e quindi viene eliminato
    list1.decreaseItemQuantity(item3);

    //Ogni utente stampa la sua lista Casa e verifica che siano uguali
    std::cout << "6) Ogni utente stampa la sua lista Casa e verifica che siano uguali" << std::endl;
    user1.showItemsList("Casa");
    user2.showItemsList("Casa");
    user3.showItemsList("Casa");

    //L'utente 3 rimuove la lista 1 che ha nome Casa dalle proprie liste della spesa
    user3.removeShoppingList(&list1);

    //Aggiungo articoli alla lista 1 che ha nome Casa
    list1.addItem(item1);
    list1.addItem(item2);

    //Ogni utente stampa la sua lista Casa e verifica che per l'utente 1 e l'utente 2 siano uguali
    //mentre per l'utente 3 non deve più ricevere gli aggiornamnti perché ha rimosso la lista 1
    std::cout << "7) Ogni utente stampa la sua lista Casa e verifica che per l'utente 1 e l'utente 2 siano uguali" << std::endl;
    std::cout << "mentre per l'utente 3 non deve più ricevere gli aggiornamnti perché ha rimosso la lista 1"
              << std::endl;
    user1.showItemsList("Casa");
    user2.showItemsList("Casa");
    user3.showItemsList("Casa");

    //Per ulterirore verifica l'utente 3 stampa le sue liste e verifica che non ci sia più la lista 1
    std::cout << "8) Per ulterirore verifica l'utente 3 stampa le sue liste e verifica che non ci sia più la lista 1"
              << std::endl;
    user3.showLists();

    std::cout << "9) Uso il metodo per comprare un articolo e vedere come la lista viene modificata" << std::endl;
    list2.buyItem(item4);

    return 0;
}
