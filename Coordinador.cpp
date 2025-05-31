#include "Coordinador.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include "juego.h"
#include <chrono>
#include <thread>



juego Juego;
Estado estado = MENU;
Estado Coordinador::getEstado() {
    return estado;
}

void Coordinador::dibujapantallamenu() {
   
    //estado = MENU;
    // --- Dibujar el fondo de pantalla según el estado actual ---
    switch (estado) {
    case MENU:

        std::cout << "hola estoy en menu" << std::endl;
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo_menu.png").id); //HAY QUE METER DONDE fondo EL NOMBRE DE LA FOTO QUE SE ELIJA 
        glDisable(GL_LIGHTING); //Esta ni penseis en quitarla

        glColor3f(1.0f, 1.0f, 1.0f);  // para que se vea con su color real

        glBegin(GL_POLYGON); //Defino el cuadrado en el que se va a pegar la imagen
        glTexCoord2d(0, 0); glVertex2f(0, 0); //Limite abajo izquierda
        glTexCoord2d(1, 0); glVertex2f(800, 0); //Limite abajo derecha
        glTexCoord2d(1, 1); glVertex2f(800, 800); //Limite arriba derecha
        glTexCoord2d(0, 1); glVertex2f(0, 800); //Origen arriba izq
        glEnd();

        // glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
    //    std::this_thread::sleep_for(std::chrono::milliseconds(3000)); // Espera 3 segundo

        break;
    case JUEGO:
        //Juego.reiniciarJuego();
        Juego.dibuja();
       

        
        break;
    case INSTRUCCIONES:
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo_instrucciones.png").id); //HAY QUE METER DONDE fondo EL NOMBRE DE LA FOTO QUE SE ELIJA 
        glDisable(GL_LIGHTING); //Esta ni penseis en quitarla

        glColor3f(1.0f, 1.0f, 1.0f);  // para que se vea con su color real

        glBegin(GL_POLYGON); //Defino el cuadrado en el que se va a pegar la imagen
        glTexCoord2d(0, 0); glVertex2f(0, 0); //Limite abajo izquierda
        glTexCoord2d(1, 0); glVertex2f(800, 0); //Limite abajo derecha
        glTexCoord2d(1, 1); glVertex2f(800, 800); //Limite arriba derecha
        glTexCoord2d(0, 1); glVertex2f(0, 800); //Origen arriba izq
        glEnd();

        // glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);


        break;
    case CONTROLES:
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo_controles.png").id); //HAY QUE METER DONDE fondo EL NOMBRE DE LA FOTO QUE SE ELIJA 
        glDisable(GL_LIGHTING); //Esta ni penseis en quitarla

        glColor3f(1.0f, 1.0f, 1.0f);  // para que se vea con su color real

        glBegin(GL_POLYGON); //Defino el cuadrado en el que se va a pegar la imagen
        glTexCoord2d(0, 0); glVertex2f(0, 0); //Limite abajo izquierda
        glTexCoord2d(1, 0); glVertex2f(800, 0); //Limite abajo derecha
        glTexCoord2d(1, 1); glVertex2f(800, 800); //Limite arriba derecha
        glTexCoord2d(0, 1); glVertex2f(0, 800); //Origen arriba izq
        glEnd();

        // glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);

        break;


    case GANA_BLANCAS:
        //  ETSIDI::play("sonidos/astro.mp3");

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Astro_gana.png").id); //HAY QUE METER DONDE fondo EL NOMBRE DE LA FOTO QUE SE ELIJA 
       // glDisable(GL_LIGHTING); //Esta ni penseis en quitarla

        glColor3f(1.0f, 1.0f, 1.0f);  // para que se vea con su color real
        glDisable(GL_LIGHTING); //Esta ni penseis en quitarla
        glBegin(GL_POLYGON); //Defino el cuadrado en el que se va a pegar la imagen
        glTexCoord2d(0, 0); glVertex2f(0, 0); //Limite abajo izquierda
        glTexCoord2d(1, 0); glVertex2f(800, 0); //Limite abajo derecha
        glTexCoord2d(1, 1); glVertex2f(800, 800); //Limite arriba derecha
        glTexCoord2d(0, 1); glVertex2f(0, 800); //Origen arriba izq
        glEnd();

        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
        // glDisable(GL_TEXTURE_2D);
         //glutSwapBuffers();
       
        estado = BORRADO;
        break;
    case GANA_NEGRAS:
        //   else if (estado == GANA_NEGRAS) {
               //   ETSIDI::play("sonidos/alien.mp3");

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Alien_gana.png").id); //HAY QUE METER DONDE fondo EL NOMBRE DE LA FOTO QUE SE ELIJA 
        glDisable(GL_LIGHTING); //Esta ni penseis en quitarla

        glColor3f(1.0f, 1.0f, 1.0f);  // para que se vea con su color real

        glBegin(GL_POLYGON); //Defino el cuadrado en el que se va a pegar la imagen
        glTexCoord2d(0, 0); glVertex2f(0, 0); //Limite abajo izquierda
        glTexCoord2d(1, 0); glVertex2f(800, 0); //Limite abajo derecha
        glTexCoord2d(1, 1); glVertex2f(800, 800); //Limite arriba derecha
        glTexCoord2d(0, 1); glVertex2f(0, 800); //Origen arriba izq
        glEnd();

        // glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
        break;
    case BORRADO:
        Juego.reiniciarJuego();
        break;

    }

   
}

void Coordinador::tecla(unsigned char tecla) {

    switch (estado) {


    case MENU:
        if (tecla == '1') { // ASCII for '1'
            
           
            glutPostRedisplay();
            
            estado = JUEGO;
        }
        else if (tecla == '2') { // ASCII for '2'
            estado = INSTRUCCIONES;
        }
        else if (tecla == '3') { // ASCII for '3'
            estado = CONTROLES;
        }
        else if (tecla == 27) { // ASCII for ESC key
            exit(0);
        }
        break; // IMPORTANT: Add break here for MENU case

    case INSTRUCCIONES:
        if (tecla == '4') { // ASCII for '1'
            estado = MENU;
        }
        break;
    case JUEGO:
       // Juego.dibuja();
       
        if (tecla =='R' || tecla=='r') { // ASCII for '1'
            estado =  MENU;
            
           
        }
        else if (tecla == 27)
            exit(0);
        break;
 

    case CONTROLES:
        if (tecla == '4') { // ASCII for '1'
            estado = MENU;
        }
        break;

    }
}

void Coordinador::setResultado(Estado r) {
    estado = r;
}


