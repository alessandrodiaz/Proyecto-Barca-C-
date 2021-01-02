/*
  Archivo: main.cpp
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
  Historia: Se implementará el juego del zorro, el conejo y la lechuga. El juego consiste en lo siguiente: hay un robot que debe transportar un zorro, un conejo y una lechuga desde un lado del río hasta la otra orilla, usando una barca. En la barca solo cabe uno de los tres individuos, además del robot. El problema es que si el robot deja solos al zorro y el conejo, el zorro se comerá el conejo. Y si deja solos al conejo y la lechuga, el conejo se comerá la lechuga. El usuario-jugador debe controlar que órdenes dar, para lograr que el robot transporte los tres individuos a la otra orilla, sanos y salvos.
*/

//valgrind --tool=memcheck --leak-check=full ./main

#include "Barca.h"
#include "Individuo.h"
#include "Jugador.h"
#include "Lugar.h"
#include "Orilla.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() 
{
  //Crea 4 objetos de la clase Individuo
  Individuo *robot = new Individuo(    "Robot", "R", "r");  
  Individuo *lechuga = new Individuo("Lechuga", "L", "l");
  Individuo *conejo = new Individuo(  "Conejo", "C", "c","L");
  Individuo *zorro = new Individuo(    "Zorro", "Z", "z","C");
  //Individuo *robot2 = new Individuo(   "Robot2", "R", "r");

  //Los 4 objetos se agregan a un vector
  vector <Individuo *> individuos = {robot, zorro, conejo, lechuga/*, robot2*/};
  
  //Creación de una barca, dos orillas y un jugador nuevo
  Barca *laBarca = new Barca("BARCA");
  Orilla *izquierda = new Orilla("IZQUIERDA");
  Orilla *derecha = new Orilla("DERECHA");
  Jugador *usuario = new Jugador(individuos, laBarca, izquierda, derecha);

  //Agrega los individuos a la izquierda
  izquierda->agregarEnLugar(robot);
  izquierda->agregarEnLugar(conejo);
  izquierda->agregarEnLugar(zorro);
  izquierda->agregarEnLugar(lechuga);
  //izquierda->agregarEnLugar(robot2);

  cout << "\n··············   JUEGO LA BARCA   ··············\n"<<endl;
  cout << "Tu objetivo es hacer que el robot lleve al zorro,\nconejo  y lechuga  a la  orilla  derecha sin que\nninguno  de ellos muera: El zorro mata al conejo\ny el conejo se come a la lechuga. \n \nLas instrucciones son: \n- Presiona la letra  inicial del Individuo para\n  subirlo a la barca. \n- Se aconseja que para bajar un individuo de la\n  barca, primero bajar al robot para evitar que\n  un individuo muera.\n\n " <<endl;

  //Inicia el juego
  usuario->jugar();

  //Borra todos los objetos creados con new, después de que finaliza el juego
  delete robot;
  delete lechuga;
  delete conejo;
  delete zorro;
  delete laBarca;
  delete izquierda;
  delete derecha;
  delete usuario;
  //delete robot2;
  
  return 0;
}