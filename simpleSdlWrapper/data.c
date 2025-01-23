#define _CRT_SECURE_NO_WARNINGS
#include "ourTypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

nibela dataKargatu(int nibel)
{
    srand(time(NULL));
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
    case 5:
        mapa.kantitatea = 4;
        break;
    case 35:
        mapa.kantitatea = 18;
        mapa.limiteak.x = 2000;
        mapa.limiteak.y = 2000;

        mapa.elementuak[0].mota = PERTSONAIA;
        mapa.elementuak[0].irudia = 0;

        mapa.elementuak[1].mota = KOLISIOA;
        mapa.elementuak[1].pos.x = 740;
        mapa.elementuak[1].pos.y = 1500;
        mapa.elementuak[1].hitbox[0] = 740;
        mapa.elementuak[1].hitbox[1] = 1500;
        mapa.elementuak[1].hitbox[2] = 900;
        mapa.elementuak[1].hitbox[3] = 1510;
        mapa.elementuak[1].irudia = 6;

        mapa.elementuak[2].mota = KOLISIOA;
        mapa.elementuak[2].pos.x = 740;
        mapa.elementuak[2].pos.y = 1300;
        mapa.elementuak[2].hitbox[0] = 740;
        mapa.elementuak[2].hitbox[1] = 1300;
        mapa.elementuak[2].hitbox[2] = 750;
        mapa.elementuak[2].hitbox[3] = 1510;
        mapa.elementuak[2].irudia = 7;

        mapa.elementuak[3].mota = KOLISIOA;
        mapa.elementuak[3].pos.x = 190;
        mapa.elementuak[3].pos.y = 1300;
        mapa.elementuak[3].hitbox[0] = 190;
        mapa.elementuak[3].hitbox[1] = 1300;
        mapa.elementuak[3].hitbox[2] = 740;
        mapa.elementuak[3].hitbox[3] = 1310;
        mapa.elementuak[3].irudia = 8;

        mapa.elementuak[4].mota = KOLISIOA;
        mapa.elementuak[4].pos.x = 190;
        mapa.elementuak[4].pos.y = 490;
        mapa.elementuak[4].hitbox[0] = 190;
        mapa.elementuak[4].hitbox[1] = 490;
        mapa.elementuak[4].hitbox[2] = 200;
        mapa.elementuak[4].hitbox[3] = 1310;
        mapa.elementuak[4].irudia = 9;

        mapa.elementuak[5].mota = KOLISIOA;
        mapa.elementuak[5].pos.x = 190;
        mapa.elementuak[5].pos.y = 490;
        mapa.elementuak[5].hitbox[0] = 190;
        mapa.elementuak[5].hitbox[1] = 490;
        mapa.elementuak[5].hitbox[2] = 500;
        mapa.elementuak[5].hitbox[3] = 500;
        mapa.elementuak[5].irudia = 10;

        mapa.elementuak[6].mota = KOLISIOA;
        mapa.elementuak[6].pos.x = 490;
        mapa.elementuak[6].pos.y = 190;
        mapa.elementuak[6].hitbox[0] = 490;
        mapa.elementuak[6].hitbox[1] = 190;
        mapa.elementuak[6].hitbox[2] = 500;
        mapa.elementuak[6].hitbox[3] = 500;
        mapa.elementuak[6].irudia = 11;

        mapa.elementuak[7].mota = KOLISIOA;
        mapa.elementuak[7].pos.x = 500;
        mapa.elementuak[7].pos.y = 190;
        mapa.elementuak[7].hitbox[0] = 490;
        mapa.elementuak[7].hitbox[1] = 190;
        mapa.elementuak[7].hitbox[2] = 1510;
        mapa.elementuak[7].hitbox[3] = 200;
        mapa.elementuak[7].irudia = 12;

        mapa.elementuak[8].mota = KOLISIOA;
        mapa.elementuak[8].pos.x = 1500;
        mapa.elementuak[8].pos.y = 190;
        mapa.elementuak[8].hitbox[0] = 1500;
        mapa.elementuak[8].hitbox[1] = 190;
        mapa.elementuak[8].hitbox[2] = 1510;
        mapa.elementuak[8].hitbox[3] = 500;
        mapa.elementuak[8].irudia = 11;

        mapa.elementuak[9].mota = KOLISIOA;
        mapa.elementuak[9].pos.x = 1500;
        mapa.elementuak[9].pos.y = 490;
        mapa.elementuak[9].hitbox[0] = 1500;
        mapa.elementuak[9].hitbox[1] = 490;
        mapa.elementuak[9].hitbox[2] = 1810;
        mapa.elementuak[9].hitbox[3] = 500;
        mapa.elementuak[9].irudia = 10;

        mapa.elementuak[10].mota = KOLISIOA;
        mapa.elementuak[10].pos.x = 1800;
        mapa.elementuak[10].pos.y = 490;
        mapa.elementuak[10].hitbox[0] = 1800;
        mapa.elementuak[10].hitbox[1] = 490;
        mapa.elementuak[10].hitbox[2] = 1810;
        mapa.elementuak[10].hitbox[3] = 1310;
        mapa.elementuak[10].irudia = 9;

        mapa.elementuak[11].mota = KOLISIOA;
        mapa.elementuak[11].pos.x = 1250;
        mapa.elementuak[11].pos.y = 1300;
        mapa.elementuak[11].hitbox[0] = 1250;
        mapa.elementuak[11].hitbox[1] = 1300;
        mapa.elementuak[11].hitbox[2] = 1810;
        mapa.elementuak[11].hitbox[3] = 1310;
        mapa.elementuak[11].irudia = 8;

        mapa.elementuak[12].mota = KOLISIOA;
        mapa.elementuak[12].pos.x = 1250;
        mapa.elementuak[12].pos.y = 1300;
        mapa.elementuak[12].hitbox[0] = 1250;
        mapa.elementuak[12].hitbox[1] = 1300;
        mapa.elementuak[12].hitbox[2] = 1260;
        mapa.elementuak[12].hitbox[3] = 1510;
        mapa.elementuak[12].irudia = 7;

        mapa.elementuak[13].mota = KOLISIOA;
        mapa.elementuak[13].pos.x = 1100;
        mapa.elementuak[13].pos.y = 1500;
        mapa.elementuak[13].hitbox[0] = 1100;
        mapa.elementuak[13].hitbox[1] = 1500;
        mapa.elementuak[13].hitbox[2] = 1260;
        mapa.elementuak[13].hitbox[3] = 1510;
        mapa.elementuak[13].irudia = 6;

        mapa.elementuak[14].mota = KOLISIOA;
        mapa.elementuak[14].pos.x = 800;
        mapa.elementuak[14].pos.y = 700;
        mapa.elementuak[14].hitbox[0] = 800;
        mapa.elementuak[14].hitbox[1] = 700;
        mapa.elementuak[14].hitbox[2] = 1200;
        mapa.elementuak[14].hitbox[3] = 1100;
        mapa.elementuak[14].irudia = 13;

        mapa.elementuak[15].mota = KOLISIOA;
        mapa.elementuak[15].pos.x = 200;
        mapa.elementuak[15].pos.y = 580;
        mapa.elementuak[15].hitbox[0] = 200;
        mapa.elementuak[15].hitbox[1] = 580;
        mapa.elementuak[15].hitbox[2] = 250;
        mapa.elementuak[15].hitbox[3] = 740;
        mapa.elementuak[15].irudia = 14;

        mapa.elementuak[16].mota = KOLISIOA;
        mapa.elementuak[16].pos.x = 200;
        mapa.elementuak[16].pos.y = 820;
        mapa.elementuak[16].hitbox[0] = 200;
        mapa.elementuak[16].hitbox[1] = 820;
        mapa.elementuak[16].hitbox[2] = 250;
        mapa.elementuak[16].hitbox[3] = 980;
        mapa.elementuak[16].irudia = 14;

        mapa.elementuak[17].mota = KOLISIOA;
        mapa.elementuak[17].pos.x = 200;
        mapa.elementuak[17].pos.y = 1060;
        mapa.elementuak[17].hitbox[0] = 200;
        mapa.elementuak[17].hitbox[1] = 1060;
        mapa.elementuak[17].hitbox[2] = 250;
        mapa.elementuak[17].hitbox[3] = 1220;
        mapa.elementuak[17].irudia = 14;
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

    partida.objetu_kantitatea[0] = 1;
    partida.objetu_kantitatea[1] = 40;
    partida.objetu_kantitatea[2] = 1;
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