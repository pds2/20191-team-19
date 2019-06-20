#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "../include/carta.h"

using namespace std;

Carta::Carta()
{
    int peso = 1 + rand() % 10;
    this->_nome = "nome";
    this->_naipe = "naipe";
    this->_peso = peso;
    this->geraNome(peso);
    this->geraNaipe();
    this->conferirManilha();
}

void Carta::geraNome(int peso)
{
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
    switch(n)
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

string Carta::get_nome()
{
    string nome = this->_nome;
    cout << this->_nome;
    return nome;
}

int Carta::get_peso()
{
  return this->_peso;
}

string Carta::get_naipe()
{
  return this->_naipe;
}

Carta::Carta(int peso){
    this->_naipe = "naipe";
    this->_nome = "nome";
    this->_peso = peso;
    this->geraNome(peso);
    this->geraNaipe();
    this->conferirManilha();
}
