 /*
  Archivo: Barca.cpp
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

#include "Barca.h"
#include<iostream>
#include <string>
using namespace std;

Barca::Barca(string lugarNombre) 
: Lugar(lugarNombre), posicion(1)
{

}

int Barca::posicionBarca()
{
  return posicion;
}

int Barca::moverBarca()
{
  if (posicionBarca()==1) 
    return posicion++;
  else
    return posicion--;
}

int Barca::dimeDondeEstaEnLaBarca(string id)
{
  if (this->contadorDeIndividuos()==0)
  {
    return 4; //Posición arbitraria
  }
  else 
  {
    int dondeEsta=4;
    for(int cualIndividuo=0; cualIndividuo<individuosEnElLugar.size(); cualIndividuo++)
    {
      if (individuosEnElLugar.at(cualIndividuo)->letraMayuscula()==id)
      {
        dondeEsta = individuosEnElLugar.at(cualIndividuo)->posicionIndividuo();
      }
    }  
    return dondeEsta;
  }
}

string Barca::companyeroDeBarca()
{
  string idCompanyero;
  for(int cualIndividuo=0; cualIndividuo<individuosEnElLugar.size(); cualIndividuo++)
  {
    if (individuosEnElLugar.at(cualIndividuo)->letraMayuscula()!="R")
    {
      idCompanyero = individuosEnElLugar.at(cualIndividuo)->letraMayuscula();
    }
  }     
  return idCompanyero;
}

Barca::~Barca()
{
  //Se destruye en main
}