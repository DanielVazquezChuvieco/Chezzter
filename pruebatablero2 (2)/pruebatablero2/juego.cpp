#include "juego.h"
#include "freeglut.h"
#include "peon.h"
#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
#include <iostream>
#include "ETSIDI.h"

using namespace std;


void juego::dibuja()
{
    Tablero.dibuja();  //Dibuja el tablero y piezasen pantalla
}


void juego::iniciarArrastre(int x, int y) {
    cout << "\n=== INICIANDO ARRASTRE ===" << endl;
    cout << "Coordenadas click: (" << x << ", " << y << ")" << endl;

    //Convierte las coordenadas de pantalla a la posición de la casilla del tablero y lo muestra por consola
    int fila = (y - 100) / 75;
    int col = (x - 100) / 75;
    cout << "Casilla calculada: (" << fila << ", " << col << ")" << endl;

    if (fila >= 0 && fila < 8 && col >= 0 && col < 8) {  //Comprueba que el clic está dentro del tablero
        if (Tablero.at(fila, col).hayPieza()) {   //Si hay una pieza en la casilla, obtiene un puntero a la pieza y muestra su tipo y color
            Pieza* pieza = Tablero.at(fila, col).getPieza();
            bool esBlanca = pieza->esBlanca();
            std::string colorPieza = esBlanca ? "BLANCO" : "NEGRO";
            cout << "Pieza encontrada: " << typeid(*pieza).name() << " Color: " << colorPieza << endl;

            if (esBlanca != turnoBlanco) {
                cout << "Intento de mover pieza contraria! Turno actual: " << (turnoBlanco ? "BLANCO" : "NEGRO") << endl;
                return;
            }
            //Si es el turno correcto, guarda la pieza
            piezaArrastrada = pieza;
            filaOrigen = fila;  //Guarda su posición de origen
            colOrigen = col;
            arrastrando = true;  //activa el modo arrastre

            cout << "Iniciando arrastre de pieza desde (" << filaOrigen << ", " << colOrigen << ")" << endl;
            piezaArrastrada->setPosicionGraficaPixel(x, y);  //actualiza la posición gráfica de la pieza del drag
        }
        else {
            cout << "No hay pieza en (" << fila << ", " << col << ")" << endl;  //Si no hay pieza lo indica
        }
    }
    else {
        cout << "Click fuera del tablero" << endl;  //Si está fuera del tablero lo indica
    }
}

//Mientras el usuario arrastra la pieza, imprime la posición actual del ratón y actualiza la plsicion gráfica de la pieza para que siga el cursos
void juego::actualizarArrastre(int x, int y) {
    if (arrastrando && piezaArrastrada) {
        cout << "Actualizando posicion arrastre: (" << x << ", " << y << ")" << endl;
        piezaArrastrada->setPosicionGraficaPixel(x, y);
        glutPostRedisplay();  //LLamada al glutPostRedisplay para redibujar la pantalla
    }
}

void juego::finalizarArrastre(int x, int y) {
    cout << "\n=== FINALIZANDO ARRASTRE ===" << endl;  //Imprime que el arrastre ha finalizado

    if (arrastrando && piezaArrastrada) {  //Si hay una pieza siendo arrastrada calcula e imprime la casilla de destino
        int filaDestino = (y - 100) / 75;
        int colDestino = (x - 100) / 75;

        cout << "Posicion destino calculada: (" << filaDestino << ", " << colDestino << ")" << endl;
        cout << "Tipo de pieza: " << typeid(*piezaArrastrada).name() << endl;

        //Inicializamos variables para saber si el movimiento es válido y el tipo de pieza
        bool movimientoValido = false;
        string tipoPieza = "Desconocida";

        //Intentamos conertir el puntero a cada tipo de pieza para llamar a su método específico movimientoValido
        if (peon* p = dynamic_cast<peon*>(piezaArrastrada)) {
            tipoPieza = "Peon";  //Guarda el tipo de pieza para mostrarlo
            movimientoValido = p->movimientoValido(filaOrigen, colOrigen, filaDestino, colDestino, Tablero);
        }
        else if (Torre* t = dynamic_cast<Torre*>(piezaArrastrada)) {
            tipoPieza = "Torre";
            movimientoValido = t->movimientoValido(filaOrigen, colOrigen, filaDestino, colDestino, Tablero);
        }
        else if (Alfil* a = dynamic_cast<Alfil*>(piezaArrastrada)) {
            tipoPieza = "Alfil";
            movimientoValido = a->movimientoValido(filaOrigen, colOrigen, filaDestino, colDestino, Tablero);
        }
        else if (Caballo* c = dynamic_cast<Caballo*>(piezaArrastrada)) {
            tipoPieza = "Caballo";
            movimientoValido = c->movimientoValido(filaOrigen, colOrigen, filaDestino, colDestino, Tablero);
        }
        else if (Reina* r = dynamic_cast<Reina*>(piezaArrastrada)) {
            tipoPieza = "Reina";
            movimientoValido = r->movimientoValido(filaOrigen, colOrigen, filaDestino, colDestino, Tablero);
        }
        else if (Rey* rey = dynamic_cast<Rey*>(piezaArrastrada)) {
            tipoPieza = "Rey";
            movimientoValido = rey->movimientoValido(filaOrigen, colOrigen, filaDestino, colDestino, Tablero);
        }

        //  imprime si el movimiento es válido o no
        cout << "Validacion movimiento (" << tipoPieza << "): " << (movimientoValido ? "VALIDO" : "INVALIDO") << endl;

        if (movimientoValido && filaDestino >= 0 && filaDestino < 8 && colDestino >= 0 && colDestino < 8){  //Si el movimiento es válido y dentro del tablero
            Pieza* compjaque = Tablero.at(filaDestino, colDestino).getPieza();

            
            Tablero.at(filaDestino, colDestino).set(piezaArrastrada);  //actualiza la posición de la pieza
            Tablero.at(filaOrigen, colOrigen).set(nullptr);
            piezaArrastrada->setFila(filaDestino);
            piezaArrastrada->setColumna(colDestino);
          
          
            if (Tablero.estaEnJaque(turnoBlanco)) {
                Tablero.at(filaOrigen, colOrigen).set(piezaArrastrada);
                Tablero.at(filaDestino, colDestino).set(compjaque);
                piezaArrastrada->setFila(filaOrigen);
                piezaArrastrada->setColumna(colOrigen);
                piezaArrastrada->setPosicionGrafica();

                cout << "¡Movimiento invalido! Tu rey quedaria en jaque." << endl;
            }
            else {
                piezaArrastrada->setPosicionGrafica();
                cout << "Realizando movimiento de (" << filaOrigen << ", " << colOrigen << ") a (" << filaDestino << ", " << colDestino << ")" << endl;
                cout << "Las" << (turnoBlanco ? "BLANCO" : "NEGRO") << " no estan en jaque" << endl;
                cout << "Turno anterior: " << (turnoBlanco ? "BLANCO" : "NEGRO") << endl;
                turnoBlanco = !turnoBlanco; // Cambia el turno
                cout << "Nuevo turno: " << (turnoBlanco ? "BLANCO" : "NEGRO") << endl;
                if (Tablero.estaEnJaque(turnoBlanco)) {
                    std::cout << "¡" << (turnoBlanco ? "BLANCO" : "NEGRO") << " esta en JAQUE!" << std::endl;
                }
            }
            
           
        }
        else {  //Si no es válido muestra posibles razones 
            cout << "Movimiento invalido! Razones posibles:" << endl;
            cout << "- Destino fuera del tablero: " << (filaDestino < 0 || filaDestino >= 8 || colDestino < 0 || colDestino >= 8) << endl;
            cout << "- Movimiento no permitido para la pieza" << endl;
            cout << "- Intento de capturar pieza propia" << endl;
            cout << "LAS" << (turnoBlanco ? "BLANCO" : "NEGRO") << " ESTAN EN JAQUE MUEVE OTRA" << endl;
            piezaArrastrada->setPosicionGrafica(); // Devuelve la pieza a su sitio original
        }
        piezaArrastrada = nullptr;  //Ya no está arrastrando pieza
        arrastrando = false;
       // Tablero.aplicarGravedad();  //Aplica gravedad si hay huecos debajo
        glutPostRedisplay();  //Redibuja la pantalla
    }
    else {
        cout << "Arrastre finalizado sin pieza seleccionada" << endl;  //Si no había pieza seleccionada al soltar lo indica
    }
}