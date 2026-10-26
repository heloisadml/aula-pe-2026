#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Faça um programa que converta coordenadas polares para cartesianas:
// - Crie e leia um ponto em coordenada polar (struct), composto por raio (r) e argumento (a) em radianos.
// - Crie outro ponto (struct), agora em coordenada cartesiana, composto por x e y, sabendo que x = r ∗ cos(a) e y = r ∗ sin(a).

struct PontoPolar {
    double r;
    double a;
};

struct PontoCartesiano {
    double x;
    double y;
};

int main() {
    srand(time(NULL));

    struct PontoPolar polar;
    struct PontoCartesiano cartesiano;

    polar.r = ((double)rand() / RAND_MAX) * 50.0; // raio entre 0 e 50

    polar.a = ((double)rand() / RAND_MAX) * (M_PI / 2.0); // rad entre 0 e pi/2

    cartesiano.x = polar.r * cos(polar.a);
    cartesiano.y = polar.r * sin(polar.a);

    printf("CONVERSAO DE POLAR PARA CARTESIANO \n");
    printf("COORDENADAS POLAR: Raio (r): %.2f | Argumento (a): %.2f rad\n", polar.r, polar.a);
    printf("COORDENADAS CARTESIANAS:  X: %.2f |             Y: %.2f\n", cartesiano.x, cartesiano.y);

    return 0;
}