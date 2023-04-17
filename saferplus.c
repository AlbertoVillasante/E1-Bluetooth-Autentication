#include "saferplus.h"
#include <stdlib.h>


/* Precomputed values for the 16 biases */
static const unsigned char biases[16][16] = {
        {70, 151, 177, 186, 163, 183, 16, 10, 197, 55, 179, 201, 90, 40, 172, 100},
        {236, 171, 170, 198, 103, 149, 88, 13, 248, 154, 246, 110, 102, 220, 5, 61},
        {138, 195, 216, 137, 106, 233, 54, 73, 67, 191, 235, 212, 150, 155, 104, 160},
        {93, 87, 146, 31, 213, 113, 92, 187, 34, 193, 190, 123, 188, 153, 99, 148},
        {42, 97, 184, 52, 50, 25, 253, 251, 23, 64, 230, 81, 29, 65, 68, 143},
        {221, 4, 128, 222, 231, 49, 214, 127, 1, 162, 247, 57, 218, 111, 35, 202},
        {58, 208, 28, 209, 48, 62, 18, 161, 205, 15, 224, 168, 175, 130, 89, 44},
        {125, 173, 178, 239, 194, 135, 206, 117, 6, 19, 2, 144, 79, 46, 114, 51},
        {192, 141, 207, 169, 129, 226, 196, 39, 47, 108, 122, 159, 82, 225, 21, 56},
        {252, 32, 66, 199, 8, 228, 9, 85, 94, 140, 20, 118, 96, 255, 223, 215},
        {250, 11, 33, 0, 26, 249, 166, 185, 232, 158, 98, 76, 217, 145, 80, 210},
        {24, 180, 7, 132, 234, 91, 164, 200, 14, 203, 72, 105, 75, 78, 156, 53},
        {69, 77, 84, 229, 37, 60, 12, 74, 139, 63, 204, 167, 219, 107, 174, 244},
        {45, 243, 124, 109, 157, 181, 38, 116, 242, 147, 83, 176, 240, 17, 237, 131},
        {182, 3, 22, 115, 59, 30, 142, 112, 189, 134, 27, 71, 126, 36, 86, 241},
        {136, 70, 151, 177, 186, 163, 183, 16, 10, 197, 55, 179, 201, 90, 40, 172}
};



/*
 * Function that generates the round keys from the key using key scheduling algorithm
 * INPUT: k - the 128 bits key
 * OUTPUT: the 17 round keys
 */
unsigned char** keyScheduling(unsigned char* k){
    unsigned char** roundKeys;
    unsigned char* aux; // aux array used to compute the round keys
    /* Allocate memory for the 17 round keys */
    roundKeys = (unsigned char**) malloc(NUMROUNDKEYS * sizeof(unsigned char*));
    for (int i = 0; i < NUMROUNDKEYS; ++i) {
        roundKeys[i] = (unsigned char*) malloc(NUMROUNDKEYS * sizeof(unsigned char));
    }
    /* Deep copy the key into the 0 round key and calculate the acumulative xor to insert into the aux array*/
    for (int i = 0; i < KEYSIZE; i++){
        roundKeys[0][i] = k[i];
        aux[i] = k[i];
        aux[KEYSIZE] ^= k[i]; // Calculate the acumulative xor of the key
    }
    /* Generate the 16 round keys */
    for (int i = 1; i < NUMROUNDKEYS; ++i) {
        /* Rotate each byte 3 bits left */
        for (int j = 0; j < NUMROUNDKEYS; ++j) {
            aux[j] = (aux[j] << 3) | (aux[j] >> 5);
        }
        /* Select the 16 bytes of the rotated and circularly shifted array and add the corresponding bias array */
        for (int j = 0; j < NUMROUNDKEYS; ++j) {
            roundKeys[i][j] = (aux[(i+j)%NUMROUNDKEYS] + biases[i-1][j]) & 255; // aux is circularly shifted by i positions and then the bias is added
        }
    }

    return roundKeys;
}



/*
 * Function that implements the SAFER+ algorithm for the E1 authentication function of Bluetooth
 * INPUT: k - the 128 bits key, rand - the random number of 128 bits
 * OUTPUT: the 128 bits result of the function
 */
unsigned char* A_r(unsigned char* k, unsigned char* rand){
    unsigned char* result;
    //result = (char*) malloc(16 * sizeof(char));
}