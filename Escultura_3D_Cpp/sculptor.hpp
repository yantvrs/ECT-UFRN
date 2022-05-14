#ifndef SCULPTOR_HPP
#define SCULPTOR_HPP
#include "voxel.hpp"

class Sculptor{

protected:
    Voxel ***vox; //Matriz 3d
    int nx, ny, nz; //Dimensões da matriz
    float r, g, b, a; //Manipulação de cores

public:
    Sculptor(int _nx, int _ny, int _nz); //Construtor
    ~Sculptor(); //Destrutor
    void setColor(float r, float g, float b, float alpha); //Cores
    void putVoxel(int x, int y, int z); //Adiciona voxel nas posições especificadas
    void cutVoxel(int x, int y, int z); //Remove voxel nas posições especificadas
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1); //Adiciona paralelepípedo
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1); //Remove paralelepípedo
    void putSphere(int xcenter, int ycenter, int zcenter, int radius); //Adiciona esfera
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius); //Remove esfera
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); //Adiciona elipsóide
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); //Remove elipsóide
    void writeOFF(char* filename); //Arquivo .off
};

#endif // SCULPTOR_HPP
