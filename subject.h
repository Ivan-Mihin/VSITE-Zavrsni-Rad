#pragma once

#include "IObserver.h"

#include <vector>

class Subject
{
private:
    std::vector<IObserver*> observers;

protected:
    void notifyObservers(GameEvent event);

public:
    virtual ~Subject() = default;

    void addObserver(IObserver* observer);
    void removeObserver(IObserver* observer);
};