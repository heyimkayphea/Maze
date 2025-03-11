#ifndef _PRESS__H
#define _PRESS__H

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void OutGame()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 && (e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

#endif // _PRESS__H_
