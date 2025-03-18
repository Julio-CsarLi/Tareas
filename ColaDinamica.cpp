#include <iostream>

class constancia {
private:
    std::string Alumno;
    std::string Carrera;
    std::string Materias;
    float Promedio;

public:
    constancia(std::string alumno = " ", std::string carrera = " ", std::string materias = " ", float promedio = 0.0)
    : Alumno(alumno), Carrera(carrera), Materias(materias), Promedio(promedio) {}

    friend std::ostream& operator<<(std::ostream& o, const constancia& p) {
        o << "El nombre del alumno es: " << p.Alumno << "\n";
        o << "La carrera a la que pertenece el alumno es: " << p.Carrera << "\n";
        o << "Estas son las materias aprobadas por el alumno: " << p.Materias << "\n";
        o << "El promedio final del alumno es de: " << p.Promedio << "\n";
        return o;
    }

    friend std::istream& operator>>(std::istream& i, constancia& p) {
        std::cout << "Ingresa el nombre de el alumno: ";
        i >> p.Alumno;
        std::cout << "Ingresa el nombre de la carrera de el alumno: ";
        i >> p.Carrera;
        std::cout << "Ingresa las materias aprobadas por el alumno: ";
        i >> p.Materias;
        std::cout << "Ingresa el promedio obtenido por el alumno: ";
        i >> p.Promedio;
        return i;
    }

    // operadores de comparacion
    bool operator==(const constancia& p) const {
        return (Alumno == p.Alumno);
    }

    bool operator!=(const constancia& p) const {
        return (Promedio != p.Promedio);
    }

    bool operator<(const constancia& p) const {
        return (Promedio < p.Promedio);
    }

    bool operator>(const constancia& p) const {
        return (Promedio > p.Promedio);
    }

    std::string getAlumno() const { return Alumno; }
    std::string getCarrera() const { return Carrera; }
    std::string getMaterias() const { return Materias; }
    float getPromedio() const { return Promedio; }
};

class Cola {
private:
    constancia* constancias;  // puntero a arreglo dinamico de constancias
    int frente;                // frente de la cola
    int fin;                   // final de la cola
    int capacidad;             // arreglo dinamico

public:
    Cola() : frente(0), fin(0), capacidad(5) {
        constancias = new constancia[capacidad];  // crear arreglo dinamico inicial con capacidad de 5
    }

    ~Cola() {
        delete[] constancias;  // liberar la memoria del arreglo dinamico
    }

    bool vacia() const {
        return frente == fin;  // si el frente es igual al final, la cola esta vacia
    }

    bool llena() const {
        return fin == capacidad;  // si el final llega a la capacidad, la cola esta llena
    }

    void encolar() {
        if (llena()) {
            // si la cola esta llena, duplicamos la capacidad del arreglo dinamico
            capacidad *= 2;
            constancia* nuevo_arreglo = new constancia[capacidad];  // creamos un nuevo arreglo mas grande

            // copiar las constancias del arreglo antiguo al nuevo arreglo
            for (int i = 0; i < fin; i++) {
                nuevo_arreglo[i] = constancias[i];
            }

            delete[] constancias;  // se libera la memoria del arreglo antiguo
            constancias = nuevo_arreglo;  // apuntamos al nuevo arreglo con mayor capacidad
        }

        constancia s;
        std::cout << "Ingresa los datos de la constancia para el alumno\n";
        std::cin >> s;

        // verificar si la constancia ya existe en la cola
        for (int i = frente; i < fin; i++) {
            if (constancias[i] == s) {
                std::cout << "La constancia de " << s.getAlumno() << " ya existe en la cola\n";
                return;
            }
        }

        constancias[fin] = s;  // agregar la nueva constancia al final de la cola
        fin++;  // incrementa el indice del final
        std::cout << "La solicitud de " << s.getAlumno() << " se capturo correctamente\n";
    }

    void desencolar() {
        if (vacia()) {
            std::cout << "No hay constancias que atender.\n";
            return;
        }

        constancia s = constancias[frente];
        frente++;  // incrementar el indice del frente

        if (frente == fin) {
            frente = fin = 0;  // se restablece el frente y el final
        }

        std::cout << "Generando constancia para el alumno.\n";
        std::cout << s;
    }

    void mostrar() {
        if (vacia()) {
            std::cout << "No se encontro ninguna constancia.\n";
        } else {
            std::cout << "Estas son las constancias disponibles:\n";
            for (int i = frente; i < fin; i++) {
                std::cout << constancias[i] << std::endl;
            }
        }
    }
};

// Menu
int main() {
    Cola MiCola;
    int opcion;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Agregar una constancia\n";
        std::cout << "2. Generar una constancia\n";
        std::cout << "3. Mostrar todas las constancias\n";
        std::cout << "4. Salir\n";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                MiCola.encolar();
                break;
            case 2:
                MiCola.desencolar();
                break;
            case 3:
                MiCola.mostrar();
                break;
            case 4:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Escribe una opción válida\n";
        }
    } while (opcion != 4);

    return 0;
}
