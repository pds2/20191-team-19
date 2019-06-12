#ifndef CARTA_H
#define CARTA_H

#include <string>

using namespace std;

class Carta{
    private:
        string _nome;
        int _peso;
        string _naipe;
        void geraNaipe();
        void conferirManilha();
        void geraNome(int peso);
    public:
        Carta();
        Carta(int peso);
        string get_nome();
        int get_peso();
        string get_naipe();
        ;
};

#endif
