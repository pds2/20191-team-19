#include "include/mesa.h"
#include "include/carta.h"

Mesa::Mesa(){
    for(int i = 0; i < 4; i++){
        this->cartas[i] = 0;
    }
}

Mesa m = Mesa();
m.cartas[0] = c;