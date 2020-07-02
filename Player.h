#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "GameObject.h"
#include "Enemy.h"
#include "Bullet.h"
#include <vector>

enum playerDirection{UP, DOWN, LEFT, RIGHT};

class Player : public GameObject {
public:
    Player(int x, int y, int fuel);
    void control(Player *player);
    bool checkCollision(Player *a);

    bool onFuelStation(bool);

    void removeFuel();
    void setFuel( int wasted );
    int getFuel(void);

    void setEmptyFuel( bool empt);
    bool getEmptyFuel (bool);

    playerDirection getDir() {return curD;}
    void setDir(playerDirection dir) {curD = dir;}
    playerDirection changeDirection(Player *p);
    ~Player();
private:
    playerDirection curD;
    int fuel;
    bool fuelEmpty;


};


#endif // PLAYER_H_INCLUDED
