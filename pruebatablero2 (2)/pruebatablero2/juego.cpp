#include "juego.h"
#include "freeglut.h"
#include "peon.h"
#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
#include <iostream>

using namespace std;


void juego::dibuja() {
	Tablero.dibuja();

	//iran todos los dibujas
}

void juego::clickRaton(int x, int y) {
    int fila = (y - 100) / 75;
    int col = (x - 100) / 75;

    cout << "Click en: (" << fila << ", " << col << ")" << endl;
    cout << "Estado esperandoSegundoClick: " << esperandoSegundoClick << endl;

    if (!esperandoSegundoClick) {
        if (fila >= 0 && fila < 8 && col >= 0 && col < 8) {
            if (Tablero.at(fila, col).hayPieza()) {
                Pieza* pieza = Tablero.at(fila, col).getPieza();
                if (!esTurnoDe(pieza->obtenerColor())) {
                    cout << "No es el turno de esta pieza.\n";
                    return;
                }

                filaOrigen = fila;
                colOrigen = col;
                cout << "Hay pieza en origen" << endl;
                esperandoSegundoClick = true;
            }
            else {
                cout << "No hay pieza en (" << fila << ", " << col << ")" << endl;
            }
        }
        else {
            cout << "Click fuera del tablero en primer clic" << endl;
        }
    }
    else {
        cout << "Entrando al segundo click (Destinoo)" << endl;

        if (filaOrigen >= 0 && filaOrigen < 8 && colOrigen >= 0 && colOrigen < 8 &&
            fila >= 0 && fila < 8 && col >= 0 && col < 8) {

            cout << "Verificando casilla origen: (" << filaOrigen << ", " << colOrigen << ")" << endl;

            Casilla& origen = Tablero.at(filaOrigen, colOrigen);
            Casilla& destino = Tablero.at(fila, col);

            if (origen.hayPieza()) {
                cout << "Origen tiene pieza" << endl;

                Pieza* pieza = origen.getPieza();
                if (pieza) {
                    cout << "Puntero a pieza válido" << endl;

                    // Validación para peón
                    peon* peonPtr = dynamic_cast<peon*>(pieza);  //convierte el puntero pieza a un puntero derivado peon
                    if (peonPtr) {                                //si se ha convertido el puntero correctamente entonces:
                        if (!peonPtr->movimientoValido(filaOrigen, colOrigen, fila, col, Tablero)) {  //llamada a su método movimientoValido, si no es válido muestra un mensaje por consola
                            cout << "Movimiento de peón inválido" << endl;
                            esperandoSegundoClick = false;  //se cancela el estado de espera del segundo click
                            return;
                        }
                    }

                    // Validación para torre
                    Torre* torrePtr = dynamic_cast<Torre*>(pieza);  //convierte el puntero pieza a un puntero derivado torre
                    if (torrePtr) {                                 //si se ha convertido el puntero correctamente entonces:
                        if (!torrePtr->movimientoValido(filaOrigen, colOrigen, fila, col, Tablero)) {  //llamada a su método movimientoVálido, si no es válido muestra un mensaje por consola
                            cout << "Movimiento de torre inválido" << endl;
                            esperandoSegundoClick = false;   //se cancela el estado de espera del segundo click
                            return;
                        }
                    }
                    //Validación para caballo
                    Caballo* caballoPtr = dynamic_cast<Caballo*>(pieza);  //convierte el puntero pieza a un puntero derivado caballo
                    if (caballoPtr) {                                 //si se ha convertido el puntero correctamente entonces: 
                        if (!caballoPtr->movimientoValido(filaOrigen, colOrigen, fila, col, Tablero)) {   //llamada a su método movimientoVálido, si no es válido muestra mensaje por consola
                            cout << "Movimiento de alfil inválido" << endl;
                            esperandoSegundoClick = false;  //se cancela el estado de espera del segundo click
                            return;
                        }
                    }

                    //Validación para alfil
                    Alfil* alfilPtr = dynamic_cast<Alfil*>(pieza);  //convierte el puntero pieza a un puntero derivado alfil
                    if (alfilPtr) {                                 //si se ha convertido el puntero correctamente entonces: 
                        if (!alfilPtr->movimientoValido(filaOrigen, colOrigen, fila, col, Tablero)) {   //llamada a su método movimientoVálido, si no es válido muestra mensaje por consola
                            cout << "Movimiento de alfil inválido" << endl;
                            esperandoSegundoClick = false;  //se cancela el estado de espera del segundo click
                            return;
                        }
                    }

                    //Validación para reina
                    Reina* reinaPtr = dynamic_cast<Reina*>(pieza);  //convierte el puntero pieza a un puntero derivado reina
                    if (reinaPtr) {                                 //si se ha convertido el puntero correctamente entonces: 
                        if (!reinaPtr->movimientoValido(filaOrigen, colOrigen, fila, col, Tablero)) {   //llamada a su método movimientoVálido, si no es válido muestra mensaje por consola
                            cout << "Movimiento de alfil inválido" << endl;
                            esperandoSegundoClick = false;  //se cancela el estado de espera del segundo click
                            return;
                        }
                    }

                    //Validación para rey
                    Rey* reyPtr = dynamic_cast<Rey*>(pieza);  //convierte el puntero pieza a un puntero derivado rey
                    if (reyPtr) {                                 //si se ha convertido el puntero correctamente entonces: 
                        if (!reyPtr->movimientoValido(filaOrigen, colOrigen, fila, col, Tablero)) {   //llamada a su método movimientoVálido, si no es válido muestra mensaje por consola
                            cout << "Movimiento de alfil inválido" << endl;
                            esperandoSegundoClick = false;  //se cancela el estado de espera del segundo click
                            return;
                        }
                    }
                    destino.set(pieza);
                    origen.set(nullptr);
                    
                    pieza->setFila(fila);
                    pieza->setColumna(col);
                    pieza->setPosicionGrafica();
                    cambiarTurno();
                   

                    cout << "Movimiento realizado a (" << fila << ", " << col << ")" << endl;
                }
                else {
                    cout << "Puntero a pieza es NULL" << endl;
                }
            }
            else {
                cout << "Origen NO tiene pieza (aunque debería)" << endl;
            }
        }
        else {
            cout << "Coordenadas fuera de rango en segundo clic" << endl;
        }
        Tablero.aplicarGravedad();
        esperandoSegundoClick = false;
        glutPostRedisplay();
    }
}

std::string juego::obtenerTurnoActual() const {
    return turnoActual;
}

void juego::cambiarTurno() {
    turnoActual = (turnoActual == "BLANCO") ? "NEGRO" : "BLANCO";
}

bool juego::esTurnoDe(const std::string& color) const {
    return turnoActual == color;
}