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

     //Operador de comparacion
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
    constancia constancias[5]; //  5 elementos
    int frente;                 // frente de la cola
    int fin;                    // final de la cola

public:
    Cola() : frente(0), fin(0) {}

    bool vacia() const {
        return frente == fin;  // comprueba si la cola esta vacia
    }

    bool llena() const {
        return fin == 5;  // comprueba si la cola esta llena
    }

    void agregar() {
        if (llena()) {
            std::cout << "La cola esta llena. No se puede agregar mas constancias.\n";
            return;
        }

        constancia s;
        std::cout << "Ingresa los datos de la constancia para el alumno\n";
        std::cin >> s;

        for(int i = frente; i < fin; i++){//Operador de igualdad
            if(constancias[i] == s){
                std::cout << "La constancia de " << s.getAlumno() << " ya existe en la cola\n";
                return;
            }
        }

        constancias[fin] = s;  // Agregar al final de la cola
        fin++;  // Incrementar
        std::cout << "La solicitud de " << s.getAlumno() << " se capturo correctamente\n";
    }

    void generar() {
        if (vacia()) {
            std::cout << "No hay constancias que atender.\n";
            return;
        }

        constancia s = constancias[frente];  // Tomar la constancia del frente de la cola
        frente++;  // Incrementar el indice o frente
        std::cout << "Generando constancia para el alumno.\n";
        std::cout << s;
    }

    void mostrar() {
        if (vacia()) {
            std::cout << "No se encontro ninguna constancia.\n";
        } else {
            std::cout << "Estas son las constancias disponibles:\n";
            for (int i = frente; i < fin; i++) { //Revisa todo lo que hay en la cola
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
                MiCola.agregar();
                break;
            case 2:
                MiCola.generar();
                break;
            case 3:
                MiCola.mostrar();
                break;
            case 4:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Escribe una opcion valida\n";
        }
    } while (opcion != 4);

    return 0;
}
