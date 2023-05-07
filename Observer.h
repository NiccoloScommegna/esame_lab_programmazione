//
// Created by Niccoló Scommegna on 22/03/23.
//

#ifndef ESAME_LAB_PROGRAMMAZIONE_OBSERVER_H
#define ESAME_LAB_PROGRAMMAZIONE_OBSERVER_H

class ShoppingList;

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update(ShoppingList *newList, const std::string &msg) = 0;
};

#endif //ESAME_LAB_PROGRAMMAZIONE_OBSERVER_H
