// Esto con un incude de include
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define GRAPHICS

#include <SDL_ttf.h>

#include "graphics.h"
#include "imagen.h"

SDL_Window *window = NULL;
SDL_Renderer *gRenderer;
int colorR, colorG, colorB;

SDL_Renderer *getRenderer(void)
{
    return gRenderer;
}

void sgHasieratu()
{
    atexit(SDL_Quit);
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Init();
    atexit(TTF_Quit);
}

void sgItxi()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void arkatzKoloreaEzarri(int red, int green, int blue)
{
    colorR = red;
    colorG = green;
    colorB = blue;
}

void zuzenaMarraztu(int x1, int y1, int x2, int y2)
{
    SDL_SetRenderDrawColor(gRenderer, colorR, colorG, colorB, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(gRenderer, x1, y1, x2, y2);
}

void karratuaMarraztu(int x1, int y1, int x2, int y2)
{
    zuzenaMarraztu(x1, y1, x1, y2);
    zuzenaMarraztu(x1, y2, x2, y2);
    zuzenaMarraztu(x2, y2, x2, y1);
    zuzenaMarraztu(x2, y1, x1, y1);
}

int irudiaMarraztuPorTamanoPersonaje(SDL_Texture *texture, SDL_Rect *pDest, int frame, int margen, int width,
                                     int height, int jokalariarenNorabidea)
{
    SDL_Rect src;

    // para que pille la imagen empezando de 0 (si el frame es 0), y si no que pille lo que sería al siguiente frame
    int cropX = (margen + width) * frame + 2;
    // lo mismo, pero teniendo en cuanta la dirección que tiene el personaje
    //  ^ 0 ; v 1
    //  < 2 ; > 3
    int cropY = (jokalariarenNorabidea == 0) ? 0 : (margen + height) * jokalariarenNorabidea + 2;

    src.x = cropX;
    src.y = cropY;

    src.w = (width == 0) ? pDest->w : width;
    src.h = (height == 0) ? pDest->h : height;

    pDest->w = src.w;
    pDest->h = src.h;

    SDL_RenderCopy(gRenderer, texture, &src, pDest);
    return 0;
}

int irudiaMarraztuPorTamano(SDL_Texture *texture, SDL_Rect *pDest, int margen, int width, int height, int norabidea)
{
    SDL_Rect src;

    // para que pille la imagen empezando de 0 (si el frame es 0), y si no que pille lo que sería al siguiente frame
    src.x = margen;
    src.y = (margen + height) * norabidea;

    src.w = width;
    src.h = height;

    pDest->w = src.w;
    pDest->h = src.h;

    SDL_RenderCopy(gRenderer, texture, &src, pDest);
    return 0;
}

void puntuaMarraztu(int x, int y)
{
    SDL_SetRenderDrawColor(gRenderer, colorR, colorG, colorB, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoint(gRenderer, x, y);
}

void zirkuluaMarraztu(int x, int y, int r)
{

    int i, h;

    SDL_SetRenderDrawColor(gRenderer, colorR, colorG, colorB, SDL_ALPHA_OPAQUE);
    for (i = x - r; i <= x + r; i++)
    {
        h = (int)llround(sqrt((double)(r * r - (i - x) * (i - x))));
        SDL_RenderDrawLine(gRenderer, i, y + h, i, y - h);
    }
}

int irudiaMarraztu(SDL_Texture *texture, SDL_Rect *pDest)
{
    SDL_Rect src;

    src.x = 0;
    src.y = 0;
    src.w = pDest->w;
    src.h = pDest->h;
    SDL_RenderCopy(gRenderer, texture, &src, pDest);
    return 0;
}

void pantailaGarbitu()
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(gRenderer);
}

void pantailaBerriztu()
{
    SDL_RenderPresent(gRenderer);
}