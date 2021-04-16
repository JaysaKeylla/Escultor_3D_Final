#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <iostream>
#include <fstream>

using namespace std;

struct Voxel {
  float r,g,b; // Colors
  float a;
// Transparency
  bool isOn; // Included or not
};

class Sculptor
{
protected:
  Voxel ***v;
  // 3D matrix
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color
public:
    int getDimX();
    int getDimY();
    int getDimZ();

    Sculptor(int _nx, int _ny, int _nz);
    ~Sculptor();
    void setColor(float _r, float _g, float _b, float alpha);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void writeOFF(char* filename);

};
#endif // SCULPTOR_H
