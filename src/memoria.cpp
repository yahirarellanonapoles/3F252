#include <iostream>
#include <list>
using namespace std;

class persona{
    public:
    char nombre[10];
    int edad;
};

class empleado : public persona {
    public:
    int noEmpleado;
};

class alumno : public persona {
    public:
    int registro;
}

int main(int argc, char const *argv[])
{
    cout << "tamaño de los tipos de datos: " << endl;
    cout << "Tamaño int: "<< sizeof(int) << endl;
    cout << "Tamaño long: "<< sizeof(long) << endl;
    cout << "Tamaño float: "<< sizeof(float) << endl;
    cout << "Tamaño double: "<< sizeof(double) << endl;
    cout << "Tamaño bool: "<< sizeof(bool) << endl;
    cout << "Tamaño char: "<< sizeof(char) << endl;
    cout << "Tamaño byte: "<< sizeof(byte) << endl;

    cout << "direcciones de memoria: " << endl;
    cout << "punteros en c: " << malloc(sizeof(int)) << endl;
    cout << "punteros en c++: " << new int << endl;

    cout << "tamaño de punteros" << endl;
    cout << "int*: " << sizeof(int*) << endl;
    cout << "char*: " << sizeof(char*) << endl;

    cout << "casteo de tipos" << endl;
    //casteo de punteros
    int* puntero = (int*)malloc(sizeof(int));
    
    //casteo de variables
    int ejemplo = 65;
    char letra = (char)ejemplo;


    //casteo polimorfismo
    persona* Persona = new empleado();
    persona* Persona2 = new alumno();

    list<persona*> personas;
    personas.emplace_back(Persona);
    personas.emplace_back(Persona2);

    cout << (*Persona).edad << endl;
    cout << (*Persona).nombre << endl;
    cout << (*Persona).noEmpleado << endl;
    cout << Persona->edad << endl;
    cout << Persona->nombre << endl;
//tratar a todos como personas
   for (auto &&p : personas)
   {
    cout<< Persona->nombre << endl;
    cout<< Persona ->edad << endl;
   }
   
    return  0;
}