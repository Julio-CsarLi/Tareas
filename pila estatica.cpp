#include <iostream>

class Empleado {
private:
    int ClaveEmpleado;
    std::string Nombre;
    std::string Domicilio;
    float Sueldo;
    std::string ReportaA;

public:
    // Constructor con parametros
    Empleado() {ClaveEmpleado = 0; Nombre = " "; Domicilio = " "; Sueldo = 0; ReportaA = " ";}
    Empleado(int e, std::string nom, std::string dom = "", float sueldo = 0, std::string reporta = "")
    :ClaveEmpleado(e), Nombre(nom), Domicilio(dom), Sueldo(sueldo), ReportaA(reporta) {}

    // Capturar
    int getClaveEmpleado() const { return ClaveEmpleado; }
    std::string getNombre() const { return Nombre; }
    std::string getDomicilio() const { return Domicilio; }
    float getSueldo() const { return Sueldo; }
    std::string getReportaA() const { return ReportaA; }

    // Mostrar
    void setClaveEmpleado(int e) { ClaveEmpleado = e; }
    void setNombre(std::string nom) { Nombre = nom; }
    void setDomicilio(std::string dom) { Domicilio = dom; }
    void setSueldo(float sueldo) { Sueldo = sueldo; }
    void setReportaA(std::string reporta) { ReportaA = reporta; }

    // Detalles del empleado
    void mostrar() const {
        std::cout << "ClaveEmpleado: " << ClaveEmpleado << ", Nombre: " << Nombre
             << ", Domicilio: " << Domicilio << ", Sueldo: " << Sueldo
             << ", Reporta a: " << ReportaA << std::endl;
    }
};


class Lista{
private:
    int maxTam;//Tamano maximo de la lista
    int actTam;//Tamano actual de empleados
    Empleado* MiLista;

public:
    // Constructor
    Lista(int Tam) {
        maxTam = Tam;
        actTam = 0;
        MiLista = new Empleado[maxTam];//Reserva memoria dinamica para variables u objetos que pueden ser sobrecargados
    }

    // Agregar un empleado
    void agregar(const Empleado& empleado) {
        if (actTam < maxTam) {
            MiLista[actTam] = empleado;
            actTam++;
            std::cout << "Empleado agregado." << std::endl;
        } else {
            std::cout << "La lista se encuentra llena" << std::endl;
        }
    }

    // Buscar un empleado por su clave
    void buscar(int clave) {
        bool encuentra = false;
        for (int i = 0; i < actTam; i++) {
            if (MiLista[i].getClaveEmpleado() == clave) {
                MiLista[i].mostrar();
                encuentra = true;
                break;
            }
        }
        if (encuentra) {
            std::cout << "Empleado con clave " << clave << " no se encontro nada." << std::endl;
        }
    }

    // Eliminar un empleado por clave
    void eliminar(int clave) {
        bool encuentra = false;
        for (int i = 0; i < actTam; i++) {
            if (MiLista[i].getClaveEmpleado() == clave) {
                // Mover los elementos para llenar el hueco
                for (int dato = i; dato < actTam - 1; dato++) {
                    MiLista[dato] = MiLista[dato + 1];
                }
                actTam--;
                std::cout << "Empleado con clave " << clave << " eliminado." << std::endl;
                encuentra = true;
                break;
            }
        }
        if (encuentra) {
            std::cout << "Empleado con clave " << clave << " no se pudo encontrar." << std::endl;
        }
    }

    // Insertar un empleado en una posición específica
    void insertar(int pos, const Empleado& empleado) {
        if (pos < 0 || pos > actTam || actTam >= maxTam) {
            std::cout << "Posicion invalida o la lista se encuentra llena." << std::endl;
        } else {
            for (int i = actTam; i > pos; i--) {
                MiLista[i] = MiLista[i - 1];
            }
            MiLista[pos] = empleado;
            actTam++;
            std::cout << "Empleado insertado en la posicion " << pos << std::endl;
        }
    }

    // Mostrar todos los empleados
    void mostrar() {
        if (actTam == 0) {
            std::cout << "La lista esta vacia." << std::endl;
        } else {
            for (int i = 0; i < actTam; i++) {
                MiLista[i].mostrar();
            }
        }
    }
};

int main() {
    int Tam;
    std::cout << "Ingrese cuantos empleados se van a capturar: ";
    std::cin >> Tam;

    Lista MiLista(Tam);

    int opcion;
    int clave, pos;
    std::string nombre, domicilio, reporta;
    float sueldo;

    do {
        std::cout << "\nMenu:\n" <<std::endl;
        std::cout << "1. Agregar empleado\n"<<std::endl;
        std::cout << "2. Buscar empleado por clave\n"<<std::endl;
        std::cout << "3. Eliminar empleado por clave\n"<<std::endl;
        std::cout << "4. Insertar empleado en posición\n"<<std::endl;
        std::cout << "5. Mostrar empleados\n"<<std::endl;
        std::cout << "6. Salir\n"<<std::endl;
        std::cout << "Selecciona una opcion: "<<std::endl;
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingresa la clave del empleado: "<<std::endl;
                std::cin >> clave;
                std::cout << "Ingresa el nombre del empleado: "<<std::endl;
                getline(std::cin, nombre);
                std::cout << "Ingresa el domicilio del empleado: "<<std::endl;
                getline(std::cin, domicilio);
                std::cout << "Ingresa el sueldo del empleado: "<<std::endl;
                std::cin >> sueldo;
                std::cout << "Ingresa el jefe al que reporta: "<<std::endl;
                getline(std::cin, reporta);
                MiLista.agregar(Empleado(clave, nombre, domicilio, sueldo, reporta));
                break;

            case 2:
                std::cout << "Ingresa la clave del empleado que quieres buscar: "<<std::endl;
                std::cin >> clave;
                MiLista.buscar(clave);
                break;

            case 3:
                std::cout << "Ingresa la clave del empleado que quieres eliminar: "<<std::endl;
                std::cin >> clave;
                MiLista.eliminar(clave);
                break;

            case 4:
                std::cout << "Ingresa la posicion donde se insertaran los datos del empleado: "<<std::endl;
                std::cin >> pos;
                std::cout << "Ingresa la clave del empleado: "<<std::endl;
                std::cin >> clave;
                std::cout << "Ingresa el nombre del empleado: "<<std::endl;
                getline(std::cin, nombre);
                std::cout << "Ingresa el domicilio del empleado: "<<std::endl;
                getline(std::cin, domicilio);
                std::cout << "Ingresa el sueldo del empleado: "<<std::endl;
                std::cin >> sueldo;
                std::cout << "Ingresa el jefe al que reporta: "<<std::endl;
                getline(std::cin, reporta);
                MiLista.insertar(pos, Empleado(clave, nombre, domicilio, sueldo, reporta));
                break;

            case 5:
                std::cout<<"Estos son todos los datos:"<<std::endl;
                MiLista.mostrar();
                break;

            case 6:
                std::cout << "Cerrando el programa..." << std::endl;
                break;

        }
    } while (opcion != 6);

    return 0;
}
