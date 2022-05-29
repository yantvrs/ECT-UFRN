#include <iostream>
#include "sculptor.hpp"
using namespace std;

int main(){

  Sculptor ect(80,60,50);

  //Piso cinza
  ect.setColor(139, 139, 131, 10);
  ect.putBox(0,73,0,1,0,45);

  //box por trás do predio
  ect.setColor(238, 238, 224, 10);
  ect.putBox(6,12,1,6,4,11);
  ect.cutBox(7,11,5,6,5,10);

  //box 0
  ect.setColor(238, 238, 224, 10);
  ect.cutBox(2,7,1,21,20,25);
  ect.putBox(2,7,1,21,20,25);
  ect.cutBox(3,6,20,21,21,24);

  //box 1
  ect.setColor(238, 238, 224, 10);
  ect.putBox(6,27,1,19,15,32);

  ect.cutBox(17,27,1,20,8,17);
  ect.putBox(17,27,1,24,8,17);

  //box 2
  ect.setColor(238, 238, 224, 10);
  ect.putBox(31,58,1,19,5,22);

  ect.putBox(31,41,1,19,22,32);

  //box 3
  ect.cutBox(58,63,1,21,20,25);
  ect.putBox(58,63,1,21,20,25);
  ect.cutBox(59,62,20,21,21,24);

  //box 4
  ect.cutBox(61,63,1,6,20,25);
  ect.putBox(61,70,1,6,15,27);

  //Paredes(parte frontal)
  ect.setColor(139, 137, 137, 10);
  ect.putBox(41,58,1,4,24,25);

  //Vigas frontais
  ect.setColor(238, 238, 224, 10);
  ect.putBox(41,58,4,5,24,25);

  ect.putBox(41,58,4,5,24,25);

  ect.putBox(41,58,8,9,24,25);

  ect.putBox(41,58,12,13,24,25);

  ect.putBox(41,58,16,17,24,25);

  ect.putBox(56,57,1,19,31,32);







  ect.writeOFF((char*)"ect.off");

  return 0;
}

