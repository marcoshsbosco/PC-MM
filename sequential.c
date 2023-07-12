#include <stdio.h>
#include <stdlib.h>


int n;

float *mA;
float *mB;
float *mR;


void *MM() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                mR[n * i + j] += mA[n * i + k] * mB[n * k + j];
            }
        }
    }
    return NULL;
}


int main(int argc, char *argv[]) {
     if (argc != 2) {
         printf("--Uso CLI--\n./a.out {tamMatriz}\n");

         return 1;
     } else {
        n = strtol(argv[1], NULL, 10);
    }

    // alocação de memória
    mA = calloc(n * n, sizeof(float));
    mB = calloc(n * n, sizeof(float));
    mR = calloc(n * n, sizeof(float));

    if (mA == NULL || mB == NULL || mR == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    for (int i = 0; i < n * n; i++) {
        mA[i] = (float)rand() / RAND_MAX;
        mB[i] = (float)rand() / RAND_MAX;
        mR[i] = 0;
    }

    MM();

    // print matriz C
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", mR[n * i + j]);
        }

        printf("\n");
    }

    free(mA);
    free(mB);
    free(mR);

    return 0;
}
