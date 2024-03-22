#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL_ttf.h>
#include "main.h"
#include "render.h"
#include "manageKeys.h"
#include "balle.h"
#include "bg.h"

void UpdatePos() {
    // // update position rectangles
    yRectRight += dyRectRight;
    yRectLeft += dyRectLeft;

    // update balle pos
    x += dx;
    y += dy;
}

void checkCollision(SDL_Rect maBalle, SDL_Rect lRect, SDL_Rect rRect ) {
    SDL_bool collision_left = SDL_HasIntersection(&maBalle, &lRect);
    if (collision_left && dx < 0) {
        dx = -dx;


        collision_left = 0;
    }
    SDL_bool collision_right = SDL_HasIntersection(&maBalle, &rRect);
    if (collision_right && dx > 0) {
        dx = -dx;

        collision_right = 0;
    }

}

void manageRect() {
    // dessiner la balle
    SDL_Rect maBalle = { x, y, size, size };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &maBalle);
    // dessiner le rect droite
    SDL_Rect rRect = { xRectRight, yRectRight, widthRectRight, lengthRectRight };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rRect);
    // dessiner le rect gauche
    SDL_Rect lRect = { xRectLeft, yRectLeft, widthRectLeft, lengthRectLeft };
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &lRect);

    checkCollision(maBalle, lRect, rRect);
}

int main(int argc, char* argv[]) {

    //configure la sdl, la fenetre et le rendu
    initialise();
    createWindow();
    createRender();
   
    while (1) {
        //event qui gere le deplacement des rectangles
        KeyEvent();

        UpdatePos();
       
        // Clear render
        clear();
        setBg();

        manageRect();

        screenLimits();

        stopBalle();

        // update render
        SDL_RenderPresent(renderer);

        // Pause for a few milliseconds to control the movement speed
        SDL_Delay(10);
    }
    freeAll();
    return 0;
}