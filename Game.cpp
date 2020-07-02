#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Player.h"
#include "Human.h"
#include "cmath"
#include <vector>
#include <utility>
#include <windows.h>



Map* map;
Player* player;
GameObject* b;
Bullet* bullet;
int bulletDirection;


SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

vector<Bullet*> bullets;
vector<Player*> players;
vector<Enemy*> enemies;


Game::Game()
{

}

Game::~Game()
{SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}


void Game::init(const char *title, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){

        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        }

        isRunning = true;
    }else {isRunning = false;}

    player = new Player(356,256, 1000);
    players.push_back(player);

    map = new Map();

}


void Game::handleEvents()
{

    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            delete bullet;
        case SDL_KEYDOWN:
                switch( event.key.keysym.sym ){
                    case SDLK_LEFT:

                        bulletDirection = 1;
                        break;
                    case SDLK_RIGHT:

                        bulletDirection = 2;
                        break;
                    case SDLK_UP:
                        bulletDirection = 3;
                        break;
                    case SDLK_DOWN:
                        bulletDirection = 4;
                        break;
                    default:
                        break;
    }
}

}


void Game::update()
{
    player->update();
    player->control(player);
    //e->bulletCollision(e, bullet, objects);
}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->DrawMap();
    player->render();
    SDL_RenderPresent(renderer);
}


Game::randNum()
//the parameters must be min = 3, max = 3;
{
int x = rand()%(798-1 + 1) + 1;
return x;

}




