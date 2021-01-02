/*
  Archivo: Lugar.cpp
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

#include "Lugar.h"
#include<iostream>
#include <string>
using namespace std;

Lugar::Lugar(string lugarNombre) : lugarNombre(lugarNombre)
{
}

void Lugar::agregarEnLugar(Individuo *individuo)
{
  individuosEnElLugar.push_back(individuo);  
}

void Lugar::borrarDelLugar(Individuo *individuo)
{
  int indice;
  for(int cualIndividuo=0; cualIndividuo<individuosEnElLugar.size(); cualIndividuo++) 
  {
    if(individuosEnElLugar.at(cualIndividuo)->letraMayuscula()==individuo->letraMayuscula())
    {
      indice=cualIndividuo;
      individuosEnElLugar.erase(individuosEnElLugar.begin()+indice);
    }   
  }    
}

bool Lugar::hayMuertosEnElLugar()
{
  bool estaElRobot=false;
  for (int cualIndividuo=0; cualIndividuo<individuosEnElLugar.size(); cualIndividuo++)
  {
    if (individuosEnElLugar.at(cualIndividuo)->letraMayuscula()=="R")
    {
      estaElRobot=true;
    }
  }

  if (estaElRobot==true || individuosEnElLugar.size()==0)
  {
    return false;
  }
  else
  {
    bool declaracionMuertos=false;
    for (int cualIndividuo=0; cualIndividuo < individuosEnElLugar.size(); cualIndividuo++)
    {  
      for (int individuoAComparar=0; individuoAComparar < individuosEnElLugar.size(); individuoAComparar++)
      {
        if (individuosEnElLugar.at(cualIndividuo)->letraMayuscula()==individuosEnElLugar.at(individuoAComparar)->letraPresa())
        {
          cout << "\n-> El " + individuosEnElLugar.at(individuoAComparar)->nombreIndividuo() + " ha matado al individuo " + individuosEnElLugar.at(cualIndividuo)->nombreIndividuo() <<endl;
          declaracionMuertos = true;         
        }                  
      }
    }
    return declaracionMuertos;
  }
}

int Lugar::contadorDeIndividuos()
{
  int cantidad = individuosEnElLugar.size();
  return cantidad;
}

Lugar::~Lugar()
{
  //Se destruye en main
}