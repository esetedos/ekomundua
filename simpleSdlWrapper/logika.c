#include "data.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "soinua.h"
#include "text.h"
#include <math.h>
#include <stdio.h>

int pantailaKargatu(nibela mapa, POSIZIOA pantaila, GLOBOAK globoak)
{
    int i;
    // se limpia la pantalla para poder dibujar todo de nuevo
    pantailaGarbitu();
    for (i = 0; i < mapa.kantitatea; i++)
    {
        irudiaMugitu(mapa.elementuak[i].id, mapa.elementuak[i].pos.x - pantaila.x,
                     mapa.elementuak[i].pos.y - pantaila.y);
    }
    for (i = 0; i < 10; i++)
    {
        // movimiento de globos
        irudiaMugitu(globoak.id[i], globoak.posizioa[i].x - pantaila.x, globoak.posizioa[i].y - pantaila.y);
    }

    // int frame, int margen, int width, int height, int jokalariarenNorabidea)
    irudiakMarraztu(mapa);
    pantailaBerriztu();
    return 0;
}

GLOBOAK globoakMugitu(GLOBOAK globoak)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        globoak.posizioa[i].x += globoak.abiadura[i].x;
        globoak.posizioa[i].y += globoak.abiadura[i].y;
    }

    return globoak;
}

int fondoaKargatu(int irudia)
{
    // carga de fondos
    int id;
    switch (irudia)
    {
    case 100:
        id = irudiaKargatu("./img/fondo_1.bmp");
        break;
    case 101:
        id = irudiaKargatu("./img/fondo_2.bmp");
        break;
    case 102:
        id = irudiaKargatu("./img/fondo_3.bmp");
        break;
    case 111:
        id = irudiaKargatu("./img/Rio.bmp");
        break;
    default:
        break;
        return id;
    }
}

int paretakinTalkaEskubi(JOKO_ELEMENTUA jokalaria)
{
    // para detectar colisiones con la derecha
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

POSIZIOA paretakinTalka(JOKO_ELEMENTUA jokalaria, POSIZIOA abiadura)
{
    // para que no choque con ninguna pared
    //  datos de las paredes del 3er nibel
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

int objetuakKargatu(int irudia)
{
    int id;
    switch (irudia)
    {
    case 5:
        id = irudiaKargatu("./img/kanaberaX2.bmp");
        break;
    case 19:
        id = irudiaKargatu("./img/bolsa_gris.bmp");
        break;
    case 20:
        id = irudiaKargatu("./img/bolsa_amarilla.bmp");
        break;
    case 21:
        id = irudiaKargatu("./img/jager.bmp");
        break;
    case 22:
        id = irudiaKargatu("./img/licor.bmp");
        break;
    case 23:
        id = irudiaKargatu("./img/cocacola.bmp");
        break;
    case 24:
        id = irudiaKargatu("./img/cigarros.bmp");
        break;
    case 103:
        id = irudiaKargatu("./img/suelo_1.bmp");
        break;
    case 104:
        id = irudiaKargatu("./img/suelo_2.bmp");
        break;
    case 105:
        id = irudiaKargatu("./img/suelo_3.bmp");
        break;
    case 106:
        id = irudiaKargatu("./img/suelo_4.bmp");
        break;
    case 107:
        id = irudiaKargatu("./img/suelo_5.bmp");
        break;
    case 108:
        id = irudiaKargatu("./img/suelo_futbol.bmp");
        break;
    default:
        break;
        return id;
    }
}

GLOBOAK globoaBota(GLOBOAK globoak, JOKO_ELEMENTUA jokalaria, POSIZIOA pantaila)
{
    // geometria para los disparos de los globos
    int modulua;
    float moduluaf;
    POSIZIOA sagua;
    sagua = saguarenPosizioa();
    sagua.x += 7 + pantaila.x;
    sagua.y += 9 + pantaila.y;
    globoak.abiadura[globoak.zenbagarrena].x = sagua.x - jokalaria.pos.x - 25;
    globoak.abiadura[globoak.zenbagarrena].y = sagua.y - jokalaria.pos.y - 36;
    modulua = globoak.abiadura[globoak.zenbagarrena].x * globoak.abiadura[globoak.zenbagarrena].x +
              globoak.abiadura[globoak.zenbagarrena].y * globoak.abiadura[globoak.zenbagarrena].y;
    moduluaf = (float)modulua;
    moduluaf = (float)(sqrt(moduluaf) / 10);
    modulua = (int)moduluaf;
    globoak.abiadura[globoak.zenbagarrena].x /= modulua;
    globoak.abiadura[globoak.zenbagarrena].y /= modulua;
    globoak.posizioa[globoak.zenbagarrena].x = jokalaria.pos.x + 25;
    globoak.posizioa[globoak.zenbagarrena].y = jokalaria.pos.y + 36;
    globoak.zenbagarrena++;
    if (globoak.zenbagarrena == 10)
    {
        globoak.zenbagarrena = 0;
    }
    return globoak;
}

int irudiaOndoKargatu(char *fileName)
{
    int irudia;
    irudia = irudiaKargatu("./img/irudia.bmp");
    if (irudia == -1)
    {
        irudiaKendu(irudia);
        irudia = irudiaKargatu(fileName);
    }
    return irudia;
}

int irudiakKargatu(int irudia)
{
    int id;
    switch (irudia)
    {
    case 1:
        id = irudiaKargatu("./img/arboles_1.bmp");
        break;
    case 2:
        id = irudiaKargatu("./img/arboles_2.bmp");
        break;
    case 3:
        id = irudiaKargatu("./img/rio_1.bmp");
        break;
    case 4:
        id = irudiaKargatu("./img/coche.bmp");
        break;
    case 6:
        id = irudiaKargatu("./img/arboles_5.bmp");
        break;
    case 7:
        id = irudiaKargatu("./img/arboles_4.bmp");
        break;
    case 8:
        id = irudiaKargatu("./img/arbusto.bmp");
        break;
    case 9:
        id = irudiaKargatu("./img/arbol_1.bmp");
        break;
    case 10:
        id = irudiaKargatu("./img/arbol_2.bmp");
        break;
    case 11:
        id = irudiaKargatu("./img/mesa.bmp");
        break;
    case 12:
        id = irudiaKargatu("./img/banco.bmp");
        break;
    case 13:
        id = irudiaKargatu("./img/farola.bmp");
        break;
    case 14:
        id = irudiaKargatu("./img/columpio.bmp");
        break;
    case 15:
        id = irudiaKargatu("./img/tobogan.bmp");
        break;
    case 16:
        id = irudiaKargatu("./img/fuente.bmp");
        break;
    case 17:
        id = irudiaKargatu("./img/arboles_1.bmp");
        break;
    case 18:
        id = irudiaKargatu("./img/arboles_3.bmp");
        break;
    case 25:
        id = irudiaKargatu("./img/arbol_quemado_1.bmp");
        break;
    case 26:
        id = irudiaKargatu("./img/arbol_quemado_2.bmp");
        break;
    case 27:
        id = irudiaKargatu("./img/tronco_quemado.bmp");
        break;
    case 28:
        id = irudiaKargatu("./img/tronco_quemandose.bmp");
        break;
    case 29:
        id = irudiaKargatu("./img/rio_2.bmp");
        break;
    case 30:
        id = irudiaKargatu("./img/cigarros.bmp");
        break;
    case 31:
        id = irudiaKargatu("./img/cigarros.bmp");
        break;
    case 32:
        id = irudiaKargatu("./img/arboles_quemandose_3.bmp");
        break;
    case 33:
        id = irudiaKargatu("./img/arboles_quemandose_1.bmp");
        break;
    case 34:
        id = irudiaKargatu("./img/arboles_quemandose_2.bmp");
        break;
    case 35:
        id = irudiaKargatu("./img/arboles_quemandose_2.bmp");
        break;
    case 36:
        id = irudiaKargatu("./img/estitxu.bmp");
        break;
    case 37:
        id = irudiaKargatu("./img/pollo.bmp");
        break;
    default:
        break;
    }
    return id;
}

int interfazaKargatu(inventario invent)
{
    int i;
    irudiaMugitu(invent.argazkiak[0], 425, 650);
    irudiaMugitu(invent.argazkiak[1], 422 + invent.posizioa * 30, 647);
    for (i = 0; i < 5; i++)
    {
        switch (invent.objetuak[i])
        {
        case KANABERA:
            irudiaMugitu(invent.argazkiak[2], 433 + i * 30, 658);
            break;
        case UR_GLOBOA:
            irudiaMugitu(invent.argazkiak[3], 433 + i * 30, 658);
            break;
        default:
            break;
        }
    }
    return 0;
}

partidako_data inbentarioaKargatu(partidako_data partida)
{
    // inventario
    partida.invent.argazkiak[0] = irudiaKargatu("./img/inventario.bmp");
    if (partida.invent.argazkiak[0] == -1)
    {
        irudiaKendu(partida.invent.argazkiak[0]);
        partida.invent.argazkiak[0] = irudiaKargatu("./img/inventario.bmp");
    }
    partida.invent.argazkiak[1] = irudiaKargatu("./img/casilla.bmp");
    if (partida.invent.argazkiak[1] == -1)
    {
        irudiaKendu(partida.invent.argazkiak[0]);
        partida.invent.argazkiak[1] = irudiaKargatu("./img/casilla.bmp");
    }
    partida.invent.argazkiak[2] = irudiaKargatu("./img/kanabera.bmp");
    if (partida.invent.argazkiak[2] == -1)
    {
        irudiaKendu(partida.invent.argazkiak[0]);
        partida.invent.argazkiak[2] = irudiaKargatu("./img/kanabera.bmp");
    }
    irudiaMugitu(partida.invent.argazkiak[2], -1000, -1000);
    partida.invent.argazkiak[3] = irudiaKargatu("./img/globo.bmp");
    if (partida.invent.argazkiak[3] == -1)
    {
        irudiaKendu(partida.invent.argazkiak[0]);
        partida.invent.argazkiak[3] = irudiaKargatu("./img/globo.bmp");
    }
    irudiaMugitu(partida.invent.argazkiak[3], -1000, -1000);
    return partida;
}

GLOBOAK globoakKargatu()
{
    int i;
    GLOBOAK globoak;
    for (i = 0; i < 10; i++)
    {
        globoak.id[i] = irudiaKargatu("./img/globo.bmp");
        globoak.abiadura[i].x = 0;
        globoak.abiadura[i].y = 0;
        globoak.posizioa[i].x = -2000;
        globoak.posizioa[i].y = -2000;
    }
    globoak.zenbagarrena = 0;
    return globoak;
}

int pausaBotoia(int nibel)
{
    int ebentu, hasi = 1;
    POSIZIOA sagua;
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_ESCAPE_UP);
    do
    {
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            sagua = saguarenPosizioa();
            if (sagua.x > 240 && sagua.x < 750 && sagua.y > 250 && sagua.y < 320)
            {
                hasi = 0;
            }
            else if (sagua.x > 240 && sagua.x < 750 && sagua.y > 380 && sagua.y < 450)
            {
                hasi = 0;
                nibel = 10;
            }
        }
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_ESCAPE && hasi == 1);
    return nibel;
}

partidako_data objetuaGehitu(partidako_data partida, OBJETUAK objetua)
{
    // añadir objetos a la partida
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
    // para ajustar la pantalla
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
    // movimiento del jugador
    jokalaria.pos.x += abiadura.x;
    jokalaria.pos.y += abiadura.y;
    jokalaria.hitbox[0] += abiadura.x;
    jokalaria.hitbox[1] += abiadura.y;
    jokalaria.hitbox[2] += abiadura.x;
    jokalaria.hitbox[3] += abiadura.y;
    return jokalaria;
}

int txokatuAlDira(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA kolisioa)
{
    // deteccion de colision
    int k = 0;
    if (jokalaria.hitbox[0] < kolisioa.hitbox[2] && jokalaria.hitbox[1] < kolisioa.hitbox[3] &&
        jokalaria.hitbox[2] > kolisioa.hitbox[0] && jokalaria.hitbox[3] > kolisioa.hitbox[1])
    {
        k = 1;
    }
    return k;
}

POSIZIOA txokatuAlDiraKolisioa(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA kolisioa, POSIZIOA abiadura)
{ // deteccion de colision y cambio de velocidad envase a eso

    if (kolisioa.mota == KOLISIOA)
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
    }
    return abiadura;
}

partidako_data eremuaEgin(partidako_data partida, int eremu_id, JOKO_ELEMENTUA jokalaria)
{
    // colisiones con las paredes para cambio de nivel
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
    case 2:
        partida.nibel = 2;
        partida.jokalaria.x = 2950;
        partida.jokalaria.y = jokalaria.pos.y - 4400;
        break;
    case 3:
        partida.nibel = 1;
        partida.jokalaria.x = 10;
        partida.jokalaria.y = jokalaria.pos.y + 4400;
        break;
    case 4:
        partida.nibel = 6;
        break;
    case 5:
        partida.nibel = 3;
        partida.jokalaria.x = 1050;
        partida.jokalaria.y = jokalaria.pos.y - 800;
        break;
    case 6:
        partida.nibel = 2;
        partida.jokalaria.x = 5;
        partida.jokalaria.y = jokalaria.pos.y + 800;
        break;
    default:
        break;
    }
    return partida;
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

POSIZIOA pantailaMugitu(POSIZIOA pantaila, POSIZIOA limiteak, POSIZIOA jokalaria, POSIZIOA abiadura)
{
    // para que la pantalla se mueva con el jugador cuando el mapa es más grande que los margenes
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
    // sacar elementos de la pantalla
    elementua.pos.x = -1000;
    elementua.pos.y = -1000;
    elementua.hitbox[0] = -1000;
    elementua.hitbox[1] = -1000;
    elementua.hitbox[2] = -1000;
    elementua.hitbox[3] = -1000;
    return elementua;
}

nibela objetuakKanporatu(partidako_data partida, nibela mapa)
{
    // detecta que elementos hay que sacar
    int i;
    for (i = 0; i < mapa.kantitatea; i++)
    {
        if (mapa.elementuak[i].mota == OBJETUA)
        {
            if (partida.objetuak[mapa.elementuak[i].objetu_id] == 1)
            {
                mapa.elementuak[i] = irudiaKanporatu(mapa.elementuak[i]);
            }
        }
    }
    return mapa;
}

void irudiakKendu(nibela mapa)
{
    int i;
    for (i = 0; i < mapa.kantitatea; i++)
    {
        irudiaKendu(mapa.elementuak[i].id);
    }
}

partidako_data kolisioak(partidako_data partida, nibela mapa)
{
    int i, txokea;
    for (i = 0; i < mapa.kantitatea; i++)
    {
        partida.abiadura = txokatuAlDiraKolisioa(mapa.elementuak[0], mapa.elementuak[i], partida.abiadura);
        txokea = txokatuAlDira(mapa.elementuak[0], mapa.elementuak[i]);
        if (mapa.elementuak[i].mota == EREMUA && txokea == 1)
        {
            partida = eremuaEgin(partida, mapa.elementuak[i].eremu_id, mapa.elementuak[0]);
        }
    }
    return partida;
}

partidako_data objetuak(partidako_data partida, nibela mapa)
{
    // cuando pilla un objeto (pulsando la e) ejecuta lo que indique dicho objeto
    int i, txokea;
    for (i = 0; i < mapa.kantitatea; i++)
    {
        txokea = txokatuAlDira(mapa.elementuak[0], mapa.elementuak[i]);
        if (mapa.elementuak[i].mota == OBJETUA && txokea == 1)
        {
            mapa.elementuak[i] = irudiaKanporatu(mapa.elementuak[i]);
            irudiaMugitu(mapa.elementuak[i].id, mapa.elementuak[i].pos.x, mapa.elementuak[i].pos.y);
            partida.objetuak[mapa.elementuak[i].objetu_id] = 1;
            if (mapa.elementuak[i].objetu_id == 0)
            {
                partida = objetuaGehitu(partida, KANABERA);
            }
            else if (mapa.elementuak[i].objetu_id == 41)
            {
                partida = objetuaGehitu(partida, UR_GLOBOA);
            }
            break;
        }
    }
    return partida;
}