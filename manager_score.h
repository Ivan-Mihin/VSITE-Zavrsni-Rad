#pragma once

#include "IObserver.h"

class ManagerScore : public IObserver
{
private:
    int score = 0;
    int combo = 0;

public:
    void onNotify(GameEvent event) override;

    int getScore() const;
    int getCombo() const;

    void addScore(int value);
    bool isComboActive() const;
};