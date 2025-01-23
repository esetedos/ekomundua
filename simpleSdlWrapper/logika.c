#include "data.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "soinua.h"
#include "text.h"
#include <stdio.h>

int pantailaKargatu(nibela mapa, POSIZIOA pantaila)
{
    int i;
    pantailaGarbitu();
    for (i = 0; i < mapa.kantitatea; i++)
    {
        irudiaMugitu(mapa.elementuak[i].id, mapa.elementuak[i].pos.x - pantaila.x,
                     mapa.elementuak[i].pos.y - pantaila.y);
    }
    // int frame, int margen, int width, int height, int jokalariarenNorabidea)
    irudiakMarraztu(mapa);
    for (i = 0; i < mapa.kantitatea; i++)
    {
        karratuaMarraztu(mapa.elementuak[i].hitbox[0] - pantaila.x, mapa.elementuak[i].hitbox[1] - pantaila.y,
                         mapa.elementuak[i].hitbox[2] - pantaila.x, mapa.elementuak[i].hitbox[3] - pantaila.y);
    }
    pantailaBerriztu();
    return 0;
}

int interfazaKargatu(inventario invent)
{
    irudiaMugitu(invent.argazkiak[0], 425, 650);
    irudiaMugitu(invent.argazkiak[1], 422 + invent.posizioa * 30, 647);
    return 0;
}

void pausaBotoia()
{
    int ebentu;
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_ESCAPE_UP);
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_ESCAPE);
}

partidako_data objetuaGehitu(partidako_data partida, OBJETUAK objetua)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (partida.invent.objetuak[i] == EZER_EZ)
        {
            partida.invent.objetuak[i] = objetua;
            break;
        }
    }
    return partida;
}

POSIZIOA pantailaEgokitu(partidako_data partida, POSIZIOA limiteak)
{
    POSIZIOA pantaila;
    if (partida.jokalaria.x < 472)
    {
        pantaila.x = 0;
    }
    else if (partida.jokalaria.x > limiteak.x - 472)
    {
        pantaila.x = limiteak.x - 1000;
    }
    else
    {
        pantaila.x = partida.jokalaria.x - 472;
    }
    if (partida.jokalaria.y < 316)
    {
        pantaila.y = 0;
    }
    else if (partida.jokalaria.y > limiteak.y - 316)
    {
        pantaila.y = limiteak.y - 700;
    }
    else
    {
        pantaila.y = partida.jokalaria.y - 316;
    }
    return pantaila;
}

JOKO_ELEMENTUA jokalariaMugitu(JOKO_ELEMENTUA jokalaria, POSIZIOA abiadura)
{
    jokalaria.pos.x += abiadura.x;
    jokalaria.pos.y += abiadura.y;
    jokalaria.hitbox[0] += abiadura.x;
    jokalaria.hitbox[1] += abiadura.y;
    jokalaria.hitbox[2] += abiadura.x;
    jokalaria.hitbox[3] += abiadura.y;
    return jokalaria;
}

int txokatuAlDiraPareta(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA kolisioa)
{
    int k = 0;

    // Detectar si los hitboxes se tocan horizontal o verticalmente
    if ((jokalaria.hitbox[2] == kolisioa.hitbox[0] ||  // borde derecho de jokalaria toca borde izquierdo de kolisioa
         jokalaria.hitbox[0] == kolisioa.hitbox[2]) && // borde izquierdo de jokalaria toca borde derecho de kolisioa
        (jokalaria.hitbox[1] < kolisioa.hitbox[3] && jokalaria.hitbox[3] > kolisioa.hitbox[1]))
    { // verticalmente se solapan o están en la misma línea
        k = 1;
    }
    else if ((jokalaria.hitbox[3] ==
                  kolisioa.hitbox[1] || // borde inferior de jokalaria toca borde superior de kolisioa
              jokalaria.hitbox[1] ==
                  kolisioa.hitbox[3]) && // borde superior de jokalaria toca borde inferior de kolisioa
             (jokalaria.hitbox[0] < kolisioa.hitbox[2] && jokalaria.hitbox[2] > kolisioa.hitbox[0]))
    { // horizontalmente se solapan o están en la misma línea
        k = 1;
    }

    return k;
}

int txokatuAlDira(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA kolisioa)
{
    int k = 0;
    if (jokalaria.hitbox[0] < kolisioa.hitbox[2] && jokalaria.hitbox[1] < kolisioa.hitbox[3] &&
        jokalaria.hitbox[2] > kolisioa.hitbox[0] && jokalaria.hitbox[3] > kolisioa.hitbox[1])
    {
        k = 1;
    }
    return k;
}

POSIZIOA txokatuAlDiraKolisioa(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA kolisioa, POSIZIOA abiadura)
{
    if (jokalaria.hitbox[0] + abiadura.x < kolisioa.hitbox[2] && jokalaria.hitbox[1] < kolisioa.hitbox[3] &&
        jokalaria.hitbox[2] + abiadura.x > kolisioa.hitbox[0] && jokalaria.hitbox[3] > kolisioa.hitbox[1])
    {
        abiadura.x = 0;
    }
    else if (jokalaria.hitbox[0] < kolisioa.hitbox[2] && jokalaria.hitbox[1] + abiadura.y < kolisioa.hitbox[3] &&
             jokalaria.hitbox[2] > kolisioa.hitbox[0] && jokalaria.hitbox[3] + abiadura.y > kolisioa.hitbox[1])
    {
        abiadura.y = 0;
    }
    return abiadura;
}

POSIZIOA paretakinTalka(JOKO_ELEMENTUA jokalaria, POSIZIOA abiadura)
{
    // datos de las paredes del 3er nibel
    int hitbox[4][4];
    hitbox[0][0] = 0;
    hitbox[0][1] = -50;
    hitbox[0][2] = 1000;
    hitbox[0][3] = -20;

    hitbox[1][0] = -5;
    hitbox[1][1] = 0;
    hitbox[1][2] = 0;
    hitbox[1][3] = 700;

    // derecha
    hitbox[2][0] = 1000;
    hitbox[2][1] = 0;
    hitbox[2][2] = 1005;
    hitbox[2][3] = 700;

    // abajo
    hitbox[3][0] = 0;
    hitbox[3][1] = 700;
    hitbox[3][2] = 1000;
    hitbox[3][3] = 705;

    for (int i = 0; i < 4; i++)
    {
        if (jokalaria.hitbox[0] + abiadura.x < hitbox[i][2] && jokalaria.hitbox[1] < hitbox[i][3] &&
            jokalaria.hitbox[2] + abiadura.x > hitbox[i][0] && jokalaria.hitbox[3] > hitbox[i][1])
        {
            abiadura.x = 0;
        }
        else if (jokalaria.hitbox[0] < hitbox[i][2] && jokalaria.hitbox[1] + abiadura.y < hitbox[i][3] &&
                 jokalaria.hitbox[2] > hitbox[i][0] && jokalaria.hitbox[3] + abiadura.y > hitbox[i][1])
        {
            abiadura.y = 0;
        }
    }

    return abiadura;
}

int paretakinTalkaEskubi(JOKO_ELEMENTUA jokalaria)
{
    int hitbox[4], k = 0;
    // derecha
    hitbox[0] = 1000;
    hitbox[1] = 0;
    hitbox[2] = 1100;
    hitbox[3] = 700;

    if (jokalaria.hitbox[0] < hitbox[2] && // Izquierda de jokalaria está dentro del rango horizontal de kolisioa
        jokalaria.hitbox[0] > hitbox[0] && // Izquierda de jokalaria no está fuera por la izquierda de kolisioa
        jokalaria.hitbox[1] < hitbox[3] && // Parte superior de jokalaria está dentro del rango vertical de kolisioa
        jokalaria.hitbox[3] > hitbox[1])   // Parte inferior de jokalaria está dentro del rango vertical de kolisioa
    {
        k = 1; // Colisión en el lado izquierdo
    }

    return k;
}

partidako_data eremuaEgin(partidako_data partida, int eremu_id, JOKO_ELEMENTUA jokalaria)
{
    switch (eremu_id)
    {
    case 0:
        partida.nibel = 1;
        partida.jokalaria.x = 4950;
        partida.jokalaria.y = jokalaria.pos.y + 3000;
        break;
    case 1:
        partida.nibel = 0;
        partida.jokalaria.x = 5;
        partida.jokalaria.y = jokalaria.pos.y - 3000;
        break;

    case 3:
        partida.nibel = 4;
        partida.jokalaria.x = 450;
        partida.jokalaria.y = 30;
        jokalaria.norabidea = 4;
        break;
    default:
        break;
    }
    return partida;
}

POSIZIOA pantailaMugitu(POSIZIOA pantaila, POSIZIOA limiteak, POSIZIOA jokalaria, POSIZIOA abiadura)
{
    if (pantaila.x + 1000 + abiadura.x <= limiteak.x && pantaila.x + abiadura.x >= 0 && jokalaria.x > 472 &&
        jokalaria.x < limiteak.x - 472)
    {
        pantaila.x += abiadura.x;
    }
    if (pantaila.y + 700 + abiadura.y <= limiteak.y && pantaila.y + abiadura.y >= 0 && jokalaria.y > 316 &&
        jokalaria.y < limiteak.y - 316)
    {
        pantaila.y += abiadura.y;
    }
    return pantaila;
}

JOKO_ELEMENTUA irudiaKanporatu(JOKO_ELEMENTUA elementua)
{
    elementua.pos.x = -1000;
    elementua.pos.y = -1000;
    elementua.hitbox[0] = -1000;
    elementua.hitbox[1] = -1000;
    elementua.hitbox[2] = -1000;
    elementua.hitbox[3] = -1000;
    return elementua;
}