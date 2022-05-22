//Headers
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include "sculptor.hpp"
#include <cmath>

using namespace std;

//Função construtora
Sculptor::Sculptor(int _nx, int _ny, int _nz){

    //Dimensões
    nx = _nx;
    ny = _ny;
    nz = _nz;

    //Inicializando cores(Obs:valores de 0 a 1)
    r = 0;
    g = 0;
    b = 0;
    a = 0;

    //Alocando memória
    v = new Voxel**[_nx];

    for(int i = 0; i < _nx; i++){
        v[i] = new Voxel*[_ny];
    }

    for(int i = 0; i < _nx; i++){
        for(int j= 0; j < _ny; j++){
            v[i][j] = new Voxel[_nz];
        }
    }


    for(int i = 0; i < _nx; i++){
        for(int j = 0; j < _ny; j++){
            for(int k = 0; k < _nz; k++){

                v[i][j][k].isOn = false;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = g;

            }
        }
    }

}

//Função destrutora
Sculptor::~Sculptor(){
    for(int i = 0; i < nx; i++){
        for( int j = 0; j < ny; j++){
            delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v ;
    nx = ny = nz = 0;
}

//Cores
void Sculptor::setColor(float color_r, float color_g, float color_b, float alpha){
    r = color_r;
    g = color_g;
    b = color_b;
    a = alpha;
}

//Put voxel
void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].isOn = true;
}

//cut Voxel
void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

//Adicionando paralelepípedo
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){

    //Atribuição dos intervalos nos voxels
    for( int i = x0; i < x1; i++){
        for( int j = y0; j < y1; j++){
            for( int k = z0; k < z1; k++){
                putVoxel(i,j,k);
            }
        }
    }
}

//Removendo paralelepípedo
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k < z1 ; k++){
                cutVoxel(i,j,k);
            }
        }
    }
}

//Adicionando esfera
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){

   float sphere;

   for(int i = 0; i < nx ; i++ ){
       for(int  j = 0; j < ny ; j++ ){
           for(int k = 0; k < nx ; k++ ){
           sphere = ((i-xcenter)*(i-xcenter))+((j-ycenter)*(j-ycenter))+((k-zcenter)*(k-zcenter));
           if(sphere < pow(radius,2)){
               putVoxel(i,j,k);
           }
           }
       }
   }
}

//Removendo esfere
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){

    float sphere;

    for(int i = 0; i < nx ; i++ ){
        for(int  j = 0; j < ny ; j++ ){
            for(int k = 0; k < nx ; k++ ){
            sphere = ((i-xcenter)*(i-xcenter))+((j-ycenter)*(j-ycenter))+((k-zcenter)*(k-zcenter));
            if(sphere< pow(radius,2)){
                cutVoxel(i,j,k);
            }
            }
        }
    }
}

//Adicionando elipsóide
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry,int rz){

    float elips;

    //Verificador das dimensões
    int x0 = (xcenter - rx < 0) ? 0: xcenter - rx;
    int x1 = (xcenter + rx > nx) ? nx : xcenter+rx;
    int y0 = (ycenter - ry < 0) ? 0: ycenter - rx;
    int y1 = (ycenter + ry > ny) ? ny : ycenter+ry;
    int z0 = (zcenter - rz < 0) ? 0: zcenter - rz;
    int z1 = (zcenter + rz > nz) ? nz : zcenter+rz;

    for(int k=z0;k<z1;k++){
       for(int i=x0;i<x1;i++){
         for(int j=y0;j<y1;j++){
           //Fórmula do elipsóide com preenchimento interno
           elips = (((i-xcenter)/rx)*((i-xcenter)/rx))+(((j-ycenter)/ry)*((j-ycenter)/ry))+(((k-zcenter)/rz)*((k-zcenter)/rz));
           //Condições para o preenchimento das elipses
           if(elips < 1){
             putVoxel(i,j,k); //Para construir o elipsóide
           }
         }
       }
     }
}

//Removendo eipsóide

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry,int rz){

    float elips;

    //Verificador das dimensões
    int x0 = (xcenter - rx < 0) ? 0: xcenter - rx;
    int x1 = (xcenter + rx > nx) ? nx : xcenter+rx;
    int y0 = (ycenter - ry < 0) ? 0: ycenter - rx;
    int y1 = (ycenter + ry > ny) ? ny : ycenter+ry;
    int z0 = (zcenter - rz < 0) ? 0: zcenter - rz;
    int z1 = (zcenter + rz > nz) ? nz : zcenter+rz;

    for(int k=z0;k<z1;k++){
       for(int i=x0;i<x1;i++){
         for(int j=y0;j<y1;j++){
           //Fórmula do elipsóide com preenchimento interno
           elips = (((i-xcenter)/rx)*((i-xcenter)/rx))+(((j-ycenter)/ry)*((j-ycenter)/ry))+(((k-zcenter)/rz)*((k-zcenter)/rz));
           //Condições para a remoção das elipses
           if(elips < 1){
             cutVoxel(i,j,k); //Para construir o elipsóide
           }
         }
       }
     }
}

//Gera um arquivo OFF
void Sculptor::writeOFF(char *filename){


}
