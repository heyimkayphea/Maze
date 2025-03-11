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

    SDL_Texture* background = loadTexture("maze.png", renderer);
    SDL_RenderCopy( renderer, background, NULL, NULL);

    int playerX = 750;
    int playerY = 580;

    SDL_Texture* player = loadTexture("player.png", renderer);
    renderTexture(player, playerX, playerY, 25, 25, renderer);
    SDL_RenderPresent( renderer );

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        handleInput(e, playerX, playerY, quit);

        SDL_SetRenderDrawColor(renderer, 173, 216, 230, 255);
        SDL_RenderClear(renderer);

        SDL_RenderCopy( renderer, background, NULL, NULL);
        renderTexture(player, playerX, playerY, 25, 25, renderer);

        SDL_RenderPresent(renderer);

        SDL_Delay(15);

        if(playerX >= 750 && playerY >= 580)
        {
            cout<<"You Win";
            SDL_Texture* win = loadTexture("win.png", renderer);
            renderTexture(win, 150, 150, 500, 250, renderer);
            SDL_RenderPresent( renderer );
            break;
        }
    }


    OutGame();
    SDL_DestroyTexture( player );
    player = NULL;

    SDL_DestroyTexture( background );
    background = NULL;

    quitSDL(window, renderer);
    return 0;
}
