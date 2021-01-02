/*
  Archivo: Orilla.h
  Autores:
    Juan Manuel Castillo Molina - 1941563
    Alejandro Marroquín Almeida - 1942529    
    Alessandro Díaz García - 1940983 
  Emails:               
    <juan.manuel.castillo@correounivalle.edu.co>
    <alejandro.marroquin@correounivalle.edu.co>  
    <alessandro.diaz@correounivalle.edu.co>
  Fecha creación: 2020-10-04
  Fecha última modificación: 2020-12-11
  Versión: 2.0
  Licencia: GNU-GPL
*/

/*
  Clase: Orilla
  Atributos: 
    - Hereda de Lugar
  Funcionalidades:
    - Hereda de Lugar
  Relaciones: Orilla ES UN Lugar
*/

#ifndef ORILLA_H      // GUARDAS
#define ORILLA_H      // GUARDAS

#include "Lugar.h"
#include "Barca.h"
#include <string>
#include <vector>
using namespace std;

//Orilla ES UN Lugar - herencia
class Orilla : public Lugar
{
  protected:

  public: 

    //Consructor
    Orilla(string lugarNombre); 

    //Destructor
    virtual ~Orilla();

};

#else
class Orilla; // Declaración adelantada
#endif