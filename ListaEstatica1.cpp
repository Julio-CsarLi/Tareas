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

    // mostrar la informacion del empleado
    friend std::ostream& operator<<(std::ostream& o, const empleado& p) {
        o << "La clave del empleado es: " << p.ClaveEmpleado << "\n";
        o << "Su nombre es: " << p.Nombre << "\n";
        o << "Y este es su domicilio: " << p.Domicilio << "\n";
        o << "Su actual sueldo es de: " << p.Sueldo << "\n";
        o << "Este es el reporte del empleado: " << p.ReportaA << "\n";
        return o;
    }

    // capturar los datos del empleado
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

    //Operador de comparacion
    bool operator==(const empleado& p) const {
        return (ClaveEmpleado == p.ClaveEmpleado && Nombre == p.Nombre && ReportaA == p.ReportaA);
    }

    bool operator!=(const empleado& p) const {
        return (Domicilio != p.Domicilio && Sueldo != p.Sueldo);
    }

    bool operator<(const empleado& p) const {
        return (ClaveEmpleado < p.ClaveEmpleado);
    }

    bool operator>(const empleado& p) const {
        return (ClaveEmpleado > p.ClaveEmpleado);
    }

   //controlar los atributos
   int getClaveEmpleado() const { return ClaveEmpleado; }
   std::string getNombre() const { return Nombre; }
   std::string getDomicilio() const { return Domicilio; }
   float getSueldo() const { return Sueldo; }
   std::string getReportaA() const { return ReportaA; }
};

class Lista {
private:
    empleado empleados[5];  // Arreglo de empleados
    int Tam; // empleados actuales en la lista

public:
    // Constructor
    Lista() : Tam(0) {}

    // ver si la lista esta vacia
    bool vacia() const {
        return Tam == 0;
    }

    // ver si la lista esta llena
    bool llena() const {
        return Tam == 5;
    }

    // Agregar empleado
    void agregar() {
        if (llena()) {
            std::cout << "La lista esta llena.\n";
        } else {
            std::cout << "Escribe los datos del nuevo empleado:\n";
            std::cin >> empleados[Tam];
            Tam++;
        }
    }

    // Buscar un empleado
    void buscar() {
        int clave;
        std::cout << "Escribe la clave del empleado que quieres buscar: ";
        std::cin >> clave;
        for (int i = 0; i < Tam; i++) {
            if (empleados[i].getClaveEmpleado() == clave) {
                std::cout << "El empleado con clave " << clave << " se ha encontrado:\n" << empleados[i] << std::endl;
                return;
            }
        }
        std::cout << "El empleado con clave " << clave << " no existe.\n";
    }

    // Eliminar un empleado
    void eliminar() {
        empleado eliminaEmp;
        std::cout << "Escribe los datos del empleado que quieres eliminar \n";
        std::cin >> eliminaEmp;
        for (int i = 0; i < Tam; i++) {
            if (empleados[i] == eliminaEmp) {
                for (int j = i; j < Tam - 1; j++) {
                    empleados[j] = empleados[j + 1]; // recorre los empleados hacia la izquierda
                }
                Tam--;
                std::cout << "El empleado se elimino correctamente\n";
                return;
            }
        }
        std::cout << "El empleado no existe\n";
    }

    // Insertar un empleado por posicion
    void insertar() {
        if (llena()) {
            std::cout << "La lista se encuentra llena.\n";
        } else {
            empleado nuevoEmp;
            std::cout << "Escribe los datos del nuevo empleado:\n";
            std::cin >> nuevoEmp;

            int posicion;
            std::cout << "Escribe la posicion donde deseas insertar el nuevo empleado (0 a " << Tam << "): ";
            std::cin >> posicion;

            if (posicion < 0 || posicion > Tam) {
                std::cout << "Escribe una posicion valida.\n";
                return;
            }

            for (int i = Tam; i > posicion; i--) {
                empleados[i] = empleados[i - 1]; // recorre los empleados hacia la derecha
            }

            empleados[posicion] = nuevoEmp;
            Tam++;
            std::cout << "El empleado se inserto en la posicion " << posicion << ".\n";
        }
    }

    // Mostrar todos los empleados
    void mostrar() const {
        if (vacia()) {
            std::cout << "No se encontraron datos.\n";
        } else {
            std::cout << "Estos son los empleados que se encontraron:\n";
            for (int i = 0; i < Tam; i++) {
                std::cout << empleados[i] << std::endl;
            }
        }
    }
};

// Menú
int main() {
    Lista MiLista;
    int opcion;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Agregar un empleado\n";
        std::cout << "2. Buscar un empleado\n";
        std::cout << "3. Eliminar un empleado\n";
        std::cout << "4. Insertar un empleado\n";
        std::cout << "5. Mostrar todos los empleados\n";
        std::cout << "6. Salir\n";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                MiLista.agregar();
                break;
            case 2:
                MiLista.buscar();
                break;
            case 3:
                MiLista.eliminar();
                break;
            case 4:
                MiLista.insertar();
                break;
            case 5:
                MiLista.mostrar();
                break;
            case 6:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Escribe una opcion valida\n";
        }
    } while (opcion != 6);

    return 0;
}
