#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "screen.h"
#include "graphic.h"
#include "move.h"
#include "press.h"

using namespace std;

int main(int argc, char *argv[])
{
    SDL_Window* window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Renderer* renderer = createRenderer(window);

    SDL_SetRenderDrawColor(renderer, 173, 216, 230, 255);
    SDL_RenderClear(renderer);

    int playerX = 40;
    int playerY = 0;


    SDL_Texture* hide = loadTexture("img/backgr.jpg", renderer);
    renderTexture(hide, 0, 0, 40, 40, renderer);


    SDL_Texture* player = loadTexture("img/player.jpg", renderer);
    renderTexture(player, playerX, playerY, 40, 40, renderer);



    int mapWidth = 15;
    int mapHeight = 15;

    SDL_Texture* blackMap = loadTexture("img/blackMap.jpg", renderer);

    int fullMap[mapHeight][mapWidth] = {
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},

    };

    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWidth; j++) {
            if (fullMap[i][j] == 1) {
                renderTexture(blackMap, j * 40, i * 40, 40, 40, renderer);
            }
        }
    }
    SDL_RenderPresent( renderer );

    bool quit = false;
    SDL_Event e;
    int OldX = playerX;
    int OldY = playerY;
    while (!quit) {

        OldX = playerX;
        OldY = playerY;
        handleInput(e, playerX, playerY, quit);

        renderTexture(hide, OldX, OldY, 40, 40, renderer);
        renderTexture(player, playerX, playerY, 40, 40, renderer);

        SDL_RenderPresent(renderer);

        SDL_Delay(15);

        if(playerX >= 520 && playerY >= 560)
        {
            cout<<"You Win";
            SDL_Texture* win = loadTexture("img/win.png", renderer);
            renderTexture(win, 100, 200, 400, 200, renderer);
            SDL_RenderPresent( renderer );
            break;
        }
    }


    OutGame();
    SDL_DestroyTexture( player );
    player = NULL;

    quitSDL(window, renderer);
    return 0;
}
