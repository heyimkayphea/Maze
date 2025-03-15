#ifndef _MOVE__H_
#define _MOVE__H_

void handleInput(SDL_Event& e, int& x, int& y, bool& quit, int (amap)[][15]) {
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            quit = true;
        }
        else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_UP:
                    {
                        if(y>0 && amap[y/40-1][x/40]==0)
                        y -= 40;
                    }

                    break;
                case SDLK_DOWN:
                    {
                        if(y<600 && amap[y/40+1][x/40]==0)
                        y += 40;
                    }

                    break;
                case SDLK_LEFT:
                    {
                        if(x>0 && amap[y/40][x/40-1]==0)
                        x -= 40;
                    }
                    break;
                case SDLK_RIGHT:
                    {
                        if(x<600 && amap[y/40][x/40+1]==0)
                        x += 40;
                    }
                    break;
            }
        }
    }
}

#endif // _MOVE__H_
