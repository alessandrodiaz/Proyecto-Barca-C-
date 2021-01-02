/*
  Archivo: Lugar.h
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
  Clase: Lugar
  Atributos: 
    - El nombre del Lugar
  Funcionalidades:
    - Puedo pedirle que agregue un Individuo al Lugar
    - Puedo pedirle que borre un Individuo del Lugar
    - Puedo preguntarle si algún Individuo ha muerto en el Lugar
    - Puedo pedirle que retorne la cantidad de individuos que hay en un Lugar
  Relaciones: 
    - Conoce los individuos que hay en el Lugar (vector de individuos)
*/

#ifndef LUGAR_H      // GUARDAS
#define LUGAR_H      // GUARDAS

#include "Individuo.h"
#include <string>
#include <vector>
using namespace std;

class Lugar
{
  protected: 
    
    vector <Individuo*> individuosEnElLugar;

    string lugarNombre;

  public: 
 
    //Constructor Lugar
    Lugar(string lugarNombre);

    //Destructor Lugar
    virtual ~Lugar();

    //Agrega un Individuo al Lugar
    virtual void agregarEnLugar(Individuo *individuo);

    //Borra un Individuo del Lugar
    virtual void borrarDelLugar(Individuo *individuo);
 
    //Retorna TRUE si hay un muerto en el Lugar, FALSE si no
    virtual bool hayMuertosEnElLugar();

    //Cuenta la cantidad de individuos que hay en el Lugar
    virtual int contadorDeIndividuos();

};

#else
class Lugar; // Declaración adelantada
#endif 