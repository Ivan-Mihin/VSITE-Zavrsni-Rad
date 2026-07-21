#include "manager_score.h"

void ManagerScore::onNotify(GameEvent event)
{
    switch (event)
    {
    case GameEvent::LinesCleared_1:
        addScore(100);
        break;
    case GameEvent::LinesCleared_2:
        addScore(300);
        break;
    case GameEvent::LinesCleared_3:
        addScore(500);
        break;
    case GameEvent::LinesCleared_4:
        addScore(800);
        break;
    }
}

int ManagerScore::getScore() const
{
    return score; 
}

void ManagerScore::addScore(int value)
{
    score += value;
}