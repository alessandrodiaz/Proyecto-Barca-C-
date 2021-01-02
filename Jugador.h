/*
  Archivo: Jugador.h
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
  Clase: Jugador 
  Atributos:
    - 
  Funcionalidades:
    - Puedo pedirle que inicie el juego 
    - Puede recibir la indicación que digite el usuario
    - Puedo pedirle que decida cómo mover un Individuo según el que haya indicado el usuario
    - Puede imprimir un mensaje de error si el usuario ha digitado una orden no válida
    - Puede imprimir las barras de los lugares para que se impriman como debe en la pantalla
    - Puede imprimir el nombre de los individuos de manera que se ajusten correctamente a la pantalla del usuario
  Relaciones: 
    - Conoce una Barca
    - Conoce dos objetos Orilla
    - Conoce los individuos que puede mover (vector de individuos)
*/

#ifndef JUGADOR_H      // GUARDAS
#define JUGADOR_H      // GUARDAS

#include "Barca.h"
#include "Individuo.h"
#include "Lugar.h"
#include "Orilla.h"
#include <string>
#include <vector>

using namespace std;

class Jugador
{
  protected:

    vector <Individuo*> individuos;
    Barca *laBarca;
    Orilla *izquierda;
    Orilla *derecha;

  public:

    // Constructor Jugador
    Jugador(vector <Individuo*> individuos, Barca *laBarca, Orilla *izquierda, Orilla *derecha);

    // Destructor Jugador
    virtual ~Jugador();

    //Inicia el juego y lo finaliza cuando corresponda
    virtual void jugar();

    //Recibe la indicación del usuario
    virtual void accionJugador(); 

    //Algoritmo para decidir cómo mover el Individuo que indicó el usuario
    virtual void comoMoverIndividuo(string tecladoUsuario, bool reversa);

    //Retorna un mensaje de error cuando el usuario ordena acciones que no se pueden hacer
    virtual void ordenNoValida();

    //Imprime las barras de los lugares para mostrarlas en pantalla
    virtual string imprimirBarrasLugares();
    
    //Organiza los nombres de los individuos para imprimirlos en pantalla
    virtual string imprimirBarrasIndividuos();

};

#else
class Jugador; // Declaración adelantada
#endif  