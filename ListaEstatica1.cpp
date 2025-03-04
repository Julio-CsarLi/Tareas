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
    empleado() : ClaveEmpleado(0), Nombre(" "), Domicilio(" "), Sueldo(0.0), ReportaA(" ") {}
    empleado(int clave, std::string nombre, std::string domicilio, float sueldo, std::string reporta)
        : ClaveEmpleado(clave), Nombre(nombre), Domicilio(domicilio), Sueldo(sueldo), ReportaA(reporta) {}

    // mostrar la información del empleado
    friend std::ostream& operator<<(std::ostream& o, const empleado& p) {
        o << "Clave del empleado: " << p.ClaveEmpleado << "\n";
        o << "Nombre: " << p.Nombre << "\n";
        o << "Domicilio: " << p.Domicilio << "\n";
        o << "Sueldo: " << p.Sueldo << "\n";
        o << "Reporte: " << p.ReportaA << "\n";
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

    //Operador de comparación
    bool operator==(const empleado& p) const {
        return (ClaveEmpleado == p.ClaveEmpleado&& Nombre == p.Nombre&& ReportaA == p.ReportaA);
    }

     bool operator!=(const empleado& p) const {
        return (Domicilio != p.Domicilio&& Sueldo != p.Sueldo);
    }

    bool operator<(const empleado& p) const {
        return (ClaveEmpleado < p.ClaveEmpleado);
    }

    bool operator>(const empleado& p) const {
        return (ClaveEmpleado > p.ClaveEmpleado);
    }


   //Acceder a los atributos
   int getClaveEmpleado() const { return ClaveEmpleado; }
   std::string getNombre() const { return Nombre; }
   std::string getDomicilio() const { return Domicilio; }
   float getSueldo() const { return Sueldo; }
   std::string getReportaA() const { return ReportaA; }
};

class Lista {
private:
    empleado empleados[5];  // Arreglo de empleados
    int contador; // Contador de empleados actuales en la lista

public:
    // Constructor
    Lista() : contador (0){}

    // Agregar empleado
    void agregar() {
        if (contador < 5) {
            std::cout << "Escribe los datos del nuevo empleado:\n";
            std::cin >> empleados[contador];
            contador++;
        } else {
            std::cout << "La lista ya esta llena.\n";
        }
    }

    // Buscar un empleado por clave
    void buscar() {
        int clave;
        std::cout << "Escribe la clave del empleado a buscar: ";
        std::cin >> clave;
        for (int i = 0; i < contador; i++) {
            if (empleados[i].getClaveEmpleado() == clave) {
                std::cout << "El empleado con clave " <<clave<< " se encontro:\n" << empleados[i] << std::endl;
                return;
            }
        }
        std::cout << "El empleado con clave " <<clave<< " no se encontro o no existe.\n";
    }

    // Eliminar un empleado
    void eliminar() {
        int clave;
        std::string nombre, domicilio, reporta;
        float sueldo;
        std::cout << "Escribe la clave del empleado que quieres eliminar: ";
        std::cin >> clave;
        std::cout << "Escribe el nombre del empleado que quieres eliminar: ";
        std::cin >> nombre;
        std::cout << "Escribe el domicilio del empleado que quieres eliminar: ";
        std::cin >> domicilio;
        std::cout << "Escribe el sueldo del empleado que quieres eliminar: ";
        std::cin >> sueldo;
        std::cout << "Escribe el reporte del empleado que quieres eliminar: ";
        std::cin >> reporta;

        for (int i = 0; i < contador; i++) {
                empleado comparaEmp(clave, nombre, domicilio, sueldo, reporta);
            if (empleados[i] == comparaEmp) {
                for (int j = i; j < contador - 1; j++) {
                    empleados[j] = empleados[j + 1]; // Desplazamos los empleados hacia la izquierda
                }
                contador--;
                std::cout << "El empleado con la clave: "<< clave << " y nombre: "<< nombre <<" se elimino correctamente";
                return;
            }
        }
        std::cout << "El empleado  con la clave " <<clave<< " y nombre " <<nombre<< " no se elimino o no existe";
    }

    // Insertar un empleado
    void insertar() {
        if (contador < 5) {
            empleado nuevoEmp;
            std::cout << "Escribe los datos del nuevo empleado:\n";
            std::cin >> nuevoEmp;

            int posicion;
            std::cout << "Escribe la posicion donde deseas insertar los datos del nuevo empleado ( 0 a " << contador << "): ";
            std::cin >> posicion;

            if (posicion < 0 || posicion > contador) {
                std::cout << "Escribe una posicion valida.\n";
                return;
            }

            for (int i = contador; i > posicion; i--) {
                empleados[i] = empleados[i - 1]; // Desplazamos los empleados hacia la derecha
            }

            empleados[posicion] = nuevoEmp;
            contador++;
            std::cout << "El empleado se inserto en la posicion " << posicion << ".\n";
        } else {
            std::cout << "La lista ya esta llena.\n";
        }
    }

    // Mostrar todos los empleados
    void mostrar() const {
        if (contador == 0) {
            std::cout << "No se encontraron datos.\n";
        } else {
            std::cout << "Estos son los empleados que se encontraron:\n";
            for (int i = 0; i < contador; i++) {
                std::cout << empleados[i] << std::endl;
            }
        }
    }
};

// Menu
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
