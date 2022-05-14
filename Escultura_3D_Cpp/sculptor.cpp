#include "sculptor.hpp"
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

//Função construtora
Sculptor::Sculptor(int _nx, int _ny, int _nz){

    this -> nx = _nx;
    this -> ny = _ny;
    this -> nz = _nz;

    this -> r = 0;
    this -> g = 0;
    this -> b = 0;
    this -> a = 0;

    //Reservando memória
    vox = new Voxel**[_nx];
    for(int i = 0; i < _nx; i++){
        vox[i] = new Voxel*[_ny];
        for(int j = 0; j < _ny; j++){
            vox[i][j] = new Voxel[_nz];
            for(int k = 0; k < -nz; k++){
                this -> vox[i][j][k].r = 0;
                this -> vox[i][j][k].g = 0;
                this -> vox[i][j][k].b = 0;
                this -> vox[i][j][k].a = 0;
                this -> vox[i][j][k].isOn = false;
            }
        }
    }
}

//Função destrutora
Sculptor::~Sculptor(){
    for(int i = 0; i < nx; i++){
        for( int j = 0; j < ny; j++){
            delete[]vox[i][j];
        }
        delete[]vox [i];
    }
    delete[]vox;
}

//Cores
void Sculptor::setColor(float r, float g, float b, float alpha){
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = alpha;
}
