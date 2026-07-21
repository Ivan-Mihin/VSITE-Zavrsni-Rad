#pragma once

#include "IObserver.h"

class ManagerScore : public IObserver
{
private:
    int score = 0;
    int lines_cleared = 0;

public:
    void onNotify(GameEvent event) override;

    int getScore() const;
    int getLinesCleared() const;

    void addScore(int value);
};