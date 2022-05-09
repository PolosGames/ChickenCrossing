#pragma once
#ifndef GAME_H_
#define GAME_H_

class Game
{
public:
    Game();

    void Update(float delta_time);
private:
    pl::int32 frame{};
};

#endif /* GAME_H_ */