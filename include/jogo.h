#ifndef JOGO_H
#define JOGO_H

class Jogo{
    protected:
        int _valorRodada;
        int _pntTimeA;
        int _pntTimeB;
        void novoJogo();
    public:
        Jogo(int opcao);
        void set_valorRodada(int valor);
        void set_pntTimeA(int valor);
        void set_pntTimeB(int valor);
        int get_valorRodada();
        int get_pntTimeA();
        int get_pntTimeB();
};

#endif 
