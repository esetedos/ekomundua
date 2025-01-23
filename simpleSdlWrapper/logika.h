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
int pantailaKargatu(nibela mapa, POSIZIOA pantaila);
int interfazaKargatu(inventario invent);
POSIZIOA pantailaEgokitu(partidako_data partida, POSIZIOA limiteak);
JOKO_ELEMENTUA jokalariaMugitu(JOKO_ELEMENTUA jokalaria, POSIZIOA abiadura);
int txokatuAlDira(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA kolisioa);
POSIZIOA txokatuAlDiraKolisioa(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA kolisioa, POSIZIOA abiadura);
POSIZIOA paretakinTalka(JOKO_ELEMENTUA jokalaria, POSIZIOA abiadura);
partidako_data eremuaEgin(partidako_data partida, int eremu_id, JOKO_ELEMENTUA jokalaria);
POSIZIOA pantailaMugitu(POSIZIOA pantaila, POSIZIOA limiteak, POSIZIOA jokalaria, POSIZIOA abiadura);
JOKO_ELEMENTUA irudiaKanporatu(JOKO_ELEMENTUA elementua);
int txokatuAlDiraPareta(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA kolisioa);
int paretakinTalkaEskubi(JOKO_ELEMENTUA jokalaria);

#endif