#include <iostream>

class empleado{
private: //Atributos deben de ir aqui
    //std::string Puesto;
    int ClaveEmpleado;
    std::string Nombre;
    std::string Domicilio;
    float Sueldo;
    std::string ReportaA;
public:
    empleado(){ClaveEmpleado=0; /*Puesto=" "*/; Nombre=" "; Domicilio=" "; Sueldo=0; ReportaA=" ";} //constructor
    empleado(int e, float s, std::string nom){       //constructor con parametros
        ClaveEmpleado=e;
        Nombre=nom;
    }
    //mostrar informacion
    friend std::ostream & operator<<(std::ostream & o, empleado &p){
        //o<<"Mi puesto es: "<<p.Puesto<<std::endl;
        o<<"mi clave es: "<<p.ClaveEmpleado<<std::endl;
        o<<"me llamo: "<<p.Nombre<<std::endl;
        o<<"y yo vivo en: "<<p.Domicilio<<std::endl;
        o<<"mi sueldo es de: "<<p.Sueldo<<std::endl;
        o<<"el reporte es para: "<<p.ReportaA<<std::endl;
        return o;
    }

    //capturar informacion
    friend std::istream & operator>>(std::istream & i, empleado &p){
        //std::cout<<"Nota:\n";
        //std::cout<<"\n Cual es tu puesto?\n";
        //i>>p.Puesto;
        std::cout<<"\cual es tu clave?\n ";
        i>>p.ClaveEmpleado;
        std::cout<<"cual es tu nombre?\n ";
        i>>p.Nombre;
        std::cout<<"donde vives?\n ";
        i>>p.Domicilio;
        std::cout<<"cual es tu sueldo?\n ";
        i>>p.Sueldo;
        std::cout<<"Hacia quien es tu reporte?\n ";
        i>>p.ReportaA;
        return i;
    }

    bool operator == (empleado &p) {
        return (p.ClaveEmpleado==ClaveEmpleado);
        }
    bool operator != (empleado &p) {
        return (p.ClaveEmpleado!=ClaveEmpleado);
        }
    bool operator > (empleado &p) {
        return (p.ClaveEmpleado<ClaveEmpleado);
        }
    bool operator < (empleado &p) {
        return (p.ClaveEmpleado>ClaveEmpleado);
        }
    bool operator + (empleado &p) {
        return (p.ClaveEmpleado)+(ClaveEmpleado);
        }

};

int main()
{
    std::string p;
    int e,opc;
    float s;
    empleado jefepersonal,jefeplanta;
    std::cin>>jefepersonal;
    std::cout<<jefepersonal;
    std::cin>>jefeplanta;
    std::cout<<jefeplanta;

    do{
        std::cout<<"menu principal "<<std::endl;
        std::cout<<"1. capturar/modificar informacion jefe de personal"<<std::endl;
        std::cout<<"2. mostrar informacion jefe de personal"<<std::endl;
        std::cout<<"3. capturar/modificar informacion jefe de planta"<<std::endl;
        std::cout<<"4. mostrar informacion jefe de planta"<<std::endl;
        std::cout<<"5. salir "<<std::endl;
        std::cout<<"Seleccione una opcion: "<<std::endl;
        std::cin>>opc;

        if (opc == 1){
            system("cls");
            std::cout<<"Ingresa la informacion de jefe de personal"<<std::endl;
            std::cin>>jefepersonal;
        }
        if (opc == 2){
            system("cls");
            std::cout<<"Estos son los datos disponibles de jefe de personal"<<std::endl;
            std::cout<<jefepersonal;
        }
        if (opc == 3){
            system ("cls");
            std::cout<<"Ingresa la informacion de jefe de planta"<<std::endl;
            std::cin>>jefeplanta;
        }
        if (opc == 4){
            system("cls");
            std::cout<<"Estos son los datos disponibles de jefe de planta"<<std::endl;
            std::cout<<jefeplanta;
        }

        if (jefepersonal == jefeplanta){
        std::cout<<"Las claves son iguales"<<std::endl;
        }
        if (jefepersonal != jefeplanta){
        std::cout<<"Las claves son distintas"<<std::endl;
        }
        if (jefepersonal > jefeplanta){
        std::cout<<"la clave de jefepersonal es mayor a la clave de jefe planta"<<std::endl;
        }
        if(jefepersonal < jefeplanta){
        std::cout<<"la clave de jefe personal es menor a la clave de jefe planta"<<std::endl;
        }

      }
        while (opc!=5);
        std::cout<<"Saliendo...";


    return 0;

}
