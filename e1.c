#include <stdlib.h>
#include <stdio.h>
#include "e1.h"
#include "aux.h"
#include "saferplus.h"

/*
 * Function that do xor operation between two 128-bit numbers
 * INPUT: a: 128-bit number, b: 128-bit number
 * OUTPUT: 128-bit result modifying a
 */
void xor(unsigned char* a, const unsigned char* b){
    for(int i = 0; i < KEYSIZE; i++){
        a[i] = a[i] ^ b[i];
    }
}
/*
 * Function that expands the Bluetooth address to 128 bits
 * INPUT: btAddr: 48-bit Bluetooth address
 * OUTPUT: 128-bit result modifying btAddr
 */
void expandBtAddr(unsigned char* btAddr){
    btAddr = (unsigned char*) realloc(btAddr, KEYSIZE * sizeof(unsigned char));
    for (int i = 0; i < KEYSIZE; i++) {
        btAddr[i] = btAddr[i % BTADDRSIZE];
    }
}
/*
 * Function that adds (modulo 256) two 128-bit numbers
 * INPUT: a: 128-bit number, b: 128-bit number
 * OUTPUT: 128-bit result modifying a
 */
void add(unsigned char* a, const unsigned char* b){
    for(int i = 0; i < KEYSIZE; i++){
        a[i] = (a[i] + b[i]) % 256;
    }
}
/*
 * Main function of the E1 algorithm
 * INPUT: k: 128-bit key, rand: 128-bit random number
 * OUTPUT: 128-bit result
 */
unsigned char* e1(unsigned char* k, unsigned char* rand, unsigned char *btAddr){
    unsigned char* result;
    unsigned char** roundKeys;
    unsigned char** newRoundKeys;
    /* Generate de round keys */
    roundKeys = keyScheduling(k);
    newRoundKeys = kTilda(roundKeys);
    /* Execute A_r */
    result = A_r(roundKeys, rand);
    /* XOR the result with the random */
    xor(result, rand);
    /* Expand the Bluetooth address */
    expandBtAddr(btAddr);
    /* Add (modulo 256) the result with the Bluetooth address */
    add(result, btAddr);
    result = A_r(newRoundKeys, rand);











    printf("\nSRES_ACO:");
    printf("\n");
    printHex(result);
    printf("\n");
    printDec(result);
    return result;
}