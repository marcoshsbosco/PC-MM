#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


struct ArgsFluxo {  // encapsula argumentos para cada fluxo
    int fluxos;
    int tamMatriz;
    int fluxoAtual;
};

float *mA;
float *mB;
float *mC;


void *mm(void *arg) {
    struct ArgsFluxo args = *(struct ArgsFluxo *)arg;

    for (int i = args.fluxoAtual * args.tamMatriz / args.fluxos; i < (args.tamMatriz + args.tamMatriz * args.fluxoAtual) / args.fluxos; i++) {
        for (int j = 0; j < args.tamMatriz; j++) {
            for (int k = 0; k < args.tamMatriz; k++) {
                mC[args.tamMatriz * i + j] += mA[args.tamMatriz * i + k] * mB[args.tamMatriz * k + j];
            }
        }
    }

    return NULL;
}


int main(int argc, char *argv[]) {
    pthread_t *idsFluxo;
    struct ArgsFluxo *args;
    int tamMatriz, fluxos;

    // tratamento de argumentos por linha de comando
    if (argc != 3) {
        printf("--Uso CLI--\n./a.out fluxos tamMatriz\n");

        return 1;
    } else {
        fluxos = strtol(argv[1], NULL, 10);
        tamMatriz = strtol(argv[2], NULL, 10);
    }

    // alocação de memória
    idsFluxo = calloc(fluxos, sizeof(pthread_t));
    args = calloc(fluxos, sizeof(struct ArgsFluxo));
    mA = calloc(tamMatriz * tamMatriz, sizeof(float));
    mB = calloc(tamMatriz * tamMatriz, sizeof(float));
    mC = calloc(tamMatriz * tamMatriz, sizeof(float));

    // preenchimento das matrizes A e B com números aleatórios, C com zeros
    for (int i = 0; i < tamMatriz * tamMatriz; i++) {
        mA[i] = (float)rand() / RAND_MAX;
        mB[i] = (float)rand() / RAND_MAX;
        mC[i] = .0f;
    }

    // criação de fluxos e de seus atributos (ID e número)
    for (int i = 0; i < fluxos; i++) {
        args[i].fluxoAtual = i;
        args[i].tamMatriz = tamMatriz;
        args[i].fluxos = fluxos;

        pthread_create(&idsFluxo[i], NULL, &mm, &args[i]);
    }

    // join
    for (int i = 0; i < fluxos; i++) {
        pthread_join(idsFluxo[i], NULL);
    }

    return 0;
}
