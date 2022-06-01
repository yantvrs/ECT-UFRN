//Headers
#include <iomanip>
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
  if(x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz){
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].isOn = true;
    }
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

//Removendo esfera
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){

    float sphere;

    for(int i = 0; i < nx ; i++ ){
        for(int  j = 0; j < ny ; j++ ){
            for(int k = 0; k < nx ; k++ ){
                sphere = ((i-xcenter)*(i-xcenter))+((j-ycenter)*(j-ycenter))+((k-zcenter)*(k-zcenter));
                if(sphere < pow(radius,2)){
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}

//Adicionando elipsóide
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    float elipsoid;
    for(int i = xcenter - rx; i < xcenter + rx; i++){
        for(int j = ycenter - ry; j < ycenter + ry; j++){
            for(int k = zcenter - rz; k < zcenter + rz; k++){
                elipsoid = pow(i - xcenter, 2)/pow(rx,2) + pow(j - ycenter, 2)/pow(ry,2) + pow(k - zcenter,2)/pow(rz,2);
                if(elipsoid < 1){
                    putVoxel(i,j,k);
                }
            }
        }
    }
}

//Removendo elipsóide
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    float elipsoid;
    for(int i = xcenter - rx; i < xcenter + rx; i++){
        for(int j = ycenter - ry; j < ycenter + ry; j++){
            for(int k = zcenter - rz; k < zcenter + rz; k++){
                elipsoid = pow(i - xcenter, 2)/pow(rx,2) + pow(j - ycenter, 2)/pow(ry,2) + pow(k - zcenter,2)/pow(rz,2);
                if(elipsoid < 1){
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}

//Gera um arquivo OFF
void Sculptor::writeOFF(char *file_name_sculptor){
    int vertex, face, edge = 0; //Vértices e faces
    int on_voxel;

    on_voxel=0;

    ofstream fout;//Pesquisar no cpp ofestream

    int p = 0;
    int cont = 0;

    fout.open(file_name_sculptor); //Abertura do arquivo

    if(!fout.is_open()){
        cout << "Falha na criação do arquivo" << "\n" << endl;
        exit(1);
    }

    //Contador de voxels ativos

    for(int k = 0; k < nz; k++){
        for(int i = 0; i < nx; i++ ){
            for(int j = 0; j < ny; j++){
                if(v[i][j][k].isOn == true){
                    on_voxel++;
                }
            }
        }
    }



    vertex = on_voxel*8; //Quantidade de vértices da figura

    face = on_voxel*6; //Quantidade de faces da figura


    //Para fazer a identificação
    fout << "OFF" << endl;

    //Número de faces, vértices e arestas
    fout << vertex << " " << face << " " << edge << endl;

    //Coordenadas espaciais
    for(int k = 0; k < nz; k++){
        for(int i = 0; i < nx; i++ ){
            for(int j = 0; j < ny; j++){
                if(v[i][j][k].isOn == true){
                    fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                    fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                }
            }
        }
    }

    //Faces

    for(int k = 0; k < nz; k++){
        for(int i = 0; i < nx; i++ ){
            for(int j = 0; j < ny; j++){
                if(v[i][j][k].isOn == true){
                    p = 8 * cont;
                    fout << 4 << " " << p + 0 << " " << p + 3 << " " << p + 2 << " " << p + 1 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << 4 << " " << p + 4 << " " << p + 5 << " " << p + 6 << " " << p + 7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << 4 << " " << p + 0 << " " << p + 1 << " " << p + 5 << " " << p + 4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << 4 << " " << p + 0 << " " << p + 4 << " " << p + 7 << " " << p + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << 4 << " " << p + 3 << " " << p + 7 << " " << p + 6 << " " << p + 2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    fout << 4 << " " << p + 1 << " " << p + 2 << " " << p + 6 << " " << p + 5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    cont ++;
                }
            }
        }
    }

fout.close(); //Arquivo fechado

}
