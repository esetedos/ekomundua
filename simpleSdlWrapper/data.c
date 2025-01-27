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
    // se ejecuta cuando los datos los recogen de un txt y no del codigo
    // las primeras 3 lineas del txt son la cantidad de elementos y el tamaño del nivel
    //  despues de eso van los datos de todos los elementos, cada vez que hay un -1 se empieza un nuevo elemento
    // el primer dato es tipo de elemento
    // el segundo dato es la imagen, a menos de que se un tipo Eremu, en cuyo caso es su eremu_id
    // del tercer al sexto dato son la hitbox
    // el septimo y el octavo son la posicion de la imagen
    // el octavo es el objetu_id
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
                    // datos a colocar a mano sobre las proporciones del personaje (para animaciones)
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
                    mapa.elementuak[j].abiadura.x = 0; // número aleatorio entre 3 y 6, ambos incluídos
                    mapa.elementuak[j].abiadura.y = 3 + rand() % (6 - 3 + 1); // no se usa en el 4to nivel
                    mapa.elementuak[j].mugimendua = 0; // timer para movimiento en el juego de pesca (nivel 4)
                    mapa.elementuak[j].hartuId = 0;    // elemento atrapado 4.nivel

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
                    // elementos con fuego que tienen que ser apagados (para poder hacer su animacion)
                    switch (zenbakia)
                    {
                    case 28:
                        mapa.elementuak[j].neurriak.width = 64;
                        mapa.elementuak[j].neurriak.height = 46;
                        mapa.elementuak[j].irudi_data.frame = 0;
                        mapa.elementuak[j].irudi_data.kantitatea = 1;
                        mapa.elementuak[j].norabidea = 0;
                        mapa.elementuak[j].irudi_data.margena = 0; // pixeles de margen entre fotograma
                        break;
                    case 25:
                        mapa.elementuak[j].neurriak.width = 163;
                        mapa.elementuak[j].neurriak.height = 310;
                        mapa.elementuak[j].irudi_data.frame = 0;
                        mapa.elementuak[j].irudi_data.kantitatea = 1;
                        mapa.elementuak[j].norabidea = 0;
                        mapa.elementuak[j].irudi_data.margena = 0;
                        break;
                    case 26:
                        mapa.elementuak[j].neurriak.width = 167;
                        mapa.elementuak[j].neurriak.height = 260;
                        mapa.elementuak[j].irudi_data.frame = 0;
                        mapa.elementuak[j].irudi_data.kantitatea = 1;
                        mapa.elementuak[j].norabidea = 0;
                        mapa.elementuak[j].irudi_data.margena = 0;
                        break;
                    default:
                        break;
                    }
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
    partida.zaborra = 0;
    partida.sutea = 0;

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