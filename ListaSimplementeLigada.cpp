#include <iostream>

class SocioClub {
private:
    int NumeroSocio;
    std::string NombreSocio;
    std::string Domicilio;
    int AnoIngreso;

public:
    // Constructor
    SocioClub(int numerosocio = 0, std::string nombresocio = " ", std::string domicilio = " ", int anoingreso = 0)
    : NumeroSocio(numerosocio), NombreSocio(nombresocio), Domicilio(domicilio), AnoIngreso(anoingreso) {}

    // Mostrar la información del socio
    friend std::ostream& operator<<(std::ostream& o, const SocioClub& p) {
        o << "El numero de socio es: " << p.NumeroSocio << "\n";
        o << "Su nombre de socio es: " << p.NombreSocio << "\n";
        o << "Y este es su domicilio: " << p.Domicilio << "\n";
        o << "Su ano de ingreso es: " << p.AnoIngreso << "\n";
        return o;
    }

    // Capturar los datos del socio
    friend std::istream& operator>>(std::istream& i, SocioClub& p) {
        std::cout << "Ingresa el numero de socio: ";
        i >> p.NumeroSocio;
        std::cout << "Ingresa el nombre: ";
        i >> p.NombreSocio;
        std::cout << "Ingresa el domicilio: ";
        i >> p.Domicilio;
        std::cout << "Ingresa el ano de ingreso del socio: ";
        i >> p.AnoIngreso;
        return i;
    }

    // Operadores de comparación
    bool operator==(const SocioClub& p) const {
        return NumeroSocio == p.NumeroSocio;
    }

    bool operator<(const SocioClub& p) const {
        return NumeroSocio < p.NumeroSocio;
    }

    bool operator!=(const SocioClub& p) const {
        return NumeroSocio != p.NumeroSocio;
    }

    bool operator>(const SocioClub& p) const {
        return NumeroSocio > p.NumeroSocio;
    }

    int getNumeroSocio() const { return NumeroSocio; }
    std::string getNombreSocio() const { return NombreSocio; }
    std::string getDomicilio() const { return Domicilio; }
    int getAnoIngreso() const { return AnoIngreso; }
};

struct Nodo {
    SocioClub socio;
    Nodo* siguiente;
    Nodo(const SocioClub& s) : socio(s), siguiente(nullptr) {}
};

class Lista {
private:
    Nodo* inicio; // Apuntador al primer nodo de la lista
    int Tam; // Número de socios actuales en la lista

public:
    // Constructor
    Lista() : inicio(nullptr), Tam(0) {}

    // Verificar si la lista esta vacia
    bool vacia() const {
        return Tam == 0;
    }

    // Agregar socio con ordenacion y verificacion de duplicados
    void agregar() {
        SocioClub nuevo;
        std::cout << "Escribe los datos del nuevo socio:\n";
        std::cin >> nuevo;

        Nodo* nuevoNodo = new Nodo(nuevo);

        // Si la lista está vacia o el nuevo socio debe ir al inicio
        if (!inicio || inicio->socio > nuevo) {
            nuevoNodo->siguiente = inicio;
            inicio = nuevoNodo;
        } else {
            Nodo* actual = inicio;
            while (actual->siguiente && actual->siguiente->socio < nuevo) {
                actual = actual->siguiente;
            }
            nuevoNodo->siguiente = actual->siguiente;
            actual->siguiente = nuevoNodo;
        }

        Tam++;
        std::cout << "Socio registrado exitosamente.\n";
    }

    // Eliminar un socio de la lista
    void eliminar() {
        int numero;
        if (vacia()) {
            std::cout << "La lista esta vacia.\n";
            return;
        }
        std::cout << "Ingrese el numero de socio a eliminar: ";
        std::cin >> numero;

        Nodo* actual = inicio;
        Nodo* anterior = nullptr;

        // Buscar el socio por numero
        while (actual && actual->socio.getNumeroSocio() != numero) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (!actual) {
            std::cout << "El socio no existe.\n";
            return;
        }

        // Si es el primer socio
        if (!anterior) {
            inicio = actual->siguiente;
        } else {
            anterior->siguiente = actual->siguiente;
        }

        delete actual;
        Tam--;
        std::cout << "El socio ha sido eliminado.\n";
    }

    // Buscar un socio
    void buscar() {
        if (vacia()) {
            std::cout << "La lista esta vacia.\n";
            return;
        }
        std::string nombre, domicilio;
        std::cout << "Ingrese el nombre del socio: ";
        std::cin >> nombre;
        std::cout << "Ingrese el domicilio del socio: ";
        std::cin >> domicilio;

        Nodo* actual = inicio;
        while (actual) {
            if (actual->socio.getNombreSocio() == nombre && actual->socio.getDomicilio() == domicilio) {
                std::cout << "Socio encontrado:\n" << actual->socio << std::endl;
                return;
            }
            actual = actual->siguiente;
        }

        std::cout << "No se encontro al socio.\n";
    }

    // Mostrar todos los socios de la lista
    void mostrar() const {
        if (vacia()) {
            std::cout << "La lista esta vacia.\n";
            return;
        }
        Nodo* actual = inicio;
        std::cout << "Estos son los socios registrados:\n";
        while (actual) {
            std::cout << actual->socio << std::endl;
            actual = actual->siguiente;
        }
    }

    // Mostrar el total de socios
    void total() const {
        if (vacia()) {
            std::cout << "La lista esta vacia.\n";
            return;
        }
        std::cout << "Total de socios registrados: " << Tam << "\n";
    }
};

// Menu
int main() {
    Lista MiLista;
    int opcion;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Registrar nuevo socio\n";
        std::cout << "2. Mostrar todos los socios\n";
        std::cout << "3. Eliminar un socio\n";
        std::cout << "4. Buscar un socio por nombre y domicilio\n";
        std::cout << "5. Mostrar total de socios registrados\n";
        std::cout << "6. Salir\n";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                MiLista.agregar();
                break;
            case 2:
                MiLista.mostrar();
                break;
            case 3:
                MiLista.eliminar();
                break;
            case 4:
                MiLista.buscar();
                break;
            case 5:
                MiLista.total();
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
