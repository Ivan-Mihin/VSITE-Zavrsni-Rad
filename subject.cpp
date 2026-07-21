#include "subject.h"

#include <algorithm>
#include <vector>

void Subject::notifyObservers(GameEvent event)
{
    for (int i = 0; i < observers.size(); ++i)
    {
        observers[i]->onNotify(event);
    }
}

void Subject::addObserver(IObserver* observer)
{
    if (observer)
    {
        observers.push_back(observer);
    }
}

void Subject::removeObserver(IObserver* observer)
{
    observers.erase(std::remove(observers.begin(), observers.end(), observer),observers.end());
}