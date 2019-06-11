#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "../include/carta.h"

using namespace std;

void Carta::geraNome(int peso)
{
    string nome;
    switch (peso)
    {
    case 1:
        this->_nome = "4";
        break;
    case 2:
        this->_nome = "5";
        break;

    case 3:
        this->_nome = "6";
        break;

    case 4:
        this->_nome = "7";
        break;

    case 5:
        this->_nome = "Q";
        break;

    case 6:
        this->_nome = "J";
        break;

    case 7:
        this->_nome = "K";
        break;

    case 8:
        this->_nome = "A";
        break;

    case 9:
        this->_nome = "2";
        break;

    default:
        this->_nome = "3";
        break;
    }
}

void Carta::geraNaipe()
{
    int n = 1 + (rand() % 4);
    string naipe;
    switch (n)
    {
    case 1:
        this->_naipe = "♦ OUROS";
        break;

    case 2:
        this->_naipe = "♣ PAUS";
        break;

    case 3:
        this->_naipe = "♥ COPAS";
        break;

    default:
        this->_naipe = "♠ ESPADAS";
        break;
    }
}

void Carta::conferirManilha()
{
    if (this->_nome == "4" && this->_naipe == "PAUS")
    {
        this->_peso = 14;
    }
    else if (this->_nome == "7")
    {
        if (this->_naipe == "OUROS")
        {
            this->_peso = 11;
        }
        else if (this->_naipe == "COPAS")
        {
            this->_peso = 13;
        }
    }
    else if (this->_nome == "A" && this->_naipe == "ESPADAS")
    {
        this->_peso = 12;
    }
}

Carta::Carta()
{
    int peso = 1 + rand() % 10;
    this->_peso = peso;
    Carta::geraNome(peso);
    Carta::geraNaipe();
    Carta::conferirManilha();
}

string Carta::get_nome()
{
  return _nome;
}

int Carta::get_peso()
{
  return _peso;
}

string Carta::get_naipe()
{
  return _naipe;
}

Carta::Carta(int peso){
    this->_peso = peso;
    Carta::geraNome(peso);
    Carta::geraNaipe();
    Carta::conferirManilha();
}