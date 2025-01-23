#ifndef LOGIKA_H
#define LOGIKA_H

#include "data.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "soinua.h"
#include "text.h"
#include <stdio.h>

void pausaBotoia();
int irudiaOndoKargatu(char *fileName);
int txokatuAlDiraPareta(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA kolisioa);
int paretakinTalkaEskubi(JOKO_ELEMENTUA jokalaria);
POSIZIOA paretakinTalka(JOKO_ELEMENTUA jokalaria, POSIZIOA abiadura);
int pantailaKargatu(nibela mapa, POSIZIOA pantaila, GLOBOAK globoak);
int interfazaKargatu(inventario invent);
int fondoaKargatu(int irudia);
int objetuakKargatu(int irudia);
int irudiakKargatu(int irudia);
void irudiakKendu(nibela mapa);
GLOBOAK globoakKargatu();
GLOBOAK globoakMugitu(GLOBOAK globoak);
GLOBOAK globoaBota(GLOBOAK globoak, JOKO_ELEMENTUA jokalaria, POSIZIOA pantaila);
partidako_data inbentarioaKargatu(partidako_data partida);
partidako_data objetuak(partidako_data partida, nibela mapa);
partidako_data kolisioak(partidako_data partida, nibela mapa);
nibela objetuakKanporatu(partidako_data partida, nibela mapa);
POSIZIOA pantailaEgokitu(partidako_data partida, POSIZIOA limiteak);
partidako_data objetuaGehitu(partidako_data partida, OBJETUAK objetua);
JOKO_ELEMENTUA jokalariaMugitu(JOKO_ELEMENTUA jokalaria, POSIZIOA abiadura);
int txokatuAlDira(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA kolisioa);
POSIZIOA txokatuAlDiraKolisioa(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA kolisioa, POSIZIOA abiadura);
partidako_data eremuaEgin(partidako_data partida, int eremu_id, JOKO_ELEMENTUA jokalaria);
POSIZIOA pantailaMugitu(POSIZIOA pantaila, POSIZIOA limiteak, POSIZIOA jokalaria, POSIZIOA abiadura);
JOKO_ELEMENTUA irudiaKanporatu(JOKO_ELEMENTUA elementua);

#endif