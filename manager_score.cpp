#include "manager_score.h"

void ManagerScore::onNotify(GameEvent event)
{
    switch (event)
    {
    case GameEvent::LinesCleared_1:
        addScore(100);
        lines_cleared += 1;
        break;
    case GameEvent::LinesCleared_2:
        addScore(300);
        lines_cleared += 2;
        break;
    case GameEvent::LinesCleared_3:
        addScore(500);
        lines_cleared += 3;
        break;
    case GameEvent::LinesCleared_4:
        addScore(800);
        lines_cleared += 4;
        break;
    }
}

int ManagerScore::getScore() const
{
    return score; 
}

int ManagerScore::getLinesCleared() const
{
    return lines_cleared;
}

void ManagerScore::addScore(int value)
{
    score += value;
}