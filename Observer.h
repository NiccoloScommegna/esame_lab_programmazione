//
// Created by Niccoló Scommegna on 22/03/23.
//

#ifndef ESAME_LAB_PROGRAMMAZIONE_OBSERVER_H
#define ESAME_LAB_PROGRAMMAZIONE_OBSERVER_H

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update() = 0;

    virtual void attach() = 0;

    virtual void detach() = 0;

};

#endif //ESAME_LAB_PROGRAMMAZIONE_OBSERVER_H
