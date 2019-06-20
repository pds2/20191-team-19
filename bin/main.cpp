#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>
#include "../include/jogo.h"

using namespace std;
int main()
{
    srand((unsigned)time(NULL));
    system("clear");
    /*
        NAIPES:
        "♥"
        "♦"
        "♣"
        "♠"
        peso:
            4 = 1;
            5 = 2;
            6 = 3;
            7 = 4;
            Q = 5;
            J = 6;
            K = 7;
            A = 8;
            2 = 9;
            3 = 10;
            7 OUROS = 11;
            ESPADILHA = 12;
            7 COPAS = 13;
            ZAP = 14;
    */

      int opcao;
      string nome;
      string opcao_;
      while(true){
                  try{
                        cout << "*******************************************" << endl;
                        cout << "\t\t TRUCÃO MALADO " << endl;
                        cout << " Menu: " << endl;
                        cout << " 1 - Iniciar Jogo" << endl;
                        cout << " 2 - Carregar Jogo" << endl;
                        cout << " 3 - Sair" << endl;
                        cout << ">";
                        getline(cin, opcao_);
                        opcao=atoi(opcao_.c_str());
                          if(opcao !=1 && opcao != 2 && opcao != 3)
                          {
                            throw "Entrada inválida.";
                          }else
                              break;
                    }catch(const char* e)
                    {
  			                 cout << "Erro: " << e <<endl;
                         cout << "Escolha uma entrada valida" << endl;
                    }
                  }

    //Inicia o jogo atraves da opcao desejada
    Jogo j = Jogo(opcao);
    int ganhou = j.iniciarJogo();
    if(time){
        cout << "PARABÉNS, VOCÊ GANHOU!!";
    }else{
        cout << "TENTE NOVAMENTE MAIS TARDE";
    }
    return 0;
}
