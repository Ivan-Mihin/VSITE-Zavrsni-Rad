#pragma once

enum class GameEvent
{
    NoLinesCleared,
    LinesCleared_1,
    LinesCleared_2,
    LinesCleared_3,
    LinesCleared_4
};

class IObserver
{
public:
    virtual ~IObserver() = default;
    virtual void onNotify(GameEvent event) = 0;
};