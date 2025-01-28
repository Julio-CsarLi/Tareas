#include <iostream>

class materia{
private: //Atributos deben de ir aqui
    int clave;
    std::string nombre;
    std::string profesortit;
    std::string librotexto;
public:
    materia(){clave=0; nombre=" "; profesortit=" "; librotexto=" ";} //constructor
    materia(int e, std::string nom){       //constructor con parametros
        clave=e;
        nombre=nom;
    }
    void setclave(int e) {clave=e;}
    void setnombre(std::string nom){nombre = nom;}
    void setprofesortit(std::string profe){profesortit = profe;}
    void setlibrotexto(std::string librotex){librotexto = librotex;}
    std::string getnombre(){return nombre;}

    void Imprime(){
        std::cout<<" Mi clave es: "<<clave<<std::endl;
        std::cout<<" Mi nombre es: "<<nombre<<std::endl;
        std::cout<<" Y mi profesor es: "<<profesortit<<std::endl;
        std::cout<<" mi libro de texto es: "<<librotexto<<std::endl;
    }

};





int main()
{
    std::string p;
    int e,opcion, opcion2;
    std::cout<<"Menu\n"<<std::endl;
    std::cout<<"1.- Cambiar materia"<<std::endl;
    std::cout<<"2.- Cambiar maestro"<<std::endl;
    std::cout<<"3.- Salir\n"<<std::endl;
    std::cout<<"Selecciona una opcion:"<<std::endl;
    std::cin>>opcion;

    switch(opcion){
        case 1:
            {
            system("cls");
            std::cout<<"Has seleccionado cambiar materia\n"<<std::endl;
            std::cout<<"Menu\n"<<std::endl;
            std::cout<<"1.- Clave"<<std::endl;
            std::cout<<"2.- Nombre del maestro"<<std::endl;
            std::cout<<"3.- Salir\n"<<std::endl;
            std::cout<<"Selecciona una opcion:"<<std::endl;
            std::cin>>opcion2;
            system("cls");
            std::cout<<"Has seleccionado cambiar de clave\n"<<std::endl;
            materia programacion;
            std::cout<<"Cual es tu clave?\n";
            std::cin>>e;
            programacion.setclave(e);
            std::cout<<"Como te llamas?\n";
            std::cin>>p;
            programacion.setnombre(p);
            std::cout<<"Como se llama el profesor? \n";
            std::cin>>p;
            programacion.setprofesortit(p);
            std::cout<<"Cual es tu libro de texto? \n";
            std::cin>>p;
            programacion.setlibrotexto(p);
            programacion.Imprime();
            }
            break;

        case 2:
            {
            system("cls");
            std::cout<<"Has seleccionado cambiar maestro\n"<<std::endl;
            materia basesdatos;
            std::cout<<"Cual es la clave del profesor?\n";
            std::cin>>e;
            basesdatos.setclave(e);
            std::cout<<"Como te llamas?\n";
            std::cin>>p;
            basesdatos.setnombre(p);
            std::cout<<"Como se llama el profesor?\n";
            std::cin>>p;
            basesdatos.setprofesortit(p);
            std::cout<<"Cual es tu libro de texto?\n";
            std::cin>>p;
            basesdatos.setlibrotexto(p);
            basesdatos.Imprime();
            }
            break;
        case 3:
            system("cls");
            std::cout<<"Saliendo...";
                }
    return 0;

}
