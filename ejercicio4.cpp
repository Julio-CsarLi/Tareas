#include <iostream>

class materia{
private: //Atributos deben de ir aqui
    //std::string Puesto;
    int Clave;
    std::string Nombre;
    std::string Profesortit;
    std::string Librotexto;
public:
    empleado(){Clave=0; Nombre=" "; Profesortit=" "; Librotexto=" ";} //constructor
    empleado(int e, std::string nom){       //constructor con parametros
        Clave=e;
        Nombre=nom;
    }
    //mostrar informacion
    friend std::ostream & operator<<(std::ostream & o, materia &p){
        //o<<"Mi puesto es: "<<p.Puesto<<std::endl;
        o<<"mi clave es: "<<p.Clave<<std::endl;
        o<<"me llamo: "<<p.Nombre<<std::endl;
        o<<"el nombre del profesor es: "<<p.Profesortit<<std::endl;
        o<<"el libro es: "<<p.Librotexto<<std::endl;
        return o;
    }

    //capturar informacion
    friend std::istream & operator>>(std::istream & i, materia &p){
        std::cout<<"\cual es tu clave?\n ";
        i>>p.Clave;
        std::cout<<"cual es tu nombre?\n ";
        i>>p.Nombre;
        std::cout<<"como se llama el profesor?\n ";
        i>>p.Profesortit;
        std::cout<<"cual es el nombre del libro?\n ";
        i>>p.Librotexto;
        return i;
    }

    bool operator == (materia &p) {
        return (p.Clave==Clave);
        }
    bool operator != (materia &p) {
        return (p.Clave!=Clave);
        }
    bool operator > (materia &p) {
        return (p.Clave<Clave);
        }
    bool operator < (materia &p) {
        return (p.Clave>Clave);
        }
    bool operator + (materia &p) {
        return (p.Clave)+(Clave);
        }

};

int main()
{
    std::string p;
    int e,opc;
    float s;
    materia programacion,basesdatos;
    std::cin>>programacion;
    std::cout<<programacion;
    std::cin>>basesdatos;
    std::cout<<basesdatos;

    do{
        std::cout<<"menu principal "<<std::endl;
        std::cout<<"1. capturar/modificar informacion de la materia programacion"<<std::endl;
        std::cout<<"2. mostrar informacion de la materia programacion"<<std::endl;
        std::cout<<"3. capturar/modificar informacion de la materia basesdatos"<<std::endl;
        std::cout<<"4. mostrar informacion de la materia basesdatos"<<std::endl;
        std::cout<<"5. salir "<<std::endl;
        std::cout<<"Seleccione una opcion: "<<std::endl;
        std::cin>>opc;

        if (opc == 1){
            system("cls");
            std::cout<<"Ingresa la informacion de la materia de programacion"<<std::endl;
            std::cin>>programacion;
        }
        if (opc == 2){
            system("cls");
            std::cout<<"Estos son los datos disponibles de la materia programacion"<<std::endl;
            std::cout<<programacion;
        }
        if (opc == 3){
            system ("cls");
            std::cout<<"Ingresa la informacion de la materia bases de datos"<<std::endl;
            std::cin>>basesdatos;
        }
        if (opc == 4){
            system("cls");
            std::cout<<"Estos son los datos disponibles de la materia bases de datos"<<std::endl;
            std::cout<<basesdatos;
        }

        if (programacion == basesdatos){
        std::cout<<"Las claves son iguales"<<std::endl;
        }
        if (programacion != basesdatos){
        std::cout<<"Las claves son distintas"<<std::endl;
        }
        if (programacion > basesdatos){
        std::cout<<"la clave de la materia programacion es mayor a la clave de la materia bases de datos"<<std::endl;
        }
        if(programacion < basesdatos){
        std::cout<<"la clave de la materia programacion es menor a la clave de la materia bases de datos"<<std::endl;
        }

      }
        while (opc!=5);
        std::cout<<"Saliendo...";


    return 0;

}
