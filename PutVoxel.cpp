#include "PutVoxel.h"
#include <iostream>

PutVoxel::PutVoxel()
{
    //ctor
}

void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].isOn = true;
}
void PutVoxel::draw(){
    std:: cout << "draw PutVoxel\n";
}
