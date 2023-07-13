#include <stdio.h>
#include <stdlib.h>


float *mA;
float *mB;
float *mC;


void mm(int tamMatriz) {
    for (int i = 0; i < tamMatriz; i++) {
        for (int j = 0; j < tamMatriz; j++) {
            for (int k = 0; k < tamMatriz; k++) {
                mC[tamMatriz * i + j] += mA[tamMatriz * i + k] * mB[tamMatriz * k + j];
            }
        }
    }

    return;
}


int main(int argc, char *argv[]) {
    int tamMatriz;

    // tratamento de argumentos por linha de comando
    if (argc != 2) {
        printf("--Uso CLI--\n./a.out tamMatriz\n");

        return 1;
    } else {
        tamMatriz = strtol(argv[1], NULL, 10);
    }

    // alocação de memória
    mA = calloc(tamMatriz * tamMatriz, sizeof(float));
    mB = calloc(tamMatriz * tamMatriz, sizeof(float));
    mC = calloc(tamMatriz * tamMatriz, sizeof(float));

    // preenchimento das matrizes A e B com números aleatórios, C com zeros
    for (int i = 0; i < tamMatriz * tamMatriz; i++) {
        mA[i] = (float)rand() / RAND_MAX;
        mB[i] = (float)rand() / RAND_MAX;
        mC[i] = .0f;
    }

    mm(tamMatriz);

    return 0;
}
