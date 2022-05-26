#include <iostream>
#include "sculptor.hpp"
using namespace std;

int main(){
// cria um escultor cuja matriz tem 10x10x10 voxels
  Sculptor trono(50,50,50);
  // para mudar a cor do voxel
  trono.setColor(0,0,1.0,1.0); // azul
  // ativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
  trono.putBox(0,50,0,50,0,50);
  // desativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
  trono.cutBox(1,40,1,50,1,50);
  // grava a escultura digital no arquivo "trono.off"
  trono.writeOFF((char*)"trono.off");



  return 0;
}

