#include "manager_score.h"

void ManagerScore::onNotify(GameEvent event)
{
    if (event == GameEvent::NoLinesCleared)
    {
        combo = 0;
        return;
    }

    ++combo;
    int points = 0;
 
    switch (event)
    {
    case GameEvent::LinesCleared_1:
        points = 100;
        break;
    case GameEvent::LinesCleared_2:
        points = 300;
        break;
    case GameEvent::LinesCleared_3:
        points = 500;
        break;
    case GameEvent::LinesCleared_4:
        points = 800;
        break;
    }

    addScore(points);

    if (combo >= 2)
    {
        addScore(50 * combo);
    }
}

int ManagerScore::getScore() const
{
    return score; 
}

int ManagerScore::getCombo() const
{
    return combo;
}

void ManagerScore::addScore(int value)
{
    score += value;
}

bool ManagerScore::isComboActive() const
{
    return combo >= 2;
}