/*
  Archivo: Barca.h
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

/**
  Clase: Barca
  Atributos:
    - Hereda de Lugar
    - Posición en el juego
  Funcionalidades:
    - Puedo preguntarle en que posición está la Barca
    - Puedo pedirle que avance o retroceda la Barca
    - Puedo preguntarle en qué lado de la Barca está un Individuo
    - Puedo preguntarle quién acompana al robot en la Barca
  Relaciones: 
    - Barca ES PARECIDO A un Lugar (hereda de Lugar)
*/

#ifndef BARCA_H      // GUARDAS
#define BARCA_H      // GUARDAS

#include "Individuo.h"
#include "Jugador.h"
#include "Lugar.h"
#include "Orilla.h"
#include <string>
#include <vector>

using namespace std;

//Barca ES PARECIDO A UN Lugar - Herencia
class Barca: public Lugar
{
  protected:
  
    //Posición de la Barca (solo puede ser 1 o 2)
    int posicion;
  
  public:

    //Constructor
    Barca(string lugarNombre);
    
    //Destructor
    virtual ~Barca();

    //Muestra la posición de la Barca como int (solo puede ser 1 o 2)
    virtual int posicionBarca();

    //Avanza o retrocede la Barca según su posición (Avanza si su posición es 1, retrocede si su posición es 2)
    virtual int moverBarca();

    //Retorna la posición del Individuo que se indique en la Barca como int
    virtual int dimeDondeEstaEnLaBarca(string id);

    //Devuelve la identificación de quién acompaña al Robot en la Barca
    virtual string companyeroDeBarca();

};

#else
class Barca; // Declaración adelantada (guarda de Ángel GB)
#endif