/*
  Archivo: Individuo.h
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
  Clase: Individuo
  Atributos:
    - Nombre del Individuo
    - Letra de identificación en minúscula y mayúscula
    - Posición en el juego
    - Letra de identificación de la presa
  Funcionalidades:
    - Puede ajustar el nombre del Individuo a los espacios necesarios para ser impreso en la pantalla
    - Puedo preguntarle la letra mayúscula de identificación del Individuo
    - Puedo preguntarle la letra minúscula de identificación del Individuo
    - Puedo preguntarle la letra de identificación de la presa del Individuo (si es que puede matar a alguien)
    - Puedo preguntarle la posición del Individuo en el juego 
    - Puedo pedirle que avance al Individuo en una posición
    - Puedo pedirle que retroceda al Individuo en una posición
    - Puedo pedirle que retorne el nombre del Individuo (sin ninguna modificación)

*/

#ifndef INDIVIDUOS_H      // GUARDAS
#define INDIVIDUOS_H      // GUARDAS

#include <string>
#include <vector>

using namespace std;

class Individuo
{
  protected:

    //Nombre del individuo
    string nombre;

    //Letra de identificación en mayúscula (para que acepte ambas entradas del usuario)
    string idMayuscula;

    //Posición del Individuo (los individuos empiezan en la posición 0 (orilla izquierda), llegan hasta la posición 3 (orilla derecha))
    int posicion;

    //Letra de identificación de la presa
    string identificacionPresa;

    //Letra de identificación en minúscula (para que acepte ambas entradas del usuario)
    string idMinuscula; 

  public:

    //Constructor 
    Individuo(string nombre, string idMayuscula, string idMinuscula, string identificacionPresa);

    //Constructor sobrecargado para individuos que no tengan ninguna presa
    Individuo(string nombre, string idMayuscula, string idMinuscula);

    //Destructor Individuos
    virtual ~Individuo();

    //Imprime el nombre del Individuo ajustándolo como debe mostrarse en el cuadro del juego
    virtual string imprimirNombreIndividuo(); 

    //Imprime la letra mayúscula del Individuo
    virtual string letraMayuscula();

    //Imprime la letra minúscula del Individuo
    virtual string letraMinuscula();

    //Imprime la letra de identificación de la presa
    virtual string letraPresa();

    //Retorna la posición del Individuo como int (los individuos empiezan en la posición 0 (orilla izquierda), llegan hasta la posición 3 (orilla derecha))
    virtual int posicionIndividuo();

    //Avanza al Individuo en una posición
    virtual int moverIndividuo();

    //Imprime el nombre del Individuo
    virtual string nombreIndividuo();

    //Retrocede al Individuo en una posición
    virtual int retrocederIndividuo();
};

#else
class Individuos; // Declaración adelantada
#endif