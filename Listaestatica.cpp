#include <iostream>

class Empleado {
private:
    int ClaveEmpleado;
    std::string Nombre;
    std::string Domicilio;
    float Sueldo;
    std::string ReportaA;

public:
    // Constructor
    Empleado() {
    ClaveEmpleado = 0; Nombre = " "; Domicilio = " "; Sueldo = 0.0; ReportaA = " ";}
    Empleado(int e, std::string nom, std::string dom = "", float sueldo = 0.0, std::string reporta = "")
    : ClaveEmpleado(e), Nombre(nom), Domicilio(dom), Sueldo(sueldo), ReportaA(reporta) {}

    //capturar datos
    int getClaveEmpleado() const { return ClaveEmpleado; }
    std::string getNombre() const { return Nombre; }
    std::string getDomicilio() const { return Domicilio; }
    float getSueldo() const { return Sueldo; }
    std::string getReportaA() const { return ReportaA; }

    // Imprimir detalles del empleado
    void imprimir() const {
        std::cout << " Mi clave es: " << ClaveEmpleado << std::endl;
        std::cout << " Mi nombre: " << Nombre << std::endl;
        std::cout << " Y yo vivo en: " << Domicilio << std::endl;
        std::cout << " Mi sueldo es de: " << Sueldo << std::endl;
        std::cout << " Mi reporte es: " << ReportaA << std::endl;
    }
};

class Lista {
private:
    Empleado Milista[3];
    int Tam;
    int ult;

public:
    Lista() {
    Tam= 0;  // comienza la lista
    }
    bool vacia() const {
        return ult == -1;
    }

    bool llena() const {
        return ult == Tam - 1;
    }

    void agregar(Empleado empleado) {
        if (Tam < 3) {
            Milista[Tam] = empleado;
            Tam++;
            std::cout << "Empleado \"" << empleado.getNombre() << "\" agregado." << std::endl;
        } else {
            std::cout << "No se puede agregar más." << std::endl;
        }
    }

    void buscar(int clave) {
        int i = 0;
        while (i < Tam && Milista[i].getClaveEmpleado() != clave) {
            i++;
        }
        if (i < Tam) {
            std::cout << "El empleado con la clave " << clave << " ha sido encontrado: " << std::endl;
            Milista[i].imprimir();
        } else {
            std::cout << "El mpleado con la clave " << clave << " no ha sido encontrado en la lista." << std::endl;
        }
    }

    void eliminar(int clave) {
        int i = 0;
        while (i < Tam && Milista[i].getClaveEmpleado() != clave) {
            i++;
        }
        if (i < Tam) {
            for (int j = i; j < Tam - 1; j++) {
                Milista[j] = Milista[j + 1];
            }
            Tam--;
            std::cout << "El empleado con la clave " << clave << " fue eliminado." << std::endl;
        } else {
            std::cout << "El empleado con la clave " << clave << " no ha sido encontrado para eliminar." << std::endl;
        }
    }

    void insertar(int pos, const Empleado&empleado) {
        if (pos >= 0 && pos <= Tam && Tam < 3) {
            for (int i = Tam; i > pos; i--) {
            Milista[i] = Milista[i - 1];
            }
            Milista[pos] = empleado;
            Tam++;
            std::cout << "El empleado \"" << empleado.getNombre() << "  se inserto en la posición " << pos << "." << std::endl;
        } else {
            std::cout << "No se pudo insertar." << std::endl;
        }
    }

    void imprimir() {
        if (Tam == 0) {
            std::cout << "No hay ningun empleado en la lista." << std::endl;
        } else {
            std::cout << "Los empleados que hay en la lista son: " << std::endl;
            for (int i = 0; i < Tam; i++) {
                Milista[i].imprimir();
            }
        }
    }
};

int main() {
    Lista Milista;
    int opcion;
    int pos;
    int clave;
    std::string nombre;
    std::string domicilio;
    std::string reporta;
    float sueldo;

    do {
        std::cout << "Menu: " << std::endl;
        std::cout << "1. Agregar empleado" << std::endl;
        std::cout << "2. Buscar empleado" << std::endl;
        std::cout << "3. Eliminar empleado" << std::endl;
        std::cout << "4. Insertar empleado" << std::endl;
        std::cout << "5. Mostrar empleado" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Selecciona una opcion: ";
        std::cin >> opcion;

        switch (opcion){
        case 1:
            std::cout << "Ingresa la clave del empleado: ";
            std::cin >> clave;
            std::cin.ignore();
            std::cout << "Ingresa el nombre del empleado: ";
            getline(std::cin, nombre);
            std::cout << "Ingresa el domicilio del empleado: ";
            getline(std::cin, domicilio);
            std::cout << "Ingresa el sueldo del empleado: ";
            std::cin >> sueldo;
            std::cin.ignore();
            std::cout << "Ingresa el reporte: ";
            getline(std::cin, reporta);
            Milista.agregar(Empleado(clave, nombre, domicilio, sueldo, reporta));
            break;

        case 2:
            std::cout << "Ingresa la clave del empleado que quieres buscar: ";
            std::cin >> clave;
            Milista.buscar(clave);
            break;

        case 3:
            std::cout << "Ingresa la clave del empleado que quieres eliminar: ";
            std::cin >> clave;
            Milista.eliminar(clave);
            break;

        case 4:
            std::cout << "Ingresa la posicion donde se insertara el empleado: "<<std::endl;
                std::cin >> pos;
                std::cout << "Ingresa la clave del empleado: "<<std::endl;
                std::cin >> clave;
                std::cout << "Ingresa el nombre del empleado: "<<std::endl;
                getline(std::cin, nombre);
                std::cout << "Ingresa el domicilio del empleado: "<<std::endl;
                getline(std::cin, domicilio);
                std::cout << "Ingresa el sueldo del empleado: "<<std::endl;
                std::cin >> sueldo;
                std::cout << "Ingresa el reporte: "<<std::endl;
                getline(std::cin, reporta);
                Milista.insertar(pos, Empleado(clave, nombre, domicilio, sueldo, reporta));
                break;

        case 5:
            Milista.imprimir();
            break;

        case 6:
            std::cout << "Saliendo..." << std::endl;
            break;
}

    }while (opcion!=6);
    return 0;
}
