#pragma once
void KEY_DOWN(SDL_Event event) {
    //Check the SDLKey values and move by changing the coords
    switch (event.key.keysym.sym) {
    case SDLK_z:
        dyRectLeft = -5;
        break;
    case SDLK_s:
        dyRectLeft = 5;
        break;
    case SDLK_UP:
        dyRectRight = -5;
        break;
    case SDLK_DOWN:
        dyRectRight = 5;
        break;
    }
}

void KEY_UP() {
    // Stop movement when the key is released
    dyRectLeft = 0;
    dyRectRight = 0;
}

void KeyEvent() {
    // Event pour bouger le rect de haut en bas
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        // update pos when key pressed
        switch (event.type)
        {
            //Look for a keypress
        case SDL_KEYDOWN:
            KEY_DOWN(event);
            break;
        case SDL_KEYUP:
            KEY_UP();
            break;
        }
    }
}