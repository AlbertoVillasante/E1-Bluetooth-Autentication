#include <stdlib.h>
#include <stdio.h>
#include "aux.h"
/*
 * Function that print the 128 bits number in hexadecimal
 * INPUT: the 128 bits number
 * OUTPUT: none
 */
void printHex(unsigned char* number) {
    for (int i = 0; i < RANDOMSIZE; i++) {
        printf("%02x", number[i]);
    }
}
/*
 * Function that print the 128 bits number in decimal
 * INPUT: the 128 bits number
 * OUTPUT: none
 */
void printDec(unsigned char* number) {
    for (int i = 0; i < RANDOMSIZE; i++) {
        printf("%u ", number[i]);
    }
}
/*
 * Function that generates a random number of 128 bits and allocs the memory for it
 * INPUT: none
 * OUTPUT: the 128 bits random number
 */
unsigned char* generateRandom(short randomSize) {
    unsigned char* random = (unsigned char*) malloc(randomSize * sizeof(unsigned char));
    for (int i = 0; i < randomSize; i++) {
        random[i] = (unsigned char) rand();
    }
    return random;
}
