/*
  Archivo: Jugador.cpp
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
#include "Jugador.h"
#include<iostream>
#include <string>
using namespace std;

Jugador::Jugador(vector <Individuo*> individuos, Barca *laBarca, Orilla *izquierda, Orilla *derecha)
: individuos(individuos), laBarca(laBarca), izquierda(izquierda), derecha(derecha)
{
  
}

void Jugador::jugar()
{
  bool elJuegoContinua=true;
  while(elJuegoContinua!=false)
  {
    string barrasLugares = imprimirBarrasLugares();
    string barrasIndividuos = imprimirBarrasIndividuos();
    string tecladoUsuario;
    cout<< barrasLugares <<endl;
    cout<< barrasIndividuos <<endl;
    this->accionJugador();
    if (laBarca->hayMuertosEnElLugar()==true || izquierda->hayMuertosEnElLugar()==true || derecha->hayMuertosEnElLugar()==true)
    {
      cout << "\n-> HAS PERDIDO\n" << endl;;
      elJuegoContinua=false;
    }
    else if (derecha->contadorDeIndividuos()==individuos.size())
    {
      cout << "\n-> ¡GANASTE!\n" <<endl;;
      elJuegoContinua=false;
    }
  }
  exit(0);
}

void Jugador::accionJugador()
{
  string tecladoUsuario;
  cout<<"¿Qué deseas mover? ";
  getline(cin, tecladoUsuario);
 
  if (tecladoUsuario=="B" || tecladoUsuario=="b")
  { 
    if((laBarca->dimeDondeEstaEnLaBarca("R"))==(laBarca->posicionBarca()))
    {
      if (laBarca->posicionBarca()==1)
      {
        this->comoMoverIndividuo("R", false);
        if (laBarca->contadorDeIndividuos()==2)
        {
        string companiaRobot;
        companiaRobot = laBarca->companyeroDeBarca();
        this->comoMoverIndividuo(companiaRobot, false);
        laBarca->moverBarca();
        }
        else 
        {
        laBarca->moverBarca();
        } 
      }
      else if (laBarca->posicionBarca()==2)
      {
        this->comoMoverIndividuo("R", false);
        if (laBarca->contadorDeIndividuos()==2)
        {
        string companiaRobot;
        companiaRobot = laBarca->companyeroDeBarca();
        this->comoMoverIndividuo(companiaRobot, false);
        laBarca->moverBarca();
        }
        else 
        {
        laBarca->moverBarca();
        } 
      }
           
    }
    else 
    {
      this->ordenNoValida();
    }      
  }
  else 
  {
    this->comoMoverIndividuo(tecladoUsuario, true);
  }  
}
 
void Jugador::comoMoverIndividuo(string tecladoUsuario, bool reversa)
{
  for(int cualIndividuo=0; cualIndividuo<individuos.size(); cualIndividuo++)
  {
    if (individuos.at(cualIndividuo)->letraMayuscula()==tecladoUsuario || individuos.at(cualIndividuo)->letraMinuscula()==tecladoUsuario)
    {
      if (individuos.at(cualIndividuo)->posicionIndividuo()==0 && laBarca->posicionBarca()==1)
      {
        if (laBarca->contadorDeIndividuos()==2)
        {
          this->ordenNoValida();
        }
        else 
        {
          individuos.at(cualIndividuo)->moverIndividuo();
          laBarca->agregarEnLugar(individuos.at(cualIndividuo));
          izquierda->borrarDelLugar(individuos.at(cualIndividuo)); 
        }          
      }
      else if (individuos.at(cualIndividuo)->posicionIndividuo()==1) 
      {
        if (laBarca->posicionBarca()==1 && reversa==false)
        {
          individuos.at(cualIndividuo)->moverIndividuo();
        }
        else if (reversa==true)
        {
          izquierda->agregarEnLugar(individuos.at(cualIndividuo));
          laBarca->borrarDelLugar(individuos.at(cualIndividuo));
          individuos.at(cualIndividuo)->retrocederIndividuo();
        }
      }
      else if (individuos.at(cualIndividuo)->posicionIndividuo()==2) 
      {
        if (laBarca->posicionBarca()==2 && reversa==true)
        {
          derecha->agregarEnLugar(individuos.at(cualIndividuo));
          laBarca->borrarDelLugar(individuos.at(cualIndividuo));
          individuos.at(cualIndividuo)->moverIndividuo();
        }
        else if (reversa==false)
        {
          individuos.at(cualIndividuo)->retrocederIndividuo();
        } 
      }
      else if (individuos.at(cualIndividuo)->posicionIndividuo()==3 && laBarca->posicionBarca()==2) 
      {
        if (laBarca->contadorDeIndividuos()==2)
        {
          this->ordenNoValida();
        }
        else
        {
          derecha->borrarDelLugar(individuos.at(cualIndividuo));
          laBarca->agregarEnLugar(individuos.at(cualIndividuo));
          individuos.at(cualIndividuo)->retrocederIndividuo();
        } 
      }
    }
    else if (tecladoUsuario!="B" && tecladoUsuario!="b" && tecladoUsuario!="R" && tecladoUsuario!="r" && tecladoUsuario!="Z" && tecladoUsuario!="z" && tecladoUsuario!="C" && tecladoUsuario!="c" && tecladoUsuario!="L" && tecladoUsuario!="l")
    {
      this->ordenNoValida();
    }
  } 
}


void Jugador::ordenNoValida()
{
  cout<<"\n-> POR FAVOR ESCRIBE UNA ORDEN VÁLIDA\n"<<endl;
  this->jugar();
}

string Jugador::imprimirBarrasLugares()
{
  string barrasLugares;
  if (laBarca->posicionBarca()==1)
    barrasLugares = "| IZQUIERDA |  BARCA    |           |  DERECHA  |";
  else if (laBarca->posicionBarca()==2)
    barrasLugares = "| IZQUIERDA |           |  BARCA    |  DERECHA  |";
  return barrasLugares;
}

string Jugador::imprimirBarrasIndividuos()
{
  string barrasIndividuos;
  for(int cualIndividuo = 0; cualIndividuo < individuos.size(); cualIndividuo++)
  {
    for(int lugarContador = 0; lugarContador < 4; lugarContador++)
    {
      if(individuos.at(cualIndividuo)->posicionIndividuo()==lugarContador)
      {        
          barrasIndividuos += "|  " + individuos.at(cualIndividuo)->imprimirNombreIndividuo();
          if (lugarContador == 3)
            barrasIndividuos += "|\n"; 
          else if (lugarContador == 2)
            barrasIndividuos += "|           |\n";
          else if (lugarContador == 1)
            barrasIndividuos += "|           |           |\n";
          else if (lugarContador ==0)
            barrasIndividuos += "|           |           |           |\n";
          break;   
        lugarContador=0;
      }
      else
        barrasIndividuos += "|           ";
    } 
  }
  return barrasIndividuos;
}

Jugador::~Jugador()
{
  //Se destruye en main
}