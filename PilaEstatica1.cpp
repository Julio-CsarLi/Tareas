#include <iostream>

class empleado {
private:
    int ClaveEmpleado;
    std::string Nombre;
    std::string Domicilio;
    float Sueldo;
    std::string ReportaA;

public:
    // Constructor
    empleado(int clave = 0, std::string nombre = " ", std::string domicilio = " ", float sueldo = 0.0, std::string reporta = " ")
    : ClaveEmpleado(clave), Nombre(nombre), Domicilio(domicilio), Sueldo(sueldo), ReportaA(reporta) {}

    // Mostrar la informacion del empleado
    friend std::ostream& operator<<(std::ostream& o, const empleado& p) {
        o << "La clave del empleado es: " << p.ClaveEmpleado << "\n";
        o << "Su nombre es: " << p.Nombre << "\n";
        o << "y su domicilio es: " << p.Domicilio << "\n";
        o << "Su actual sueldo es de: " << p.Sueldo << "\n";
        o << "Por ultimo este es su reporte: " << p.ReportaA << "\n";
        return o;
    }

    // Capturar los datos del empleado
    friend std::istream& operator>>(std::istream& i, empleado& p) {
        std::cout << "Clave del empleado: ";
        i >> p.ClaveEmpleado;
        std::cout << "Nombre: ";
        i >> p.Nombre;
        std::cout << "Domicilio: ";
        i >> p.Domicilio;
        std::cout << "Sueldo: ";
        i >> p.Sueldo;
        std::cout << "Reporte: ";
        i >> p.ReportaA;
        return i;
    }

    // Acceder a los atributos
    int getClaveEmpleado() const { return ClaveEmpleado; }
    std::string getNombre() const { return Nombre; }
    std::string getDomicilio() const { return Domicilio; }
    float getSueldo() const { return Sueldo; }
    std::string getReportaA() const { return ReportaA; }
};

class Pila {
private:
    empleado empleados[6];  // Arreglo de tamaño
    int ult;               // tope o limite / Indica el ultimo lugar ocupado de la pila

public:
    // Constructor
    Pila() : ult(0) {}

    // ver si la pila esta llena
    bool llena() const {
        return ult == 5;
    }

    // ver si la pila esta vacia
    bool vacia() const {
        return ult == 0;
    }

    // push / Agregar
    void push() {
        if (llena()) {
            std::cout << "La pila se encuentra llena.\n";
        } else {
            ult++;
            std::cout << "Escribe los datos del nuevo empleado:\n";
            std::cin >> empleados[ult];
            std::cout << "El empleado se agrego correctamente.\n";
        }
    }

    // pop / Eliminar el ultimo
    void pop() {
        if (vacia()) {
            std::cout << "La pila se encuentra vacia.\n";
        } else {
            std::cout << "El ultimo empleado se elimino correctamente: \n" << empleados[ult] << std::endl;
            ult--;
        }
    }

    // top / mostrar el ultimo
    void top() {
        if (vacia()) {
            std::cout << "La pila se encuentra vacia.\n";
        } else {
            std::cout << "El ultimo empleado que se agrego es: \n" << empleados[ult] << std::endl;
        }
    }

    // Mostrar todos
    void mostrar() {
        if (vacia()) {
            std::cout << "La pila se encuentra vacia.\n";
        } else {
            std::cout << "Estos son los empleados en la pila:\n";
            for (int i = ult; i >= 1; --i) {
                std::cout << empleados[i] << std::endl;
            }
        }
    }
};

// Menu
int main() {
    Pila miPila;
    int opcion;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Push / Agregar un empleado\n";
        std::cout << "2. Pop / Eliminar el ultimo empleado\n";
        std::cout << "3. Top / Mostrar el ultimo empleado\n";
        std::cout << "4. Mostrar todos los empleados\n";
        std::cout << "5. Salir\n";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                miPila.push();
                break;
            case 2:
                miPila.pop();
                break;
            case 3:
                miPila.top();
                break;
            case 4:
                miPila.mostrar();
                break;
            case 5:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Digita una opcion valida.\n";
        }
    } while (opcion != 5);

    return 0;
}
