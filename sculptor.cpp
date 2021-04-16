/**
@author Jaysa Barbosa/ Lucas Umbelino
@brief Sculptor 3D
*/

#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

/**
 * Class constructor
 */
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

/**
 * Class destroyer
 */
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

/**
 * Sets the current drawing color
 */
void Sculptor::setColor(float _r, float _g, float _b, float alpha)
{
    r = _r;
    g = _g;
    b = _b;
    a = alpha;
}

/**
 * Disables the voxel at the position (x, y, z) (making isOn = false)
 */
void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = false;
}

/**
 * Activates all voxels in the range x∈ [x0, x1], y∈ [y0, y1], z∈ [z0, z1] and assigns them the current drawing color
 */
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int i = x0; i <= x1; i++)
    {
        for (int j = y0; j <= y1; j++)
        {
            for (int k = z0; k <= z1; k++)
            {
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
                v[i][j][k].isOn = true;
            }
        }
    }
}

/**
 * Disables all voxels in the range x∈ [x0, x1], y∈ [y0, y1], z∈ [z0, z1] and assigns them the current drawing color
 */
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int i = x0; i <= x1; i++)
    {
        for (int j = y0; j <= y1; j++)
        {
            for (int k = z0; k <= z1; k++)
            {
                v[i][j][k].isOn = false;
            }
        }
    }
}

/**
 * Activates all voxels that satisfy the sphere's equation and assigns them the current drawing color (r, g, b, a)
 */
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int dist = 0;
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                dist = (i - xcenter) * (i - xcenter) + (j - ycenter) * (j - ycenter) + (k - zcenter) * (k - zcenter);

                if (dist <= radius * radius)
                {
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                    v[i][j][k].isOn = true;
                }
            }
        }
    }
}

/**
 * Disables all voxels that satisfy the sphere equation
 */
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int dist = 0;
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                dist = (i - xcenter) * (i - xcenter) + (j - ycenter) * (j - ycenter) + (k - zcenter) * (k - zcenter);

                if (dist <= radius * radius)
                {
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
}

/**
 * Activates all voxels that satisfy the ellipsoid equation and assigns them the current drawing color
 */
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int dist = 0;
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                dist = (i - xcenter) * (i - xcenter) / (rx * rx) + (j - ycenter) * (j - ycenter) / (ry * ry) + (k - zcenter) * (k - zcenter) / (rz * rz);

                if (dist <= 1)
                {
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                    v[i][j][k].isOn = true;
                }
            }
        }
    }
}

/**
 * Disables all voxels that satisfy the ellipsoid equation
 */
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int dist = 0;
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                dist = (i - xcenter) * (i - xcenter) / (rx * rx) + (j - ycenter) * (j - ycenter) / (ry * ry) + (k - zcenter) * (k - zcenter) / (rz * rz);

                if (dist <= 1)
                {
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
}

/**
 * save the sculpture in the OFF format in the filename file
 */
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
