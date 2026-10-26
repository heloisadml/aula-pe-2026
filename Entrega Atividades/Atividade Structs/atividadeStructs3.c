#include <stdio.h>

struct Vetor{
    double x;
    double y;
    double z;
};

struct Vetor somaVetores(struct Vetor v1, struct Vetor v2) {
    struct Vetor resultado;
    resultado.x = v1.x + v2.x;
    resultado.y = v1.y + v2.y;
    resultado.z = v1.z + v2.z;
    return resultado;
}

int main() {
    struct Vetor v1 = {10, 20, 30};
    struct Vetor v2 = {5, 8, 10};

    struct Vetor resultado = somaVetores(v1, v2);

    printf("Vetor Soma: (%.1f, %.1f, %.1f)\n", resultado.x, resultado.y, resultado.z);

    return 0;
}