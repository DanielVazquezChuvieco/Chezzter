#include "musica.h"
#include "ETSIDI.h"

void Musica::reproducir() {
    ETSIDI::playMusica("sonidos/iba.mp3", true);
}

