#ifndef IMAGEN_H
#define IMAGEN_H

#define MAX_IMG 150
#include "data.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "soinua.h"
#include "text.h"
#include <stdio.h>

int irudiaKargatu(char *fileName);
void irudiaMugitu(int numImg, int x, int y);
void irudiakMarraztuMapa(void);
void irudiakMarraztu(nibela mapa);
void irudiaKendu(int id);

#endif
