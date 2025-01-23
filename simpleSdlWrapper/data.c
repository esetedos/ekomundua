#define _CRT_SECURE_NO_WARNINGS
#include "ourTypes.h"
#include <stdio.h>
#include <stdlib.h>

nibela dataKargatu(int nibel)
{
    nibela mapa;
    FILE *archivo;
    switch (nibel)
    {
    case 0:
        archivo = fopen("./text/nibel_1.txt", "r");
        break;
    case 1:
        archivo = fopen("./text/nibel_2.txt", "r");
        break;
    case 2:
        archivo = fopen("./text/nibel_3.txt", "r");
        break;
    case 3:
        archivo = fopen("./text/nibel_4.txt", "r");
        break;
    case 4:
        archivo = fopen("./text/nibel_5.txt", "r");
        break;
    default:
        break;
    }

    char caracteres[100];
    int zenbakia, i = 0, j = 0;

    fgets(caracteres, 100, archivo);
    sscanf(caracteres, "%d", &zenbakia);
    mapa.kantitatea = zenbakia;
    fgets(caracteres, 100, archivo);
    sscanf(caracteres, "%d", &zenbakia);
    mapa.limiteak.x = zenbakia;
    fgets(caracteres, 100, archivo);
    sscanf(caracteres, "%d", &zenbakia);
    mapa.limiteak.y = zenbakia;

    while (feof(archivo) == 0)
    {
        fgets(caracteres, 100, archivo);
        sscanf(caracteres, "%d", &zenbakia);
        if (zenbakia == -1)
        {
            i = 0;
            j++;
        }
        else
        {
            switch (i)
            {
            case 0:
                switch (zenbakia)
                {
                case 0:
                    mapa.elementuak[j].mota = PERTSONAIA;
                    mapa.elementuak[j].neurriak.width = 51;
                    mapa.elementuak[j].neurriak.height = 72; // 68;
                    mapa.elementuak[j].irudi_data.frame = 0;
                    mapa.elementuak[j].irudi_data.kantitatea = 3;
                    mapa.elementuak[j].norabidea = 0;
                    mapa.elementuak[j].irudi_data.margena = 1; // pixeles de margen entre fotograma
                    mapa.elementuak[j].hartuId = -1;           // elemento atrapado 4.nivel
                    break;
                case 1:
                    mapa.elementuak[j].mota = KOLISIOA;
                    break;
                case 2:
                    mapa.elementuak[j].mota = EREMUA;
                    break;
                case 3:
                    mapa.elementuak[j].mota = OBJETUA;
                    mapa.elementuak[j].abiadura.x =
                        3 + rand() % (6 - 3 + 1); // número aleatorio entre 3 y 6, ambos incluídos
                    mapa.elementuak[j].abiadura.y = 3 + rand() % (6 - 3 + 1); // no se usa en el 4to nivel
                    mapa.elementuak[j].mugimendua = 0;
                    mapa.elementuak[j].hartuId = 0; // elemento atrapado 4.nivel

                    break;
                default:
                    break;
                }
                break;
            case 1:
                if (mapa.elementuak[j].mota == EREMUA)
                {
                    mapa.elementuak[j].eremu_id = zenbakia;
                }
                else
                {
                    mapa.elementuak[j].irudia = zenbakia;
                }
                break;
            case 2:
                mapa.elementuak[j].hitbox[0] = zenbakia;
                break;
            case 3:
                mapa.elementuak[j].hitbox[1] = zenbakia;
                break;
            case 4:
                mapa.elementuak[j].hitbox[2] = zenbakia;
                break;
            case 5:
                mapa.elementuak[j].hitbox[3] = zenbakia;
                break;
            case 6:
                mapa.elementuak[j].pos.x = zenbakia;
                break;
            case 7:
                mapa.elementuak[j].pos.y = zenbakia;
                break;
            case 8:
                mapa.elementuak[j].objetu_id = zenbakia;
                break;
            default:
                break;
            }
            i++;
        }
    }

    fclose(archivo);
    return mapa;
}

partidako_data partidakoDataKargatu()
{
    partidako_data partida;
    partida.nibel = 0;

    partida.invent.posizioa = 0;

    partida.jokalaria.x = 475;
    partida.jokalaria.y = 370;

    partida.abiadura.x = 0;
    partida.abiadura.y = 0;
    partida.zaborra=0;

    int i;

    for (i = 0; i < 42; i++)
    {
        partida.objetuak[i] = 0;
    }

    for (i = 0; i < 5; i++)
    {
        partida.invent.objetuak[i] = EZER_EZ;
    }
    return partida;
}