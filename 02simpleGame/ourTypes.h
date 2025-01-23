#ifndef OURTYPES_H
#define OURTYPES_H

#include "ebentoak.h"

typedef enum
{
    PERTSONAIA,
    KOLISIOA,
    EREMUA,
    OBJETUA
} MOTA;
typedef struct
{
    int frame;      // fotograma actual, siempre será < o igual a irudia_kant-1
    int kantitatea; // cantidad de fotogramas (numero maximo, minimo 1)
    int margena;    // pixeles de margen entre fotograma
} IRUDIA;

typedef struct
{
    int width;
    int height;
} NEURRIAK;

typedef struct
{
    MOTA mota;
    int eremu_id;
    int irudia;
    int hitbox[4];
    POSIZIOA pos;
    int id;
    int objetu_id;
    int norabidea;
    IRUDIA irudi_data;
    NEURRIAK neurriak;
    POSIZIOA abiadura;
    Uint32 mugimendua;
    int hartuId;
} JOKO_ELEMENTUA;

typedef struct
{
    int kantitatea;
    JOKO_ELEMENTUA elementuak[150];
    POSIZIOA limiteak;
} nibela;

typedef enum
{
    KANABERA,
    UR_GLOBOA,
    BATEA,
    EGUNKARIA,
    MOLOTOV,
    EZER_EZ
} OBJETUAK;

typedef struct
{
    int posizioa;
    OBJETUAK objetuak[5];
    int kantitatea[5];
    int argazkiak[7];
} inventario;

typedef struct
{
    int nibel;
    POSIZIOA jokalaria;
    int objetuak[50];
    int objetu_kantitatea[3];
    inventario invent;
} partidako_data;

#endif