#include "Player.h"
#include "cmath"
#include "Bullet.h"

Player::Player(int x, int y, int initialFuel) : GameObject("assets/player/zu.png", "player")
{
    destinationRect.x = x;
    destinationRect.y = y;
    fuel = initialFuel;
};

void Player::setFuel( int wasted) {
    fuel = wasted;
}

int Player::getFuel(void) {
    return fuel;
}

void Player::setEmptyFuel(bool empt) {
    fuelEmpty = empt;
}

void Player::removeFuel() {
    if(getFuel() <= 0) {
        setEmptyFuel(true);
    }
    else{
        setFuel(getFuel() - 10);
    }
}


void Player::control(Player *player) {
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if(fuelEmpty == true){
        cout<<"NO MORE FUEL"<<endl;
        return;
    }
    else if(state[SDL_SCANCODE_W]) {
        player->removeFuel();
        player->move(0,-3);
        setDir(UP);
        GameObject::changeTexture("assets/player/zu.png");
    }
    else if(state[SDL_SCANCODE_A]) {
        player->removeFuel();
        player->move(-3,0);
        setDir(LEFT);
        GameObject::changeTexture("assets/player/zl.png");
    }
    else if(state[SDL_SCANCODE_S]) {
        player->removeFuel();
        player->move(0,3);
        setDir(DOWN);
        GameObject::changeTexture("assets/player/zd.png");
    }
    else if(state[SDL_SCANCODE_D]) {
        player->removeFuel();
        player->move(3,0);
        setDir(RIGHT);
        GameObject::changeTexture("assets/player/zr.png");
    }
}
