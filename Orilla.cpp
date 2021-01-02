/*
  Archivo: Orilla.cpp
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

#include "Orilla.h"
#include<iostream>
#include <string>
using namespace std;

Orilla::Orilla(string lugarNombre) : Lugar(lugarNombre)
{

}

Orilla::~Orilla()
{
 //Se destruye en main 
}