#pragma once
void setBg() {
    SDL_Surface* surface;
    SDL_Texture* texture;

    surface = SDL_LoadBMP("C:/Users/lucie/Downloads/etoile.bmp.bmp");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
}
