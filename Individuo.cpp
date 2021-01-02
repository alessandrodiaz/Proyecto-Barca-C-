/*
  Archivo: Individuo.cpp
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

#include "Individuo.h"
#include<iostream>
#include <string>
using namespace std;

Individuo::Individuo(string nombre, string idMayuscula, string idMinuscula, string identificacionPresa) 
  : nombre(nombre), idMayuscula(idMayuscula), idMinuscula(idMinuscula), identificacionPresa(identificacionPresa), posicion(0)
{
  
}

Individuo::Individuo(string nombre, string idMayuscula, string idMinuscula) 
  : nombre(nombre), idMayuscula(idMayuscula), idMinuscula(idMinuscula), posicion(0)
{

}

string Individuo::imprimirNombreIndividuo()
{
  string barraNombre = nombre;
  int espacios = 9 - barraNombre.length();
  for (int numero = 0; numero < espacios; numero++)
  {
    barraNombre += " ";
  }
  return barraNombre;
}

string Individuo::nombreIndividuo()
{
  return nombre;
}

string Individuo::letraMayuscula()
{
  return idMayuscula;
}

string Individuo::letraMinuscula()
{
  return idMinuscula;
}

string Individuo::letraPresa()
{
  return identificacionPresa;
}

int Individuo::posicionIndividuo()
{
  return posicion;
}

int Individuo::moverIndividuo()
{

  return posicion++;
}

int Individuo::retrocederIndividuo()
{
  return posicion--;
}

Individuo::~Individuo()
{
  //Se destruye en main
}
