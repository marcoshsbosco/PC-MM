#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int nfluxos;
int n;

float *mA;
float *mB;
float *mC;


void *worker(void *arg) {
    int tnum = *(int *)arg;

    for (int i = tnum * n / nfluxos; i < (n + n * tnum) / nfluxos; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                mC[n * i + j] += mA[n * i + k] * mB[n * k + j];
            }
        }
    }

    return NULL;
}


int main(int argc, char *argv[]) {
    pthread_t *tid;
    int *tnum;

    if (argc != 3) {
        printf("--Uso CLI--\n./a.out nfluxos nmatriz\n");

        return 1;
    } else {
        nfluxos = strtol(argv[1], NULL, 10);
        n = strtol(argv[2], NULL, 10);
    }

    // alocação de memória
    tid = calloc(nfluxos, sizeof(pthread_t));
    tnum = calloc(nfluxos, sizeof(int));
    mA = calloc(n * n, sizeof(float));
    mB = calloc(n * n, sizeof(float));
    mC = calloc(n * n, sizeof(float));

    for (int i = 0; i < n * n; i++) {
        mA[i] = (float)i;
        mB[i] = (float)i;
        mC[i] = .0f;
    }

    // criação de fluxos e de seus atributos (ID e número)
    for (int i = 0; i < nfluxos; i++) {
        tnum[i] = i;
        pthread_create(&tid[i], NULL, &worker, &tnum[i]);
    }

    // join
    for (int i = 0; i < nfluxos; i++) {
        pthread_join(tid[i], NULL);
    }

    // print matriz C
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f ", mC[n * i + j]);
        }

        printf("\n");
    }

    return 0;
}
