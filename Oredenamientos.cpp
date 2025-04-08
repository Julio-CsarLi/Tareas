#include <iostream>

class Solicitud {
private:
    std::string Nombre;
    std::string Carrera;
    std::string Prepa;
    float Promedio;

public:
    //Constructor
    Solicitud(std::string nombre = " ", std::string carrera = " ", std::string prepa = " ", float promedio = 0)
    : Nombre(nombre), Carrera(carrera), Prepa(prepa), Promedio(promedio) {}

    //Mostrar la informacion de la solicitud
    friend std::ostream& operator<<(std::ostream& o, const Solicitud& p) {
        o << "El nombre del alumno es: " << p.Nombre << "\n";
        o << "Su carrera es: " << p.Carrera << "\n";
        o << "Y la preparatoria de la que proviene es: " << p.Prepa << "\n";
        o << "Su promedio fue de: " << p.Promedio << "\n";
        return o;
    }

    //Capturar los datos de la solicitud
    friend std::istream& operator>>(std::istream& i, Solicitud& p) {
        std::cout << "Ingresa el nombre del alumno: ";
        i >> p.Nombre;
        std::cout << "Ingresa la carrera del alumno: ";
        i >> p.Carrera;
        std::cout << "Ingresa el nombre de la preparatoria de la que proviene: ";
        i >> p.Prepa;
        std::cout << "Ingresa el promedio del alumno: ";
        i >> p.Promedio;
        return i;
    }

    //Operadores de comparacion
    bool operator==(const Solicitud& p) const {
        return Nombre == p.Nombre;
    }

    bool operator!=(const Solicitud& p) const {
        return Nombre != p.Nombre;
    }

    bool operator<(const Solicitud& p) const {
        return Nombre < p.Nombre;
    }

    bool operator>(const Solicitud& p) const {
        return Nombre > p.Nombre;
    }

    std::string getNombre() const { return Nombre; }
    std::string getCarrera() const { return Carrera; }
    std::string getPrepa() const { return Prepa; }
    float getPromedio() const { return Promedio; }

};

class ListaSolicitudes {
private:
    Solicitud* solicitudes; //Arreglo dinamico de solicitudes
    int tam; //Solicitudes que hay
    int capacidad; //Capacidad maxima

    // Ordenamiento por promedio (de mayor a menor)
    void ordenarPorPromedio() {
        for (int i = 1; i < tam; i++) {
            Solicitud key = solicitudes[i];
            int j = i - 1;
            while (j >= 0 && solicitudes[j].getPromedio() < key.getPromedio()) {
                solicitudes[j + 1] = solicitudes[j];
                j--;
            }
            solicitudes[j + 1] = key;
        }
    }

    // Ordenamiento por nombre (de a a z)
    void ordenarPorNombre() {
        for (int i = 1; i < tam; i++) {
            Solicitud key = solicitudes[i];
            int j = i - 1;
            while (j >= 0 && solicitudes[j].getNombre() > key.getNombre()) {
                solicitudes[j + 1] = solicitudes[j];
                j--;
            }
            solicitudes[j + 1] = key;
        }
    }

    // Búsqueda binaria por nombre
    int busquedaBinaria(const std::string& nombre) {
        int low = 0;
        int high = tam - 1;
        while (low <= high) {
            int mid = (low + high) / 2; //Compara el nombre en medio con el buscado. Si no es, ajusta los límites hasta encontrarlo
            if (solicitudes[mid].getNombre() == nombre)
                return mid;
            else if (solicitudes[mid].getNombre() < nombre)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

public:
    ListaSolicitudes(int capacidadMax = 100) { //Arreglo dinamico
        capacidad = capacidadMax;
        solicitudes = new Solicitud[capacidad];
        tam = 0;
    }

    ~ListaSolicitudes() { //Libera la memoria
        delete[] solicitudes;
    }

    void agregar() {
        if (tam >= capacidad) {
            std::cout << "No se pueden agregar más solicitudes. Capacidad llena.\n";
            return;
        }

        Solicitud nueva;
        std::cin >> nueva;
        solicitudes[tam++] = nueva;
        std::cout << "Solicitud agregada exitosamente al final de la lista.\n";
    }

    void buscar() {
        if (tam == 0) {
            std::cout << "No hay solicitudes registradas.\n";
            return;
        }

        std::string nombre;
        std::cout << "Ingresa el nombre a buscar: ";
        std::cin >> nombre;

        ordenarPorNombre();  // Necesario para que funcione búsqueda binaria
        int index = busquedaBinaria(nombre);

        if (index != -1) {
            // Mostrar datos
            std::cout << "\nSolicitud encontrada:\n";
            std::cout << solicitudes[index];

            // Calcular lugar por promedio
            ordenarPorPromedio();
            for (int i = 0; i < tam; ++i) {
                if (solicitudes[i].getNombre() == nombre) {
                    std::cout << "Lugar en la lista por promedio: " << i + 1 << "\n";
                    break;
                }
            }
        } else {
            std::cout << "Solicitud no encontrada. Debe darla de alta.\n";
        }
    }
};

int main() {
    ListaSolicitudes lista;
    int opcion;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Dar de alta solicitud\n";
        std::cout << "2. Buscar solicitud por nombre\n";
        std::cout << "3. Salir\n";
        std::cout << "Selecciona una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                lista.agregar();
                break;
            case 2:
                lista.buscar();
                break;
            case 3:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opcion no valida. Intenta de nuevo.\n";
        }
    } while (opcion != 3);

    return 0;
}
