#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "e1.h"
#include "saferplus.h"
#include "aux.h"
#define ITER 1
int main() {
    unsigned char *random;
    unsigned char *key;
    unsigned char *btAddr;
    unsigned char *result;
    //struct timeval inicio, final;
    //double total;
/*  Initialize variables to 0 for correction tests (not needed for performance tests)
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
*/
    //gettimeofday(&inicio,NULL);
    for (int i = 0; i < ITER; ++i) {
        random = generateRandom(RANDOMSIZE);
        key = generateRandom(KEYSIZE);
        btAddr = generateRandom(BTADDRSIZE);
        result = e1(key, random, btAddr);
        printHex(result);
        printf("\n");
        free(result);
    }
    //gettimeofday(&final,NULL);
    /*total = (final.tv_sec-inicio.tv_sec+(final.tv_usec-inicio.tv_usec)/1.e6);
    printf("\n media -> %lf", total/ITER);
    printf("\n total -> %lf \n", total);
    printf("\n ejecuciones -> %d \n", ITER);
    // Calculamos los hashes por segundo
    double hashes_per_second = ITER / total;
    double mega_hashes_per_second = hashes_per_second / 1e6;
    printf("\n Hashes por segundo -> %lf", hashes_per_second);
    printf("\n Mega Hashes por segundo -> %lf \n", mega_hashes_per_second);
    */

    return 0;
}
