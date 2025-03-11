#ifndef _MOVE__H_
#define _MOVE__H_

void handleInput(SDL_Event& e, int& x, int& y, bool& quit) {
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            quit = true;
        }
        else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_UP:
                    y -= 10;
                    break;
                case SDLK_DOWN:
                    y += 10;
                    break;
                case SDLK_LEFT:
                    x -= 10;
                    break;
                case SDLK_RIGHT:
                    x += 10;
                    break;
            }
        }
    }
}

#endif // _MOVE__H_
