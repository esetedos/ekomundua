#include "ebentoak.h"

POSIZIOA saguPos;
SDL_Event event;

POSIZIOA saguarenPosizioa()
{
    return saguPos;
}

int ebentuaJasoGertatuBada(void)
{
    int ret = 0;
    if (SDL_PollEvent(&event))
    {
        /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
        switch (event.type)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_a:
                ret = TECLA_LEFT;
                break;
            case SDLK_d:
                ret = TECLA_RIGHT;
                break;
            case SDLK_s:
                ret = TECLA_DOWN;
                break;
            case SDLK_w:
                ret = TECLA_UP;
                break;
            case SDLK_e:
                ret = TECLA_e;
                break;
            case SDLK_1:
                ret = TECLA_1;
                break;
            case SDLK_2:
                ret = TECLA_2;
                break;
            case SDLK_3:
                ret = TECLA_3;
                break;
            case SDLK_4:
                ret = TECLA_4;
                break;
            case SDLK_5:
                ret = TECLA_5;
                break;
            case SDLK_ESCAPE:
                ret = TECLA_ESCAPE;
                break;
            default:
                ret = event.key.keysym.sym;
                break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym)
            {
            case SDLK_a:
                ret = TECLA_LEFT_UP;
                break;
            case SDLK_d:
                ret = TECLA_RIGHT_UP;
                break;
            case SDLK_s:
                ret = TECLA_DOWN_UP;
                break;
            case SDLK_w:
                ret = TECLA_UP_UP;
                break;
            case SDLK_ESCAPE:
                ret = TECLA_ESCAPE_UP;
                break;
            default:
                ret = event.key.keysym.sym;
                break;
            }
            break;
        case SDL_QUIT:
            ret = GERTAERA_IRTEN;
            break;
        case SDL_MOUSEBUTTONUP:
            switch (event.button.button)
            {
            case SDL_BUTTON_LEFT:
                ret = SAGU_BOTOIA_EZKERRA;
                break;
            case SDL_BUTTON_RIGHT:
                ret = SAGU_BOTOIA_ESKUMA;
                break;
            default:
                ret = event.button.button;
                break;
            }
            break;
        case SDL_MOUSEMOTION:
            // ALDAGIA OROKOR BATEN EZARRIK ODUGU X ETA Y GERO FUNZTIO BATEKIN IRAKURTZEKO AZKEN EBENTUAREN POSIZIOA
            saguPos.x = event.motion.x;
            saguPos.y = event.motion.y;
            ret = SAGU_MUGIMENDUA;
            break;
        default:
            break;
        }
    }
    return ret;
}
