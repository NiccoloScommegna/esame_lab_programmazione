//
// Created by Niccoló Scommegna on 22/03/23.
//

#ifndef ESAME_LAB_PROGRAMMAZIONE_SUBJECT_H
#define ESAME_LAB_PROGRAMMAZIONE_SUBJECT_H

#include "Observer.h"
class ShoppingList;

class Subject {
public:
    virtual ~Subject() = default;

    virtual void subscribe(Observer *o) = 0;

    virtual void unsubscribe(Observer *o) = 0;

    virtual void notify(ShoppingList *newList, const std::string &msg) = 0;
};

#endif //ESAME_LAB_PROGRAMMAZIONE_SUBJECT_H
