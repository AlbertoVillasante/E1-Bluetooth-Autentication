#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "e1.h"
#include "saferplus.h"
#include "aux.h"

int main() {
    unsigned char *random;
    unsigned char *key;
    unsigned char *btAddr;

    srand(1);
    random = generateRandom(RANDOM_SIZE);
    printHex(random);
    printf("\n");
    srand(4);
    key = generateRandom(KEYSIZE);
    printHex(key);
    btAddr = generateRandom(BTADDRSIZE);
    key = "000000000000000000000000686F6C61";
    random = "000000000000000000000000686F6C61";

    e1(key, random);




    //free(random);
    //free(key);





    return 0;
}
