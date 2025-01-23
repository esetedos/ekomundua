#include "data.h"
#include "ebentoak.h"
#include "graphics.h"
#include "logika.h"
#include "soinua.h"
#include "text.h"
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

void jokoaAurkeztu(void);
partidako_data jokatu(partidako_data partida);
int uploadFrame(JOKO_ELEMENTUA *elem);

void jokoaAurkeztu(void)
{
    int ebentu = 0, idfondo, idboton, idboton2, hasi = 1;
    POSIZIOA sagua;

    pantailaGarbitu();
    idfondo = irudiaKargatu("./img/Menu.bmp");
    idboton = irudiaKargatu("./img/Hasi.bmp");
    idboton2 = irudiaKargatu("./img/hasi_handia.bmp");
    irudiaMugitu(idboton, 400, 400);
    irudiaMugitu(idboton2, -400, -400);
    while (hasi == 1)
    {
        pantailaBerriztu();
        irudiakMarraztuMapa();
        irudiaMugitu(idboton2, -400, -400);
        ebentu = ebentuaJasoGertatuBada();
        sagua = saguarenPosizioa();
        if (sagua.x > 400 && sagua.x < 600 && sagua.y > 400 && sagua.y < 460)
        {
            irudiaMugitu(idboton2, 375, 385);
            if (ebentu == SAGU_BOTOIA_EZKERRA)
            {
                hasi = 0;
            }
        }
    }
    irudiaKendu(idfondo);
    irudiaKendu(idboton);
    irudiaKendu(idboton2);
}

void jokoaBukatu(partidako_data partida)
{
    int ebentu = 0, idfondo, idboton, idboton2, hasi = 1,k=0,l=0,i;
    char j1[8],k1[8],l1[8];
    for (i = 1; i < 41; i++)
    {
        if (partida.objetuak[i]==1)
        {
            k++;
        }
    }
    sprintf(j1,"%d",partida.zaborra);
    sprintf(k1,"%d",k);
    sprintf(l1,"%d",l);
    POSIZIOA sagua;

    pantailaGarbitu();
    idfondo = irudiaKargatu("./img/menu_final.bmp");
    idboton = irudiaKargatu("./img/atera.bmp");
    idboton2 = irudiaKargatu("./img/atera_grande.bmp");
    irudiaMugitu(idboton, 150, 550);
    irudiaMugitu(idboton2, -400, -400);
    while (hasi == 1)
    {
        textuaIdatzi(560,510,"Arrantzatutako zaborra");
        textuaIdatzi(560,570,"Jasotako zaborra");
        textuaIdatzi(560,630,"Itzalitako zuhaitzak");
        textuaIdatzi(860,510,j1);
        textuaIdatzi(860,570,k1);
        textuaIdatzi(860,630,l1);
        pantailaBerriztu();
        irudiakMarraztuMapa();
        irudiaMugitu(idboton2, -400, -400);
        ebentu = ebentuaJasoGertatuBada();
        sagua = saguarenPosizioa();
        if (sagua.x > 150 && sagua.x < 450 && sagua.y > 550 && sagua.y < 630)
        {
            irudiaMugitu(idboton2, 138, 546);
            if (ebentu == SAGU_BOTOIA_EZKERRA)
            {
                hasi = 0;
            }
        }
        if (ebentu==TECLA_ESCAPE)
        {
            hasi=0;
        }
        
    }
    irudiaKendu(idfondo);
    irudiaKendu(idboton);
    irudiaKendu(idboton2);
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
    POSIZIOA pantaila;
    int ebentu = 0, i, j, egoera, pausa, txokea, zaborra = 0;
    GLOBOAK globoak;

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
    mapa.elementuak[mapa.kantitatea - 1].id = fondoaKargatu(mapa.elementuak[mapa.kantitatea - 1].irudia);
    for (i = 1; i < mapa.kantitatea; i++)
    {
        switch (mapa.elementuak[i].irudia)
        {
        case 5:
            mapa.elementuak[i].id = irudiaKargatu("./img/kanaberaX2.bmp");
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
        case 103:
            mapa.elementuak[i].id = irudiaKargatu("./img/suelo_1.bmp");
            break;
        case 104:
            mapa.elementuak[i].id = irudiaKargatu("./img/suelo_2.bmp");
            break;
        case 105:
            mapa.elementuak[i].id = irudiaKargatu("./img/suelo_3.bmp");
            break;
        case 106:
            mapa.elementuak[i].id = irudiaKargatu("./img/suelo_4.bmp");
            break;
        case 107:
            mapa.elementuak[i].id = irudiaKargatu("./img/suelo_5.bmp");
            break;
        case 108:
            mapa.elementuak[i].id = irudiaKargatu("./img/suelo_futbol.bmp");
            break;
        case 109:
            mapa.elementuak[i].id = irudiaKargatu("./img/suelo_6.bmp");
            break;
        case 110:
            mapa.elementuak[i].id = irudiaKargatu("./img/suelo_7.bmp");
            break;
        default:
            break;
        }
    }
    mapa.elementuak[0].id = irudiaKargatu("./img/pertsonaia.bmp");
    for (i = 1; i < mapa.kantitatea; i++)
    {
        switch (mapa.elementuak[i].irudia)
        {
        case 1:
            mapa.elementuak[i].id = irudiaKargatu("./img/arboles_1.bmp");
            break;
        case 2:
            mapa.elementuak[i].id = irudiaKargatu("./img/arboles_2.bmp");
            break;
        case 3:
            mapa.elementuak[i].id = irudiaKargatu("./img/rio_1.bmp");
            break;
        case 4:
            mapa.elementuak[i].id = irudiaKargatu("./img/coche.bmp");
            break;
        case 6:
            mapa.elementuak[i].id = irudiaKargatu("./img/arboles_5.bmp");
            break;
        case 7:
            mapa.elementuak[i].id = irudiaKargatu("./img/arboles_4.bmp");
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
            mapa.elementuak[i].id = irudiaKargatu("./img/tobogan.bmp");
            break;
        case 16:
            mapa.elementuak[i].id = irudiaKargatu("./img/fuente.bmp");
            break;
        case 17:
            mapa.elementuak[i].id = irudiaKargatu("./img/arboles_1.bmp");
            break;
        case 18:
            mapa.elementuak[i].id = irudiaKargatu("./img/arboles_3.bmp");
            break;
        case 25:
            mapa.elementuak[i].id = irudiaKargatu("./img/arbol_quemado_1.bmp");
            break;
        case 26:
            mapa.elementuak[i].id = irudiaKargatu("./img/arbol_quemado_2.bmp");
            break;
        case 27:
            mapa.elementuak[i].id = irudiaKargatu("./img/tronco_quemado.bmp");
            break;
        case 28:
            mapa.elementuak[i].id = irudiaKargatu("./img/tronco_quemandose.bmp");
            break;
        case 29:
            mapa.elementuak[i].id = irudiaKargatu("./img/rio_2.bmp");
            break;
        case 30:
            mapa.elementuak[i].id = irudiaKargatu("./img/cigarros.bmp");
            break;
        case 31:
            mapa.elementuak[i].id = irudiaKargatu("./img/cubo.bmp");
            break;
        case 32:
            mapa.elementuak[i].id = irudiaKargatu("./img/arboles_quemandose_3.bmp");
            break;
        case 33:
            mapa.elementuak[i].id = irudiaKargatu("./img/arboles_quemandose_1.bmp");
            break;
        case 34:
            mapa.elementuak[i].id = irudiaKargatu("./img/arboles_quemandose_2.bmp");
            break;
        case 35:
            mapa.elementuak[i].id = irudiaKargatu("./img/arboles_quemandose_2.bmp");
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

    globoak = globoakKargatu();
    pausa = irudiaKargatu("./img/pausa.bmp");
    if (pausa==-1)
    {
        irudiaKendu(pausa);
        pausa = irudiaKargatu("./img/pausa.bmp");
    } 
    irudiaMugitu(pausa, -1000, -1000);
    partida = inbentarioaKargatu(partida);

    if (partida.nibel == 4)
    {
        mapa.elementuak[0].norabidea = 4;
    }

    do
    {
        SDL_Delay(10);
        pantailaKargatu(mapa, pantaila, globoak);
        interfazaKargatu(partida.invent);
        ebentu = ebentuaJasoGertatuBada();
        switch (ebentu)
        {
        case TECLA_LEFT:
            partida.abiadura.x = -5;
            mapa.elementuak[0].norabidea = (partida.nibel == 4) ? 4 : 2;

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
            partida.abiadura.x = 5;
            mapa.elementuak[0].norabidea = (partida.nibel == 4) ? 4 : 3;

            tiempoActual = SDL_GetTicks();
            if (tiempoActual - lastAnimationTimer >= 100)
            {
                mapa.elementuak[0].irudi_data.frame = uploadFrame(&mapa.elementuak[0]);
                lastAnimationTimer = tiempoActual;
            }
            break;
        case TECLA_UP:
            partida.abiadura.y = -5;
            mapa.elementuak[0].norabidea = (partida.nibel == 4) ? 4 : 0;

            tiempoActual = SDL_GetTicks();
            if (tiempoActual - lastAnimationTimer >= 100)
            {
                mapa.elementuak[0].irudi_data.frame = uploadFrame(&mapa.elementuak[0]);
                lastAnimationTimer = tiempoActual;
            }
            break;
        case TECLA_DOWN:
            partida.abiadura.y = 5;
            mapa.elementuak[0].norabidea = (partida.nibel == 4) ? 4 : 1;

            tiempoActual = SDL_GetTicks();
            if (tiempoActual - lastAnimationTimer >= 100)
            {
                mapa.elementuak[0].irudi_data.frame = uploadFrame(&mapa.elementuak[0]);
                lastAnimationTimer = tiempoActual;
            }
            break;
        case TECLA_LEFT_UP:
            partida.abiadura.x = 0;
            mapa.elementuak[0].irudi_data.frame = 0;
            break;
        case TECLA_RIGHT_UP:
            partida.abiadura.x = 0;
            mapa.elementuak[0].irudi_data.frame = 0;
            break;
        case TECLA_UP_UP:
            partida.abiadura.y = 0;
            mapa.elementuak[0].irudi_data.frame = 0;
            break;
        case TECLA_DOWN_UP:
            partida.abiadura.y = 0;
            mapa.elementuak[0].irudi_data.frame = 0;
            break;
        case TECLA_e:
            // si hay dos objetos al alcance, recoge ambos a la vez
            partida = objetuak(partida, mapa);
            mapa = objetuakKanporatu(partida, mapa);
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
            irudiaMugitu(pausa, 150, 150);
            pantailaKargatu(mapa, pantaila, globoak);
            pausaBotoia(pausa);
            irudiaMugitu(pausa, -1000, -1000);
            pantailaKargatu(mapa, pantaila, globoak);
            break;
         case SAGU_BOTOIA_EZKERRA:
             if (partida.invent.objetuak[partida.invent.posizioa] == UR_GLOBOA)
             {
                 globoak = globoaBota(globoak, mapa.elementuak[0], pantaila);
             }
             else if (partida.invent.objetuak[partida.invent.posizioa] == KANABERA)
             {
                 if (partida.nibel==0&&mapa.elementuak[0].pos.y>1820)
                 {
                     partida.nibel=4;
                     partida.jokalaria.x=475;
                     partida.jokalaria.y=0;
                 }
             }
             break;
        default:
            break;
        }

        partida = kolisioak(partida, mapa);

        if (partida.nibel == 4)
        {
            // mapatik ez ateratzeko
            partida.abiadura = paretakinTalka(mapa.elementuak[0], partida.abiadura);
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
                    partida.zaborra++;
                }
            }
        }
        else
        {
            mapa.elementuak[0].hartuId = -1;
        }
        if (zaborra==10)
        {
            partida.nibel=0;
            partida.jokalaria.x=475;
            partida.jokalaria.y=1820;
        }
        

        pantaila = pantailaMugitu(pantaila, mapa.limiteak, mapa.elementuak[0].pos, partida.abiadura);
        globoak = globoakMugitu(globoak);
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < mapa.kantitatea; j++)
            {
                if (mapa.elementuak[j].mota == KOLISIOA)
                {
                    if (mapa.elementuak[j].hitbox[0] < globoak.posizioa[i].x + 14 &&
                        mapa.elementuak[j].hitbox[1] < globoak.posizioa[i].y + 18 &&
                        mapa.elementuak[j].hitbox[2] > globoak.posizioa[i].x &&
                        mapa.elementuak[j].hitbox[3] > globoak.posizioa[i].y)
                    {
                        globoak.posizioa[i].x = -2000;
                        globoak.posizioa[i].y = -2000;
                        globoak.abiadura[i].x = 0;
                        globoak.abiadura[i].y = 0;
                    }
                }
            }
        }

        mapa.elementuak[0] = jokalariaMugitu(mapa.elementuak[0], partida.abiadura);

    } while (egoera == partida.nibel);

    irudiakKendu(mapa);
    irudiaKendu(pausa);
    return partida;
}