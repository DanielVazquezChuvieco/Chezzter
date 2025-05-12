#include <iostream>
#include <string>
#define FILAS 8

using namespace std;

// Clase base abstracta
class Pieza {
protected:
    string color;
public:
    Pieza(string c) : color(c) {}
    virtual ~Pieza() {}
    virtual char simbolo() const = 0;
    string obtenerColor() const { return color; }
    virtual bool MovimientoValido(int filaorigen, int columnaorigen, int filafin, int columnafin, Pieza* destino, Pieza* tablero[8][8]) const = 0;
};


// Clase Rey (ejemplo de una pieza)
class Rey : public Pieza {
public:
    Rey(string c) : Pieza(c) {}
    char simbolo() const override {
        return (color == "blancas") ? 'R' : 'r';
    }
    bool MovimientoValido(int filaorigen, int columnaorigen, int filafin, int columnafin, Pieza* destino, Pieza* tablero[8][8]) const override {
        int df = abs(filafin - filaorigen);
        int dc = abs(columnafin - columnaorigen);

        // Rey se puede mover 1 casilla en cualquier dirección
        if (df <= 1 && dc <= 1) {
            // No puede capturar su propia pieza
            return (!destino || destino->obtenerColor() != this->obtenerColor());
        }
        return false;
    }
};

class Torre : public Pieza {
public:
    Torre(string c) : Pieza(c) {}
    char simbolo() const override {
        return (color == "blancas") ? 'T' : 't';
    }
    bool MovimientoValido(int filaorigen, int columnaorigen, int filafin, int columnafin, Pieza* destino, Pieza* tablero[8][8]) const override {
        int df = abs(filafin - filaorigen);
        int dc = abs(columnafin - columnaorigen);

        // Rey se puede mover 1 casilla en cualquier dirección
        if ((df <= 8 && dc == 0) || (df == 0 && dc <= 8)) {
            // No puede capturar su propia pieza
            return (!destino || destino->obtenerColor() != this->obtenerColor());
        }
        return false;
    }
};

class Caballo : public Pieza {
public:
    Caballo(string c) : Pieza(c) {}
    char simbolo() const override {
        return (color == "blancas") ? 'C' : 'c';
    }
    bool MovimientoValido(int filaorigen, int columnaorigen, int filafin, int columnafin, Pieza* destino, Pieza* tablero[8][8]) const override {
        int df = abs(filafin - filaorigen);
        int dc = abs(columnafin - columnaorigen);

        // Rey se puede mover 1 casilla en cualquier dirección  
        if ((df <= 2 && dc == 1) || (df == 1 && dc <= 2)) {
            // No puede capturar su propia pieza
            return (!destino || destino->obtenerColor() != this->obtenerColor());
        }
        return false;
    }
};

class Alfil : public Pieza {
public:
    Alfil(string c) : Pieza(c) {}
    char simbolo() const override {
        return (color == "blancas") ? 'A' : 'a';

    }
    bool MovimientoValido(int filaorigen, int columnaorigen, int filafin, int columnafin, Pieza* destino, Pieza* tablero[8][8]) const override {
        int df = abs(filafin - filaorigen);
        int dc = abs(columnafin - columnaorigen);

        // Rey se puede mover 1 casilla en cualquier dirección
        if (df == dc) {
            // No puede capturar su propia pieza
            return (!destino || destino->obtenerColor() != this->obtenerColor());
        }
        return false;
    }
};


class Reina : public Pieza {
public:
    Reina(string c) : Pieza(c) {}
    char simbolo() const override {
        return (color == "blancas") ? 'Q' : 'q';
    }
    bool MovimientoValido(int filaorigen, int columnaorigen, int filafin, int columnafin, Pieza* destino, Pieza* tablero[8][8]) const override {
        int df = abs(filafin - filaorigen);
        int dc = abs(columnafin - columnaorigen);

        // Rey se puede mover 1 casilla en cualquier dirección
        if (df <= 7 && dc <= 7) {
            // No puede capturar su propia pieza
            return (!destino || destino->obtenerColor() != this->obtenerColor());
        }
        return false;
    }
};


class Peon : public Pieza {
public:
    Peon(string c) : Pieza(c) {}
    char simbolo() const override {
        return (color == "blancas") ? 'P' : 'p';
    }
    bool MovimientoValido(int filaorigen, int columnaorigen, int filafin, int columnafin, Pieza* destino, Pieza* tablero[8][8]) const override {

        int df = (filafin - filaorigen);
        int dc = abs(columnafin - columnaorigen);

        if ((color == "blancas" && filaorigen == 6) || (color == "negras" && filaorigen == 1)) {
            if ((df == -2 && dc == 0 && color == "blancas" && destino == nullptr) || (df == 2 && dc == 0 && color == "negras" && destino == nullptr))
                return true;

            int nosalta = (filaorigen + filafin) / 2;
            if (tablero[nosalta][columnaorigen] == nullptr && destino == nullptr) {
                return true;
            }
        }
        // Peon se mueve en su fila
        if ((df == -1 && dc == 0 && color == "blancas" && destino == nullptr) || (df == 1 && dc == 0 && color == "negras" && destino == nullptr)) {
            // No puede capturar su propia pieza
            return true;
        }

        if ((df == -1 && dc == 1 && color == "blancas" && destino->obtenerColor() != color) || (df == 1 && dc == 1 && color == "negras" && destino->obtenerColor() != color))
            return true;

        else
            return false;
    }

};



// Clase Tablero
class Tablero {
private:
    Pieza* casillas[8][8];
public:
    Tablero() {
        // Inicializa el tablero con nullptrs
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                casillas[i][j] = nullptr;
    }

    ~Tablero() {
        // Liberar memoria de piezas
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                delete casillas[i][j];
    }

    void inicializar() {
        // Coloca solo los reyes como ejemplo
        casillas[0][0] = new Torre("negras");
        casillas[0][7] = new Torre("negras");
        casillas[7][0] = new Torre("blancas");
        casillas[7][7] = new Torre("blancas");

        casillas[0][1] = new Caballo("negras");
        casillas[0][6] = new Caballo("negras");
        casillas[7][1] = new Caballo("blancas");
        casillas[7][6] = new Caballo("blancas");

        casillas[0][2] = new Alfil("negras");
        casillas[0][5] = new Alfil("negras");
        casillas[7][2] = new Alfil("blancas");
        casillas[7][5] = new Alfil("blancas");

        casillas[0][3] = new Reina("negras");
        casillas[7][3] = new Reina("blancas");

        casillas[0][4] = new Rey("negras");   // Rey negro
        casillas[7][4] = new Rey("blancas");  // Rey blanco

        for (int i = 0; i < FILAS; i++) {
            casillas[1][i] = new Peon("negras");
            casillas[6][i] = new Peon("blancas");
        }
    }

    void mostrar() {
        cout << "  A B C D E F G H\n";
        for (int i = 0; i < 8; ++i) {
            cout << i << " ";
            for (int j = 0; j < 8; ++j) {
                if (casillas[i][j])
                    cout << casillas[i][j]->simbolo() << " ";
                else
                    cout << ". ";
            }
            cout << 8 - i << "\n";
        }
        cout << "  A B C D E F G H\n";
    }

    Pieza* obtenerPieza(int fila, int col) {
        if (fila < 0 || fila >= 8 || col < 0 || col >= 8)
            return nullptr;
        return casillas[fila][col];
    }

    bool MoverPieza(int filaorigen, int filafin, int columnaorigen, int columnafin, string turnocolor) {
        if (filaorigen < 0 || filaorigen >= 8 || columnaorigen < 0 || columnaorigen >= 8 ||
            filafin < 0 || filafin >= 8 || columnafin < 0 || columnafin >= 8) {
            cout << "Movimiento fuera de rango\n";
            return false;
        }

        Pieza* origen = casillas[filaorigen][columnaorigen];
        Pieza* destino = casillas[filafin][columnafin];

        if (!origen) {
            cout << "No hay pieza en la posición de origen\n";
            return false;
        }

        cout << "Color de la pieza: " << origen->obtenerColor() << ", Turno actual: " << turnocolor << endl;

        if (origen->obtenerColor() != turnocolor) {
            cout << "No puedes mover piezas del otro jugador\n";
            return false;
        }


        if (origen->MovimientoValido(filaorigen, columnaorigen, filafin, columnafin, destino, casillas)) {

            delete destino;  // capturar pieza si existe
            casillas[filafin][columnafin] = origen;
            casillas[filaorigen][columnaorigen] = nullptr;
            return true;
        }

        else {
            cout << "Movimiento inválido para esa pieza\n";
            return false;
        }
    }
};


int main() {
    int fo, ff, co, cf;
    string turno = "blancas";
    Tablero tablero;
    tablero.inicializar();
    tablero.mostrar();
    while (1) {

        cout << "\nMueven " << turno << "\n";
        cin >> fo >> ff >> co >> cf;
        if (tablero.MoverPieza(fo, ff, co, cf, turno)) {
            turno = (turno == "blancas") ? "negras" : "blancas";
        }
        tablero.mostrar();

    }
    return 0;

}