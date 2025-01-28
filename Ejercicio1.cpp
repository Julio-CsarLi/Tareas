#include <iostream>

class empleado{
private: //Atributos deben de ir aqui
    int ClaveEmpleado;
    std::string Nombre;
    std::string Domicilio;
    float Sueldo;
    std::string ReportaA;
public:
    empleado(){ClaveEmpleado=0; Nombre=" "; Domicilio=" "; Sueldo=0; ReportaA=" ";} //constructor
    empleado(int e, float s, std::string nom){       //constructor con parametros
        ClaveEmpleado=e;
        Nombre=nom;
    }
    void setClaveEmpleado(int e) {ClaveEmpleado=e;}
    void setCambiaDomic(std::string dom){Domicilio = dom;}
    void setCambiaReportaA(std::string Report){ReportaA = Report;}
    void setActualSueldo(float s){Sueldo=s;}
    void setNombre(std::string nom){ Nombre=nom;}
    std::string getnombre(){return Nombre;}

    void Imprime(){
        std::cout<<" Mi clave es: "<<ClaveEmpleado<<std::endl;
        std::cout<<" Mi nombre es: "<<Nombre<<std::endl;
        std::cout<<" Y yo vivo en: "<<Domicilio<<std::endl;
        std::cout<<" mi sueldo es de: "<<Sueldo<<std::endl;
        std::cout<<" Mi reporte es: "<<ReportaA<<std::endl;
    }

};





int main()
{
    std::string p;
    int e,opcion, opcion2;
    float s;
    std::cout<<"Menu\n"<<std::endl;
    std::cout<<"1.- Jefe de personal"<<std::endl;
    std::cout<<"2.- Jefe de planta"<<std::endl;
    std::cout<<"3.- Salir\n"<<std::endl;
    std::cout<<"Selecciona una opcion:"<<std::endl;
    std::cin>>opcion;

    switch(opcion){
        case 1:
            {
            system("cls");
            std::cout<<"Has seleccionado Jefe de personal\n"<<std::endl;
            std::cout<<"Menu\n"<<std::endl;
            std::cout<<"1.- Capturar datos"<<std::endl;
            std::cout<<"2.- Modificar datos"<<std::endl;
            std::cout<<"3.- Salir\n"<<std::endl;
            std::cout<<"Selecciona una opcion:"<<std::endl;
            std::cin>>opcion2;
            system("cls");
            std::cout<<"Has seleccionado capturar datos\n"<<std::endl;
            empleado jefepersonal;
            std::cout<<"Cual es tu clave de empleado?\n";
            std::cin>>e;
            jefepersonal.setClaveEmpleado(e);
            std::cout<<"Como te llamas?\n";
            std::cin>>p;
            jefepersonal.setNombre(p);
            std::cout<<"Donde vives? \n";
            std::cin>>p;
            jefepersonal.setCambiaDomic(p);
            std::cout<<"Cual es tu sueldo? \n";
            std::cin>>s;
            jefepersonal.setActualSueldo(s);
            std::cout<<"Cual es tu reporte?\n";
            std::cin>>p;
            jefepersonal.setCambiaReportaA(p);
            jefepersonal.Imprime();
            }
            break;

        case 2:
            {
            system("cls");
            std::cout<<"Has seleccionado Jefe de planta\n"<<std::endl;
            empleado jefeplanta;
            std::cout<<"Cual es tu clave de empleado?\n";
            std::cin>>e;
            jefeplanta.setClaveEmpleado(e);
            std::cout<<"Como te llamas?\n";
            std::cin>>p;
            jefeplanta.setNombre(p);
            std::cout<<"Donde vives?\n";
            std::cin>>p;
            jefeplanta.setCambiaDomic(p);
            std::cout<<"Cual es tu sueldo?\n";
            std::cin>>s;
            jefeplanta.setActualSueldo(s);
            std::cout<<"Cual es tu reporte?\n";
            std::cin>>p;
            jefeplanta.setCambiaReportaA(p);
            jefeplanta.Imprime();
            }
            break;
        case 3:
            system("cls");
            std::cout<<"Saliendo...";
                }
    return 0;

}
