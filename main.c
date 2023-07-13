#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


struct ThreadArgs {
    int nfluxos;
    int nmatriz;
    int tnum;
};

float *mA;
float *mB;
float *mC;


void *worker(void *arg) {
    struct ThreadArgs args = *(struct ThreadArgs *)arg;

    for (int i = args.tnum * args.nmatriz / args.nfluxos; i < (args.nmatriz + args.nmatriz * args.tnum) / args.nfluxos; i++) {
        for (int j = 0; j < args.nmatriz; j++) {
            for (int k = 0; k < args.nmatriz; k++) {
                mC[args.nmatriz * i + j] += mA[args.nmatriz * i + k] * mB[args.nmatriz * k + j];
            }
        }
    }

    return NULL;
}


int main(int argc, char *argv[]) {
    pthread_t *tid;
    struct ThreadArgs *args;
    int nmatriz, nfluxos;

    if (argc != 3) {
        printf("--Uso CLI--\n./a.out nfluxos nmatriz\n");

        return 1;
    } else {
        nfluxos = strtol(argv[1], NULL, 10);
        nmatriz = strtol(argv[2], NULL, 10);
    }

    // alocação de memória
    tid = calloc(nfluxos, sizeof(pthread_t));
    args = calloc(nfluxos, sizeof(struct ThreadArgs));
    mA = calloc(nmatriz * nmatriz, sizeof(float));
    mB = calloc(nmatriz * nmatriz, sizeof(float));
    mC = calloc(nmatriz * nmatriz, sizeof(float));

    for (int i = 0; i < nmatriz * nmatriz; i++) {
        mA[i] = (float)rand() / RAND_MAX;
        mB[i] = (float)rand() / RAND_MAX;
        mC[i] = .0f;
    }

    // criação de fluxos e de seus atributos (ID e número)
    for (int i = 0; i < nfluxos; i++) {
        args[i].tnum = i;
        args[i].nmatriz = nmatriz;
        args[i].nfluxos = nfluxos;

        pthread_create(&tid[i], NULL, &worker, &args[i]);
    }

    // join
    for (int i = 0; i < nfluxos; i++) {
        pthread_join(tid[i], NULL);
    }

    return 0;
}
