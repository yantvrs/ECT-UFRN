#include <iostream>
#include "sculptor.hpp"
using namespace std;

int main(){

  Sculptor ect(80,60,50);

  //Piso cinza
  ect.setColor(211, 211, 211, 10);
  ect.putBox(0,73,0,1,0,45);

  //box por trás do predio
  ect.setColor(238, 238, 224, 10);
  ect.putBox(2,9,1,6,5,12);
  ect.cutBox(3,8,5,6,6,11);

  //box 0
  ect.setColor(238, 238, 224, 10);
  ect.cutBox(2,7,1,21,15,22);
  ect.putBox(2,7,1,21,15,22);
  ect.cutBox(3,7,20,21,16,21);

  //box 1
  ect.setColor(238, 238, 224, 10);
  ect.putBox(6,27,1,19,18,32);

  ect.cutBox(20,27,1,20,10,18);
  ect.putBox(20,27,1,24,10,18);

  //box 2
  ect.setColor(238, 238, 224, 10);
  ect.putBox(31,58,1,19,5,22);

  ect.putBox(31,41,1,19,22,32);

  //box 3
  ect.cutBox(57,62,1,21,18,25);
  ect.putBox(57,62,1,21,18,25);
  ect.cutBox(57,61,20,21,19,24);

  //box 4
  ect.cutBox(61,63,1,6,20,25);
  ect.putBox(61,70,1,6,8,27);
  ect.cutBox(61,70,5,6,17,18);
  ect.putBox(58,61,1,3,15,18);

  //Parada

  ect.putBox(6,7,1,6,40,41);
  ect.putBox(2,3,1,6,40,41);
  ect.putBox(10,11,1,6,40,41);

  ect.putBox(1,12,5,6,38,43);

  //bancos parada
  ect.setColor(0, 0, 0, 10);
  ect.putBox(3,4,1,2,39,42);

  ect.putBox(5,6,1,2,39,42);
  ect.putBox(7,8,1,2,39,42);

  ect.putBox(9,10,1,2,39,42);

  //banco entrada ect
  ect.setColor(0, 0, 0, 10);

  ect.putBox(27,28,1,2,26,27);
  ect.putBox(27,28,1,2,28,29);
  ect.putBox(27,28,1,2,30,31);

  ect.putBox(30,31,1,2,26,27);
  ect.putBox(30,31,1,2,28,29);
  ect.putBox(30,31,1,2,30,31);

  ect.putBox(27,28,1,2,11,12);
  ect.putBox(27,28,1,2,13,14);

  ect.putBox(30,31,1,2,11,12);
  ect.putBox(30,31,1,2,13,14);

  //Paredes
  ect.setColor(139, 137, 137, 10);
  ect.putBox(41,58,1,4,24,25);

  ect.putBox(7,13,1,4,15,16);
  ect.putBox(14,20,1,4,15,16);

  ect.putBox(24,31,1,4,24,25);
  ect.putBox(24,31,1,4,15,16);


  //Vigas frontais
  ect.setColor(238, 238, 224, 10);
  ect.putBox(41,58,4,5,24,25);

  ect.putBox(41,58,4,5,24,25);

  ect.putBox(41,58,8,9,24,25);

  ect.putBox(41,58,12,13,24,25);

  ect.putBox(41,58,16,17,24,25);

  ect.putBox(57,58,1,19,31,32);

  ect.putBox(49,50,1,19,24,25);

  ect.putBox(49,50,1,19,31,32);

  ect.putBox(49,50,4,5,22,25);
  ect.putBox(49,50,8,9,22,25);
  ect.putBox(49,50,12,13,22,25);
  ect.putBox(49,50,16,17,22,25);

  //Pisos frontais
  ect.setColor(238, 238, 224, 10);

  ect.cutBox(27,57,5,8,18,22);
  ect.cutBox(27,57,9,12,18,22);
  ect.cutBox(27,57,13,16,18,22);


  //Vigas externas
  ect.setColor(238, 238, 224, 10);

  ect.putBox(7,20,4,5,15,16);

  ect.putBox(7,20,8,9,15,16);

  ect.putBox(7,20,12,13,15,16);

  ect.putBox(7,20,16,17,15,16);

  ect.putBox(13,14,1,19,15,16);

  ect.putBox(13,14,4,5,16,19);
  ect.putBox(13,14,8,9,16,19);
  ect.putBox(13,14,12,13,16,19);
  ect.putBox(13,14,16,17,16,19);


  //Pisos externos
  ect.setColor(238, 238, 224, 10);

  ect.cutBox(7,27,5,8,18,22);
  ect.cutBox(7,27,9,12,18,22);
  ect.cutBox(7,27,13,16,18,22);


  //Pisos da união

  ect.putBox(27,32,4,5,18,22);
  ect.putBox(27,32,8,9,18,22);
  ect.putBox(27,32,12,13,18,22);

  //Grama baixo frente

  ect.setColor(179, 238, 58, 10);
  ect.putBox(2,27,0,1,21,35);
  ect.putBox(31,44,0,1,24,35);
  ect.putBox(46,53,0,1,24,35);
  ect.putBox(55,70,0,1,24,35);

  ect.putBox(15,28,0,1,37,43);
  ect.putBox(30,53,0,1,37,43);
  ect.putBox(55,70,0,1,37,43);

  //Grama baixo externo
  ect.setColor(179, 238, 58, 10);
  ect.putBox(2,10,0,1,3,13);
  ect.putBox(12,16,0,1,3,15);
  ect.putBox(18,27,0,1,3,15);
  ect.putBox(31,59,0,1,3,15);
  ect.putBox(60,70,0,1,3,15);

  //Grama alto frente
  ect.setColor(105, 139, 34, 10);
  ect.putBox(2,3,1,2,22,35);
  ect.putBox(2,28,1,2,34,35);
  ect.putBox(27,28,1,2,32,35);

  ect.putBox(30,31,1,2,32,35);
  ect.putBox(31,44,1,2,34,35);
  ect.putBox(43,44,1,2,24,35);

  ect.putBox(46,47,1,2,24,35);
  ect.putBox(47,52,1,2,34,35);
  ect.putBox(52,53,1,2,24,35);

  ect.putBox(55,56,1,2,24,35);
  ect.putBox(55,70,1,2,34,35);
  ect.putBox(69,70,1,2,27,35);

  ect.putBox(15,16,1,2,37,43);
  ect.putBox(15,28,1,2,37,38);
  ect.putBox(15,28,1,2,42,43);
  ect.putBox(27,28,1,2,37,43);

  ect.putBox(30,31,1,2,37,43);
  ect.putBox(30,53,1,2,37,38);
  ect.putBox(30,53,1,2,42,43);
  ect.putBox(52,53,1,2,37,43);

  ect.putBox(55,56,1,2,37,43);
  ect.putBox(55,70,1,2,37,38);
  ect.putBox(55,70,1,2,42,43);
  ect.putBox(69,70,1,2,37,43);

  //Grama alto externo


  ect.setColor(105, 139, 34, 10);

  ect.putBox(2,3,1,2,3,5);
  ect.putBox(2,10,1,2,3,4);
  ect.putBox(9,10,1,2,3,13);
  ect.putBox(2,10,1,2,12,13);

  ect.putBox(12,13,1,2,3,15);
  ect.putBox(15,16,1,2,3,15);
  ect.putBox(13,15,1,2,3,4);

  ect.putBox(18,19,1,2,3,15);
  ect.putBox(27,28,1,2,3,10);
  ect.putBox(18,27,1,2,3,4);

  ect.putBox(30,31,1,2,3,10);
  ect.putBox(58,59,1,2,3,15);
  ect.putBox(31,58,1,2,3,4);

  ect.putBox(60,61,1,2,3,15);
  ect.putBox(69,70,1,2,3,8);
  ect.putBox(61,69,1,2,3,4);


  //Janela frontal central
  ect.setColor(130, 130, 130, 10);

  ect.putBox(32,34,2,4,31,32);
  ect.putBox(35,37,2,4,31,32);
  ect.putBox(38,40,2,4,31,32);

  ect.putBox(32,34,6,8,31,32);
  ect.putBox(35,37,6,8,31,32);
  ect.putBox(38,40,6,8,31,32);

  ect.putBox(32,34,10,12,31,32);
  ect.putBox(35,37,10,12,31,32);
  ect.putBox(38,40,10,12,31,32);

  ect.putBox(32,34,14,16,31,32);
  ect.putBox(35,37,14,16,31,32);
  ect.putBox(38,40,14,16,31,32);

  //Janela frontal esquerda

  ect.putBox(7,10,2,4,31,32);
  ect.putBox(11,14,2,4,31,32);
  ect.putBox(15,18,2,4,31,32);
  ect.putBox(19,22,2,4,31,32);
  ect.putBox(23,26,2,4,31,32);

  ect.putBox(7,10,6,8,31,32);
  ect.putBox(11,14,6,8,31,32);
  ect.putBox(15,18,6,8,31,32);
  ect.putBox(19,22,6,8,31,32);
  ect.putBox(23,26,6,8,31,32);

  ect.putBox(7,10,10,12,31,32);
  ect.putBox(11,14,10,12,31,32);
  ect.putBox(15,18,10,12,31,32);
  ect.putBox(19,22,10,12,31,32);
  ect.putBox(23,26,10,12,31,32);

  ect.putBox(7,10,14,16,31,32);
  ect.putBox(11,14,14,16,31,32);
  ect.putBox(15,18,14,16,31,32);
  ect.putBox(19,22,14,16,31,32);
  ect.putBox(23,26,14,16,31,32);

  //Janela externa

  ect.putBox(32,35,2,4,5,6);
  ect.putBox(36,39,2,4,5,6);
  ect.putBox(40,44,2,4,5,6);
  ect.putBox(45,49,2,4,5,6);
  ect.putBox(50,53,2,4,5,6);
  ect.putBox(54,57,2,4,5,6);

  ect.putBox(32,35,6,8,5,6);
  ect.putBox(36,39,6,8,5,6);
  ect.putBox(40,44,6,8,5,6);
  ect.putBox(45,49,6,8,5,6);
  ect.putBox(50,53,6,8,5,6);
  ect.putBox(54,57,6,8,5,6);

  ect.putBox(32,35,10,12,5,6);
  ect.putBox(36,39,10,12,5,6);
  ect.putBox(40,44,10,12,5,6);
  ect.putBox(45,49,10,12,5,6);
  ect.putBox(50,53,10,12,5,6);
  ect.putBox(54,57,10,12,5,6);

  ect.putBox(32,35,14,16,5,6);
  ect.putBox(36,39,14,16,5,6);
  ect.putBox(40,44,14,16,5,6);
  ect.putBox(45,49,14,16,5,6);
  ect.putBox(50,53,14,16,5,6);
  ect.putBox(54,57,14,16,5,6);


  //Efeito chuva
  ect.setColor(135, 206, 235,1.0);
  for(int i = 0; i < 200; i++){
      int x = rand() % 80;
      int y = rand() % 60;
      int z = rand() % 50;
      ect.putVoxel(x,y,z);
  }


  ect.writeOFF((char*)"ect.off");

  return 0;
}
