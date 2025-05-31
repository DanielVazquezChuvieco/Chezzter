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

    if (coordinador.getEstado() == GANA_BLANCAS || coordinador.getEstado() == GANA_NEGRAS) {
        cout << "FIN DE MISION: preparando informe de batalla interestelar..." << endl;

        coordinador.dibujapantallamenu();

        reiniciarJuego();
        return;
    }
    
    Tablero.dibuja();
}


void juego::iniciarArrastre(int x, int y) {
    cout << "\n=== INICIANDO DESPLAZAMIENTO === " << endl;
    cout << "OBJETIVO FIJADO: posicion tactica en el cuadrante (" << x << ", " << y << ")" << endl;

    //Convierte las coordenadas de pantalla a la posición de la casilla del tablero y lo muestra por consola
    int fila = (y - 100) / 75;
    int col = (x - 100) / 75;
    cout << "LOCALIZACION EXACTA: (" << fila << ", " << col << ")" << endl;

    if (fila >= 0 && fila < 8 && col >= 0 && col < 8) {  //Comprueba que el clic está dentro del tablero
        if (Tablero.at(fila, col).hayPieza()) {   //Si hay una pieza en la casilla, obtiene un puntero a la pieza y muestra su tipo y color
            Pieza* pieza = Tablero.at(fila, col).getPieza(); // Se coje la posición de la pieza pulsada
            bool esBlanca = pieza->esBlanca(); // Se obtien el color
            cout << "Vida encontrada:  " << pieza->nombre() << endl; //para pillar el tipo de pieza que es, se hace con polimorfismo

            if (esBlanca != turnoBlanco) { //Default Turnoblanco = 1
                cout << "ESPERA! La nave de los " << (turnoBlanco ? "ASTRONAUTA" : "ALIEN")<< " esta desplazandose. (TURNO INCORRECTO) " << endl;
                return;
            }
            //Si es el turno correcto, guarda la pieza
            piezaArrastrada = pieza;
            filaOrigen = fila;  //Guarda su posición de origen
            colOrigen = col;
            arrastrando = true;  //activa el modo arrastre

            cout << "Iniciando transporte desde la posicion de origen (" << filaOrigen << ", " << colOrigen << ")" << endl;
            piezaArrastrada->setPosicionGraficaPixel(x, y);  //actualiza la posición gráfica de la pieza del drag
        }
        else {
            cout << "No hay vida en (" << fila << ", " << col << ")" << endl;  //Si no hay pieza lo indica
        }
    }
    else {
        cout << "No hay nada en esta zona de la galaxia" << endl;  //Si está fuera del tablero lo indica
    }
}

//Mientras el usuario arrastra la pieza, imprime la posición actual del ratón y actualiza la plsicion gráfica de la pieza para que siga el cursos
void juego::actualizarArrastre(int x, int y) {
    if (arrastrando && piezaArrastrada) {
        piezaArrastrada->setPosicionGraficaPixel(x, y);
        glutPostRedisplay();  //LLamada al glutPostRedisplay para redibujar la pantalla
    }
}

void juego::finalizarArrastre(int x, int y) {
    std::cout << "\n=== FINALIZANDO DESPLAZAMIENTO ===" << endl;

    if (arrastrando && piezaArrastrada) {
        int filaDestino = (y - 100) / 75;
        int colDestino = (x - 100) / 75;
        if (filaDestino >= 0 && filaDestino < 8 && colDestino >= 0 && colDestino < 8) { // Para que no crashe si se va fuera del tablero
            if (filaDestino == filaOrigen && colDestino == colOrigen) { //Si pieza origen == pieza destino
                std::cout << "Desplazamiento nulo." << std::endl;
                piezaArrastrada->setPosicionGrafica();
                piezaArrastrada = nullptr;
                arrastrando = false;
                glutPostRedisplay();
                return;
            }

            bool movimientoValido = piezaArrastrada->movimientoValido(filaOrigen, colOrigen, filaDestino, colDestino, Tablero);

            cout << "El movimiento de " << piezaArrastrada->nombre() << (movimientoValido ? " ES VALIDO" : "NO ES VALIDO") << endl;

            if (movimientoValido && filaDestino >= 0 && filaDestino < 8 && colDestino >= 0 && colDestino < 8) {
                Pieza* destinoAnterior = Tablero.at(filaDestino, colDestino).getPieza();

                // Simular para evitar mover a jaque
                if (!simularMovimientoConGravedadYVerificar(filaOrigen, colOrigen, filaDestino, colDestino)) {
                  cout << "El desplazamiento dejaria a tu rey en peligro.... BUSQUEMOS OTRAS OPCIONES" << endl;
                  piezaArrastrada->setPosicionGrafica();
                }
                else {
                    if (destinoAnterior && destinoAnterior != piezaArrastrada)
                        delete destinoAnterior;
                    // Ejecutar el movimiento real
                    Tablero.at(filaDestino, colDestino).set(piezaArrastrada);
                    Tablero.at(filaOrigen, colOrigen).set(nullptr);
                    piezaArrastrada->setFila(filaDestino);
                    piezaArrastrada->setColumna(colDestino);
                    piezaArrastrada->setPosicionGrafica();


                    cout << "Desplazamiento realizado correctamente." << endl;



                 
                    // Sonidos
                    if (turnoBlanco) {
                        ETSIDI::play("sonidos/astro_move.mp3");
                    }
                    else {
                        ETSIDI::play("sonidos/alien_move2.mp3");
                    }
                    // Cambio de turno
                    turnoBlanco = !turnoBlanco;
                    cout << "Turno de los: " << (turnoBlanco ? "ASTRONAUTAS" : "ALIENS") << endl;
                }
            }
            else {
                cout << "Desplazamiento invalido." << endl;
                piezaArrastrada->setPosicionGrafica();
            }
        }
        else {
            std::cout << "No hay " << (turnoBlanco ? "ASTRONAUTAS" : "ALIENS") << " en ese zona de la galaxia" << endl;
            piezaArrastrada->setPosicionGrafica();
            piezaArrastrada = nullptr;
            arrastrando = false;
            glutPostRedisplay();
            return;
        }


    }
    else {
        std::cout << "No habia ninguna forma de vida seleccionada." << std::endl;
    }
    // Reset de parametros para volver a arrastrar
    piezaArrastrada = nullptr;
    arrastrando = false;
    glutPostRedisplay();
}

bool juego::simularMovimientoConGravedadYVerificar(int filaOrigen, int colOrigen, int filaDestino, int colDestino) {
    tablero copia = Tablero.copiar(); // Copiamos el tablero actual para no modificar el tablero original y poder evaluar
    
    Pieza* pieza = copia.at(filaOrigen, colOrigen).getPieza();

    if (!pieza->movimientoValido(filaOrigen, colOrigen, filaDestino, colDestino, copia)) // Movimiento invalido sale de la funcion
        return false;

    // Movimiento simulado
    copia.at(filaDestino, colDestino).set(pieza);
    copia.at(filaOrigen, colOrigen).set(nullptr);
    pieza->setFila(filaDestino);
    pieza->setColumna(colDestino);

    // Aplicar gravedad
    copia.aplicarGravedad();

    // Verificar si el rey queda en jaque
    return !copia.estaEnJaque(pieza->esBlanca()); // Si queda en jaque retur false
}

void juego::postGravedad() {
    // Verificar jaque y jaque mate 
    bool rivalBlanco = turnoBlanco;
    if (Tablero.estaEnJaque(rivalBlanco)) {
        std::cout << (rivalBlanco ? "REY ASTRONAUTA" : "REY ALIENIGENA") << " esta en JAQUE!" << std::endl;
        if (Tablero.esJaqueMate(rivalBlanco)) {
            std::cout << "JAQUE MATE! Ha ganado " << (turnoBlanco ? "LA ESPECIE HUMANA" : "LA ESPECIE ALIENIGENA") << std::endl;
            coordinador.setResultado((turnoBlanco ? GANA_NEGRAS : GANA_BLANCAS));
            glutPostRedisplay();
            return;
        }
    }
}

void juego::reiniciarJuego(){
    Tablero.limpiar(); // delete de las piezas  
    Tablero.colocapiezas(); // colocarlas de nuevo
    turnoBlanco = true; 
    cout << "BATALLA REINICIADA... Empiezan astronautas" << endl;
}



