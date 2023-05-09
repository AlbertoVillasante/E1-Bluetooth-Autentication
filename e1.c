#include <stdlib.h>
#include <stdio.h>
#include "e1.h"
#include "aux.h"
#include "saferplus.h"

/*
 * Function that generates the round keys for the Ar' algorithm from the original key
 * INPUT: key: 128-bit original key
 * OUTPUT: the new round keys
 */
unsigned char** keysOffset(unsigned char* key){
    unsigned char** newRoundKeys;
    /* Key offset */
    key[0] = (key[0] + 233) % 256;  key[1] = key[1] ^ 229;
    key[2] = (key[2] + 223) % 256;  key[3] = key[3] ^ 193;
    key[4] = (key[4] + 179) % 256;  key[5] = key[5] ^ 167;
    key[6] = (key[6] + 149) % 256;  key[7] = key[7] ^ 131;
    key[8] = key[8] ^ 233;          key[9] = (key[9] + 229) % 256;
    key[10] = key[10] ^ 223;        key[11] = (key[11] + 193) % 256;
    key[12] = key[12] ^ 179;        key[13] = (key[13] + 167) % 256;
    key[14] = key[14] ^ 149;        key[15] = (key[15] + 131) % 256;
    /* Key scheduling from the new key*/
    newRoundKeys = keyScheduling(key);
    return newRoundKeys;
}
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
    newRoundKeys = keysOffset(k);
    /* Execute A_r */
    result = A_r(roundKeys, rand, 0);
    /* XOR the result with the random */
    xor(result, rand);
    /* Expand the Bluetooth address */
    expandBtAddr(btAddr);
    /* Add (modulo 256) the result with the Bluetooth address */
    add(result, btAddr);
    /* Execute A_r_prime*/
    result = A_r(newRoundKeys, rand, 1);











    printf("\nSRES_ACO:");
    printf("\n");
    printHex(result);
    printf("\n");
    printDec(result);
    return result;
}