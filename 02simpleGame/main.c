#include "data.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "lib/game02.h"
#include "ourTypes.h"
#include "soinua.h"
#include "text.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *str[])
{
    partidako_data partida;
    partida = partidakoDataKargatu();

    sgHasieratu();
    textuaGaitu();
    audioInit();

    jokoaAurkeztu();
    loadTheMusic("./sound/gameMusic.wav");
    toggleMusic();
    while (partida.nibel < 6)
    {
        partida = jokatu(partida);
    }
    if (partida.nibel!=10)
    {
        jokoaBukatu(partida);
    }
    sgItxi();
    return 0;
}