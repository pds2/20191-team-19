#include "../include/computador.h"
#include "../third_party/doctest.h"
#include "../include/pessoa.h"

TEST_CASE("Testando o Construtor de Computador"){
  Computador pc1 = Computador("PC 1", 2, 1);
  Computador pc2 = Computador("PC 2", 1, 2);
  CHECK_EQ(pc1.get_nome(),"PC 1");
  CHECK_EQ(pc1.get_time(),2);
  CHECK_EQ(pc1.get_id(),1);
  CHECK_EQ(pc2.get_nome(),"PC 2");
  CHECK_EQ(pc2.get_time(),1);
  CHECK_EQ(pc2.get_id(),2);
}

TEST_CASE(" Testando o Construtor de Pessoa"){
    Pessoa p1= Pessoa("PESSOA 1");
    CHECK_EQ(p1.get_nome(),"PESSOA 1");
    CHECK_EQ(p1.get_time(),1);
}

TEST_CASE("Testando o Construtor de Carta"){
  Carta c1= Carta(10);
  CHECK_EQ(c1.get_peso(),10);

}
