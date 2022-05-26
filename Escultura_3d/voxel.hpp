#ifndef VOXEL_H
#define VOXEL_H

struct Voxel{
    float r, g, b; //Red, green e blue
    float a; //Transparência da cor para o voxel
    bool isOn; //True or false(inclusão ou não do voxel)
};

#endif // VOXEL_HPP
