#include "data.h"
#include "ebentoak.h"
#include "graphics.h"
#include "logika.h"
#include "soinua.h"
#include "text.h"
#include <stdio.h>

#define JOKOA_SOUND_WIN "./sound/BugleCall.wav"
#define JOKOA_SOUND_LOOSE "./sound/terminator.wav"
#define BUKAERA_SOUND_1 "./sound/128NIGHT_01.wav"
#define BUKAERA_IMAGE "./img/gameOver.bmp"

void jokoaAurkeztu(void);
partidako_data jokatu(partidako_data partida);
int uploadFrame(JOKO_ELEMENTUA *elem);

void jokoaAurkeztu(void)
{
    int ebentu = 0, idfondo, idboton;
    POSIZIOA sagua;
    SDL_Event event;

    pantailaGarbitu();
    idfondo = irudiaKargatu("./img/Menu.bmp");
    idboton = irudiaKargatu("./img/Hasi.bmp");
    irudiaMugitu(idboton, 400, 400);
    irudiakMarraztuMapa();
    pantailaBerriztu();
    do
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_MOUSEMOTION)
            {
                sagua.x = event.button.x;
                sagua.y = event.button.y;
            }
        }
        if (sagua.x >= 400 && sagua.x <= 600 && sagua.y >= 400 && sagua.y <= 500)
        {
            ebentu = ebentuaJasoGertatuBada();
            saguarenPosizioa();
        }
    } while (ebentu != SAGU_BOTOIA_EZKERRA);
    irudiaKendu(idfondo);
    irudiaKendu(idboton);
}

int uploadFrame(JOKO_ELEMENTUA *elem)
{
    elem->irudi_data.frame =
        (elem->irudi_data.frame++ >= elem->irudi_data.kantitatea - 1) ? 0 : elem->irudi_data.frame++;
    return elem->irudi_data.frame;
}

partidako_data jokatu(partidako_data partida)
{
    nibela mapa;
    POSIZIOA abiadura;
    abiadura.x = 0;
    abiadura.y = 0;
    POSIZIOA pantaila;
    int ebentu = 0, i, egoera, txokea, zaborra = 0;

    arkatzKoloreaEzarri(0, 0, 255);

    mapa = dataKargatu(partida.nibel);
    egoera = partida.nibel;
    mapa.elementuak[0].pos.x = partida.jokalaria.x;
    mapa.elementuak[0].pos.y = partida.jokalaria.y;
    mapa.elementuak[0].hitbox[0] = mapa.elementuak[0].pos.x + 12;
    mapa.elementuak[0].hitbox[1] = mapa.elementuak[0].pos.y + 4;
    mapa.elementuak[0].hitbox[2] = mapa.elementuak[0].hitbox[0] + 32;
    mapa.elementuak[0].hitbox[3] = mapa.elementuak[0].hitbox[1] + 60;

    // temporizadores
    Uint32 lastAnimationTimer = 0;
    Uint32 tiempoActual = SDL_GetTicks();
    pantaila = pantailaEgokitu(partida, mapa.limiteak);
    switch (mapa.elementuak[mapa.kantitatea - 1].irudia)
    {
    case 100:
        mapa.elementuak[mapa.kantitatea - 1].id = irudiaKargatu("./img/fondo_1.bmp");
        break;
    case 101:
        mapa.elementuak[mapa.kantitatea - 1].id = irudiaKargatu("./img/fondo_2.bmp");
        break;
    case 102:
        mapa.elementuak[mapa.kantitatea - 1].id = irudiaKargatu("./img/fondo_3.bmp");
        break;
    case 103:
        mapa.elementuak[mapa.kantitatea - 1].id = irudiaKargatu("./img/Rio.bmp");
        break;
    default:
        break;
    }
    for (i = 1; i < mapa.kantitatea; i++)
    {
        switch (mapa.elementuak[i].irudia)
        {
        case 0:
            mapa.elementuak[i].id = irudiaKargatu("./img/pertsonaia.bmp");
            break;
        case 1:
            mapa.elementuak[i].id = irudiaKargatu("./img/arboles_arriba.bmp");
            break;
        case 2:
            mapa.elementuak[i].id = irudiaKargatu("./img/arboles_4.bmp");
            break;
        case 3:
            mapa.elementuak[i].id = irudiaKargatu("./img/obstaculo_3.bmp");
            break;
        case 4:
            mapa.elementuak[i].id = irudiaKargatu("./img/coche.bmp");
            break;
        case 5:
            mapa.elementuak[i].id = irudiaKargatu("./img/kanabera.bmp");
            break;
        case 6:
            mapa.elementuak[i].id = irudiaKargatu("./img/arboles_3.bmp");
            break;
        case 7:
            mapa.elementuak[i].id = irudiaKargatu("./img/arboles_2.bmp");
            break;
        case 8:
            mapa.elementuak[i].id = irudiaKargatu("./img/arbusto.bmp");
            break;
        case 9:
            mapa.elementuak[i].id = irudiaKargatu("./img/arbol_1.bmp");
            break;
        case 10:
            mapa.elementuak[i].id = irudiaKargatu("./img/arbol_2.bmp");
            break;
        case 11:
            mapa.elementuak[i].id = irudiaKargatu("./img/mesa.bmp");
            break;
        case 12:
            mapa.elementuak[i].id = irudiaKargatu("./img/banco.bmp");
            break;
        case 13:
            mapa.elementuak[i].id = irudiaKargatu("./img/farola.bmp");
            break;
        case 14:
            mapa.elementuak[i].id = irudiaKargatu("./img/columpio.bmp");
            break;
        case 15:
            mapa.elementuak[i].id = irudiaKargatu("./img/atea_1.bmp");
            break;
        case 16:
            mapa.elementuak[i].id = irudiaKargatu("./img/fuente.bmp");
            break;
        case 17:
            mapa.elementuak[i].id = irudiaKargatu("./img/obstaculo_14.bmp");
            break;
        case 18:
            mapa.elementuak[i].id = irudiaKargatu("./img/lurra_4.bmp");
            break;
        case 19:
            mapa.elementuak[i].id = irudiaKargatu("./img/bolsa_gris.bmp");
            break;
        case 20:
            mapa.elementuak[i].id = irudiaKargatu("./img/bolsa_amarilla.bmp");
            break;
        case 21:
            mapa.elementuak[i].id = irudiaKargatu("./img/jager.bmp");
            break;
        case 22:
            mapa.elementuak[i].id = irudiaKargatu("./img/licor.bmp");
            break;
        case 23:
            mapa.elementuak[i].id = irudiaKargatu("./img/cocacola.bmp");
            break;
        case 24:
            mapa.elementuak[i].id = irudiaKargatu("./img/cigarros.bmp");
            break;
        case 36:
            mapa.elementuak[i].id = irudiaKargatu("./img/estitxu.bmp");
            break;
        case 37:
            mapa.elementuak[i].id = irudiaKargatu("./img/pollo.bmp");
            break;
        case 38:
            mapa.elementuak[i].id = irudiaKargatu("./img/bolsa1.bmp");
            break;
        case 39:
            mapa.elementuak[i].id = irudiaKargatu("./img/bolsa2.bmp");
            break;
        case 40:
            mapa.elementuak[i].id = irudiaKargatu("./img/botella.bmp");
            break;
        case 41:
            mapa.elementuak[i].id = irudiaKargatu("./img/pez.bmp");
            break;

        default:
            break;
        }
    }
    mapa.elementuak[0].id = irudiaKargatu("./img/pertsonaia.bmp");
    partida.invent.argazkiak[0] = irudiaKargatu("./img/inventario.bmp");
    partida.invent.argazkiak[1] = irudiaKargatu("./img/casilla.bmp");
    partida.invent.argazkiak[2] = irudiaKargatu("./img/casilla.bmp");
    partida.invent.argazkiak[3] = irudiaKargatu("./img/casilla.bmp");
    partida.invent.argazkiak[4] = irudiaKargatu("./img/casilla.bmp");
    partida.invent.argazkiak[5] = irudiaKargatu("./img/casilla.bmp");
    partida.invent.argazkiak[6] = irudiaKargatu("./img/casilla.bmp");
    if (partida.nibel == 4)
    {
        mapa.elementuak[0].norabidea = 4;
    }
    do
    {
        SDL_Delay(10);
        pantailaKargatu(mapa, pantaila);
        interfazaKargatu(partida.invent);
        ebentu = ebentuaJasoGertatuBada();
        switch (ebentu)
        {
        case TECLA_LEFT:
            abiadura.x = -5;
            if (partida.nibel == 4)
            {
                mapa.elementuak[0].norabidea = 4;
            }
            else
            {
                mapa.elementuak[0].norabidea = 2;
            }

            // Obtener el tiempo actual
            tiempoActual = SDL_GetTicks();

            // Verificar si han pasado al menos 2 segundos desde la última animación
            if (tiempoActual - lastAnimationTimer >= 100)
            {
                mapa.elementuak[0].irudi_data.frame = uploadFrame(&mapa.elementuak[0]);
                lastAnimationTimer = tiempoActual;
            }
            break;
        case TECLA_RIGHT:
            abiadura.x = 5;
            if (partida.nibel == 4)
            {
                mapa.elementuak[0].norabidea = 4;
            }
            else
            {
                mapa.elementuak[0].norabidea = 3;
            }

            tiempoActual = SDL_GetTicks();
            if (tiempoActual - lastAnimationTimer >= 100)
            {
                mapa.elementuak[0].irudi_data.frame = uploadFrame(&mapa.elementuak[0]);
                lastAnimationTimer = tiempoActual;
            }
            break;
        case TECLA_UP:
            abiadura.y = -5;
            if (partida.nibel == 4)
            {
                mapa.elementuak[0].norabidea = 4;
            }
            else
            {
                mapa.elementuak[0].norabidea = 0;
            }

            tiempoActual = SDL_GetTicks();
            if (tiempoActual - lastAnimationTimer >= 100)
            {
                mapa.elementuak[0].irudi_data.frame = uploadFrame(&mapa.elementuak[0]);
                lastAnimationTimer = tiempoActual;
            }
            break;
        case TECLA_DOWN:
            abiadura.y = 5;
            if (partida.nibel == 4)
            {
                mapa.elementuak[0].norabidea = 4;
            }
            else
            {
                mapa.elementuak[0].norabidea = 1;
            }

            tiempoActual = SDL_GetTicks();
            if (tiempoActual - lastAnimationTimer >= 100)
            {
                mapa.elementuak[0].irudi_data.frame = uploadFrame(&mapa.elementuak[0]);
                lastAnimationTimer = tiempoActual;
            }
            break;
        case TECLA_LEFT_UP:
            abiadura.x = 0;
            if (partida.nibel == 0)
            {
                mapa.elementuak[0].irudi_data.frame = 0;
            }
            break;
        case TECLA_RIGHT_UP:
            abiadura.x = 0;
            mapa.elementuak[0].irudi_data.frame = 0;
            break;
        case TECLA_UP_UP:
            abiadura.y = 0;
            mapa.elementuak[0].irudi_data.frame = 0;
            break;
        case TECLA_DOWN_UP:
            abiadura.y = 0;
            mapa.elementuak[0].irudi_data.frame = 0;
            break;
        case TECLA_SPACE:
            partida.nibel = 4;
            break;
        case TECLA_v:
            partida.nibel = 0;
            break;
        case TECLA_r:
            partida.nibel = 90;
            break;
        case TECLA_e:
            // si hay dos objetos al alcance, recoge ambos a la vez
            for (i = 0; i < mapa.kantitatea; i++)
            {
                txokea = txokatuAlDira(mapa.elementuak[0], mapa.elementuak[i]);
                if (mapa.elementuak[i].mota == OBJETUA && txokea == 1)
                {
                    mapa.elementuak[i] = irudiaKanporatu(mapa.elementuak[i]);
                    irudiaMugitu(mapa.elementuak[i].id, mapa.elementuak[i].pos.x, mapa.elementuak[i].pos.y);
                    break;
                }
            }
            break;
        case TECLA_1:
            partida.invent.posizioa = 0;
            break;
        case TECLA_2:
            partida.invent.posizioa = 1;
            break;
        case TECLA_3:
            partida.invent.posizioa = 2;
            break;
        case TECLA_4:
            partida.invent.posizioa = 3;
            break;
        case TECLA_5:
            partida.invent.posizioa = 4;
            break;
        case TECLA_ESCAPE:
            pausaBotoia();
            break;
        default:
            break;
        }
        for (i = 0; i < mapa.kantitatea; i++)
        {
            if (mapa.elementuak[i].mota == KOLISIOA)
            {
                abiadura = txokatuAlDiraKolisioa(mapa.elementuak[0], mapa.elementuak[i], abiadura);
            }
            txokea = txokatuAlDira(mapa.elementuak[0], mapa.elementuak[i]);
            if (mapa.elementuak[i].mota == EREMUA && txokea == 1)
            {
                partida = eremuaEgin(partida, mapa.elementuak[i].eremu_id, mapa.elementuak[0]);
            }
        }
        // logika 4. nibela
        if (partida.nibel == 4)
        {
            // mapatik ez ateratzeko
            abiadura = paretakinTalka(mapa.elementuak[0], abiadura);
            for (i = 0; i < mapa.kantitatea; i++)
            {
                tiempoActual = SDL_GetTicks();

                if (mapa.elementuak[i].mota == OBJETUA)
                {
                    txokea = txokatuAlDira(mapa.elementuak[0], mapa.elementuak[i]);
                    // mugimendua
                    if (tiempoActual - mapa.elementuak[i].mugimendua >= 50 &&
                        (txokea != 1 || mapa.elementuak[0].hartuId != -1) && mapa.elementuak[0].hartuId != i &&
                        mapa.elementuak[i].hartuId == 0)
                    {
                        mapa.elementuak[i].pos.x += mapa.elementuak[i].abiadura.x;
                        mapa.elementuak[i].hitbox[0] += mapa.elementuak[i].abiadura.x;
                        mapa.elementuak[i].hitbox[2] += mapa.elementuak[i].abiadura.x;
                        // if si sale del mapa, que se ponga en el otro lado
                        if (paretakinTalkaEskubi(mapa.elementuak[i]) == 1)
                        {
                            mapa.elementuak[i].pos.x = -(mapa.elementuak[i].hitbox[2] - mapa.elementuak[i].hitbox[0]);
                            mapa.elementuak[i].hitbox[0] =
                                -(mapa.elementuak[i].hitbox[2] - mapa.elementuak[i].hitbox[0]);
                            mapa.elementuak[i].hitbox[2] = 0;
                        }
                        mapa.elementuak[i].mugimendua = tiempoActual;
                    }
                    if (txokea == 1 &&
                        mapa.elementuak[0].hartuId == -1) // si hay choque y si no hay ningun otro elemento pillado
                    {
                        mapa.elementuak[0].hartuId = i; // ze elementu hartu den gordetzeko
                        mapa.elementuak[i].hartuId = 1; // hartuta dagoela adierazteko
                    }
                }
            }
            if (mapa.elementuak[0].hartuId != -1)
            {
                mapa.elementuak[mapa.elementuak[0].hartuId].pos.x = mapa.elementuak[0].pos.x - 50;
                mapa.elementuak[mapa.elementuak[0].hartuId].pos.y = mapa.elementuak[0].pos.y + 20;
                mapa.elementuak[mapa.elementuak[0].hartuId].hitbox[0] = mapa.elementuak[0].pos.x - 50;
                mapa.elementuak[mapa.elementuak[0].hartuId].hitbox[1] = mapa.elementuak[0].pos.y + 20 + 20;
                mapa.elementuak[mapa.elementuak[0].hartuId].hitbox[2] =
                    mapa.elementuak[0].pos.x - 50 + 150; // 150 = ancho imagen
                mapa.elementuak[mapa.elementuak[0].hartuId].hitbox[3] =
                    mapa.elementuak[0].pos.y + 20 + 100 + 20; // 100 = alto imagen

                if (mapa.elementuak[0].pos.y < 0)
                {
                    mapa.elementuak[mapa.elementuak[0].hartuId].hartuId = 0;
                    mapa.elementuak[mapa.elementuak[0].hartuId].pos.x = 9999;
                    mapa.elementuak[mapa.elementuak[0].hartuId].pos.y = 9999;
                    mapa.elementuak[mapa.elementuak[0].hartuId].hitbox[0] = 9999;
                    mapa.elementuak[mapa.elementuak[0].hartuId].hitbox[1] = 9999;
                    mapa.elementuak[mapa.elementuak[0].hartuId].hitbox[2] = 9999;
                    mapa.elementuak[mapa.elementuak[0].hartuId].hitbox[3] = 9999;
                    mapa.elementuak[0].hartuId = -1;
                    zaborra++;
                }
            }
        }
        else
        {
            mapa.elementuak[0].hartuId = -1;
        }

        pantaila = pantailaMugitu(pantaila, mapa.limiteak, mapa.elementuak[0].pos, abiadura);
        mapa.elementuak[0] = jokalariaMugitu(mapa.elementuak[0], abiadura);

        // si se recoge toda la basura sale del nivel 4
        if (zaborra >= 10 && partida.nibel == 4)
        {
            partida.nibel = 0;
            partida.jokalaria.x = 475;
            partida.jokalaria.y = 1700;
            mapa.elementuak[i].norabidea = 0;
        }

    } while (egoera == partida.nibel);

    for (i = 0; i < mapa.kantitatea; i++)
    {
        irudiaKendu(mapa.elementuak[i].id);
    }
    return partida;
}