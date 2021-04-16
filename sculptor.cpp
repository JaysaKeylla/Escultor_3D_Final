#include "sculptor.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <iomanip>

int Sculptor::getDimX(){
    return nx;
}

int Sculptor::getDimY(){
    return ny;
}

int Sculptor::getDimZ(){
    return nz;
}

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;

    if (nx <= 0 || ny <= 0 || nz <= 0)
    {
        nx = ny = nz = 0;
    }

    v = new Voxel **[nx];

    for (int i = 0; i < nx; i++)
    {
        v[i] = new Voxel *[ny];
        for (int j = 0; j < ny; j++)
        {
            v[i][j] = new Voxel[nz];
        }
    }

    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                v[i][j][k].r = 0;
                v[i][j][k].g = 0;
                v[i][j][k].b = 0;
                v[i][j][k].a = 0;
                v[i][j][k].isOn = false;
            }
        }
    }
}

Sculptor::~Sculptor()
{
    std::cout << "Objeto destruido\n";

    if (nx == 0 || ny == 0 || nz == 0)
    {
        return;
    }

    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;
}

void Sculptor::putVoxel(int x, int y, int z){

    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

void Sculptor::setColor(float _r, float _g, float _b, float alpha){
    r = _r;
    g = _g;
    b = _b;
    a = alpha;
}

void Sculptor::writeOFF(char *filename)
{
    std::ofstream f;
    int cont = 0;
    f.open(filename);

    if (f.is_open())
    {
        std::cout << "Arquivo aberto\n";
    }
    else
    {
        std::cout << "Falha para abrir o arquivo\n";
        exit(1);
    }

    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                if (v[i][j][k].isOn)
                {
                    cont++;
                }
            }
        }
    }

    f << "OFF\n";
    f << cont * 8 << " " << cont * 6 << " " << 0 << "\n";

    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                if (v[i][j][k].isOn)
                {
                    f << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
                    f << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
                    f << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
                    f << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
                    f << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
                    f << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n";
                    f << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n";
                    f << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
                }
            }
        }
    }

    cont = 0;
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                if (v[i][j][k].isOn)
                {
                    f << std::fixed;
                    f << 4 << " " << cont * 8 + 0 << " " << cont * 8 + 3 << " " << cont * 8 + 2 << " " << cont * 8 + 1 << " " << std::setprecision(2) << v[i][j][k].r << " " << std::setprecision(2) << v[i][j][k].g << " " << std::setprecision(2) << v[i][j][k].b << " " << std::setprecision(2) << v[i][j][k].a << "\n";
                    f << 4 << " " << cont * 8 + 4 << " " << cont * 8 + 5 << " " << cont * 8 + 6 << " " << cont * 8 + 7 << " " << std::setprecision(2) << v[i][j][k].r << " " << std::setprecision(2) << v[i][j][k].g << " " << std::setprecision(2) << v[i][j][k].b << " " << std::setprecision(2) << v[i][j][k].a << "\n";
                    f << 4 << " " << cont * 8 + 0 << " " << cont * 8 + 1 << " " << cont * 8 + 5 << " " << cont * 8 + 4 << " " << std::setprecision(2) << v[i][j][k].r << " " << std::setprecision(2) << v[i][j][k].g << " " << std::setprecision(2) << v[i][j][k].b << " " << std::setprecision(2) << v[i][j][k].a << "\n";
                    f << 4 << " " << cont * 8 + 0 << " " << cont * 8 + 4 << " " << cont * 8 + 7 << " " << cont * 8 + 3 << " " << std::setprecision(2) << v[i][j][k].r << " " << std::setprecision(2) << v[i][j][k].g << " " << std::setprecision(2) << v[i][j][k].b << " " << std::setprecision(2) << v[i][j][k].a << "\n";
                    f << 4 << " " << cont * 8 + 3 << " " << cont * 8 + 7 << " " << cont * 8 + 6 << " " << cont * 8 + 2 << " " << std::setprecision(2) << v[i][j][k].r << " " << std::setprecision(2) << v[i][j][k].g << " " << std::setprecision(2) << v[i][j][k].b << " " << std::setprecision(2) << v[i][j][k].a << "\n";
                    f << 4 << " " << cont * 8 + 1 << " " << cont * 8 + 2 << " " << cont * 8 + 6 << " " << cont * 8 + 5 << " " << std::setprecision(2) << v[i][j][k].r << " " << std::setprecision(2) << v[i][j][k].g << " " << std::setprecision(2) << v[i][j][k].b << " " << std::setprecision(2) << v[i][j][k].a << "\n";

                    cont++;
                }
            }
        }
    }

    f.close();
}
