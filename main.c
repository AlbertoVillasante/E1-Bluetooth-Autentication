#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "e1.h"
#include "saferplus.h"
#include "aux.h"
#define ITER 1000
int main() {
    unsigned char *random;
    unsigned char *key;
    unsigned char *btAddr;

    struct timeval inicio, final;
    double tiempo, total, min, max;


    srand(1);
    random = generateRandom(RANDOMSIZE);
    //printHex(random);
    //printf("\n");
    srand(4);
    key = generateRandom(KEYSIZE);
    //printHex(key);
    btAddr = generateRandom(BTADDRSIZE);

    for (int i = 0; i < RANDOMSIZE; i++) {
        random[i] = 0;
    }

    // Inicializar addr
    for (int i = 0; i < BTADDRSIZE; i++) {
        btAddr[i] = 0;
    }

    // Inicializar key
    for (int i = 0; i < KEYSIZE; i++) {
        key[i] = 0;
    }
    gettimeofday(&inicio,NULL);
    for (int i = 0; i < ITER; ++i) {
        e1(key, random, btAddr);
    }
    gettimeofday(&final,NULL);
    total = (final.tv_sec-inicio.tv_sec+(final.tv_usec-inicio.tv_usec)/1.e6);
    printf("\n media -> %lf", total/ITER);
    printf("\n total -> %lf \n", total);




    //free(random);
    //free(key);





    return 0;
}
