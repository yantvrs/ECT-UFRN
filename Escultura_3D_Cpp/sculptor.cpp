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

//Put voxel
void Sculptor::putVoxel(int x, int y, int z){
    this -> vox[x][y][z].r = this -> r;
    this -> vox[x][y][z].g = this -> g;
    this -> vox[x][y][z].b = this -> b;
    this -> vox[x][y][z].a = this -> a;
    this -> vox[x][y][z].isOn = true;
}

//Adicionando paralelepípedo
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){

    //Verificador das dimensões
    x0 = ( x0 < 0 ) ? 0:x0;
    x1 = ( x1 > this->nx ) ? this -> nx:x1;
    y0 = ( y0 < 0 ) ? 0:y0;
    y1 = ( y1 > this->ny ) ? this -> ny:y1;
    z0 = ( z0 < 0 ) ? 0:z0;
    z1 = ( z1 > this->nz ) ? this -> nz:z1;

    //Atribuição dos intervalos nos voxels
    for( int i = x0; i < x1; i++){
        for( int j = y0; j < y1; j++){
            for( int k = z0; k < z1; k++){
                this -> putVoxel(i,j,k);
            }
        }
    }
}

//Removendo paralelepípedo
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k < z1 ; k++){
                this -> cutVoxel(i,j,k);
            }
        }
    }
}

//Adicionando esfera
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    putEllipsoid(xcenter, ycenter, zcenter, radius, radius, radius);
}

//Removendo esfere
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    cutEllipsoid(xcenter, ycenter, zcenter, radius, radius, radius);
}

//Adicionando elipsóide
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, rz){

    //Verificador das dimensões
    int xo = (xcenter - rx < 0) ? 0:
}
