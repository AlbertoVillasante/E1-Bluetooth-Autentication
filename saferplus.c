#include "saferplus.h"
#include <stdlib.h>
#include <libc.h>
#include "aux.h"

/* Precomputed values for the 16 biases */
static const unsigned char biases[16][16] = {
        {70,151,177,186,163,183,16,10,197,55,179,201,90,40,172,100},
        {236,171,170,198,103,149,88,13,248,154,246,110,102,220,5,61},
        {138,195,216,137,106,233,54,73,67,191,235,212,150,155,104,160},
        {93,87,146,31,213,113,92,187,34,193,190,123,188,153,99,148},
        {42,97,184,52,50,25,253,251,23,64,230,81,29,65,68,143},
        {221,4,128,222,231,49,214,127,1,162,247,57,218,111,35,202},
        {58,208,28,209,48,62,18,161,205,15,224,168,175,130,89,44},
        {125,173,178,239,194,135,206,117,6,19,2,144,79,46,114,51},
        {192,141,207,169,129,226,196,39,47,108,122,159,82,225,21,56},
        {252,32,66,199,8,228,9,85,94,140,20,118,96,255,223,215},
        {250,11,33,0,26,249,166,185,232,158,98,76,217,145,80,210},
        {24,180,7,132,234,91,164,200,14,203,72,105,75,78,156,53},
        {69,77,84,229,37,60,12,74,139,63,204,167,219,107,174,244},
        {45,243,124,109,157,181,38,116,242,147,83,176,240,17,237,131},
        {182,3,22,115,59,30,142,112,189,134,27,71,126,36,86,241},
        {136,70,151,177,186,163,183,16,10,197,55,179,201,90,40,172}
};
/* Precomputed values for e box: e : i|-> (45^i mod257) mod256 */
static const unsigned char eBox[256] = {
        1,45,226,147,190,69,21,174,120,3,135,164,184,56,207,63,
        8,103,9,148,235,38,168,107,189,24,52,27,187,191,114,247,
        64,53,72,156,81,47,59,85,227,192,159,216,211,243,141,177,
        255,167,62,220,134,119,215,166,17,251,244,186,146,145,100,131,
        241,51,239,218,44,181,178,43,136,209,153,203,140,132,29,20,
        129,151,113,202,95,163,139,87,60,130,196,82,92,28,232,160,
        4,180,133,74,246,19,84,182,223,12,26,142,222,224,57,252,
        32,155,36,78,169,152,158,171,242,96,208,108,234,250,199,217,
        0,212,31,110,67,188,236,83,137,254,122,93,73,201,50,194,
        249,154,248,109,22,219,89,150,68,233,205,230,70,66,143,10,
        193,204,185,101,176,210,198,172,30,65,98,41,46,14,116,80,
        2,90,195,37,123,138,42,91,240,6,13,71,111,112,157,126,
        16,206,18,39,213,76,79,214,121,48,104,54,117,125,228,237,
        128,106,144,55,162,94,118,170,197,127,61,175,165,229,25,97,
        253,77,124,183,11,238,173,75,34,245,231,115,35,33,200,5,
        225,102,221,179,88,105,99,86,15,161,49,149,23,7,58,40
};
/* Precomputed values for l box i |->  j s.t. i = e(j) */
static const unsigned char lBox[256]={
        128,0,176,9,96,239,185,253,16,18,159,228,105,186,173,248,
        192,56,194,101,79,6,148,252,25,222,106,27,93,78,168,130,
        112,237,232,236,114,179,21,195,255,171,182,71,68,1,172,37,
        201,250,142,65,26,33,203,211,13,110,254,38,88,218,50,15,
        32,169,157,132,152,5,156,187,34,140,99,231,197,225,115,198,
        175,36,91,135,102,39,247,87,244,150,177,183,92,139,213,84,
        121,223,170,246,62,163,241,17,202,245,209,23,123,147,131,188,
        189,82,30,235,174,204,214,53,8,200,138,180,226,205,191,217,
        208,80,89,63,77,98,52,10,72,136,181,86,76,46,107,158,
        210,61,60,3,19,251,151,81,117,74,145,113,35,190,118,42,
        95,249,212,85,11,220,55,49,22,116,215,119,167,230,7,219,
        164,47,70,243,97,69,103,227,12,162,59,28,133,24,4,29,
        41,160,143,178,90,216,166,126,238,141,83,75,161,154,193,14,
        122,73,165,44,129,196,199,54,43,127,67,149,51,242,108,104,
        109,240,2,40,206,221,155,234,94,153,124,20,134,207,229,66,
        184,64,120,45,58,233,100,31,146,144,125,57,111,224,137,48
};
/*
 * Function that generates the round keys from the key using key scheduling algorithm
 * INPUT: k - the 128 bits key
 * OUTPUT: the 17 round keys
 */
unsigned char** keyScheduling(const unsigned char* k){
    unsigned char** roundKeys;
    unsigned char* aux; // aux array used to compute the round keys
    /* Allocate memory for the 17 round keys */
    roundKeys = (unsigned char**) malloc(NUMROUNDKEYS * sizeof(unsigned char*));
    for (int i = 0; i < NUMROUNDKEYS; ++i) {
        roundKeys[i] = (unsigned char*) malloc(KEYSIZE * sizeof(unsigned char));
    }
    aux = (unsigned char*) malloc(KEYSIZE * sizeof(unsigned char));
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
 * Function that implements the first mod 256 additions and the xors of the SAFER+ algorithm, modifying the input array
 * INPUT: input - the first 128 bits array, roundKey - the second 128 bits array
 * OUTPUT: the 128 bits result of the addition and xor
 */
void firstAddXor(unsigned char* input, const unsigned char* roundKey) {
    input[0]  = input[0] ^ roundKey[0];
    input[1]  = (input[1] + roundKey[1]) % 256;
    input[2]  = (input[2] + roundKey[2]) % 256;
    input[3]  = input[3] ^ roundKey[3];
    input[4]  = input[4] ^ roundKey[4];
    input[5]  = (input[5] + roundKey[5]) % 256;
    input[6]  = (input[6] + roundKey[6]) % 256;
    input[7]  = input[7] ^ roundKey[7];
    input[8]  = input[8] ^ roundKey[8];
    input[9]  = (input[9] + roundKey[9]) % 256;
    input[10] = (input[10] + roundKey[10]) % 256;
    input[11] = input[11] ^ roundKey[11];
    input[12] = input[12] ^ roundKey[12];
    input[13] = (input[13] + roundKey[13]) % 256;
    input[14] = (input[14] + roundKey[14]) % 256;
    input[15] = input[15] ^ roundKey[15];
}
/*
 * Function that implements the second mod 256 additions and the xors of the SAFER+ algorithm, modifying the input array
 * INPUT: input - the first 128 bits array, roundKey - the second 128 bits array
 * OUTPUT: the 128 bits result of the addition and xor
 */
void secondtAddXor(unsigned char* input, const unsigned char* roundKey) {
    input[0]  = (input[0] + roundKey[0]) % 256;
    input[1]  = input[1] ^ roundKey[1];
    input[2]  = input[2] ^ roundKey[2];
    input[3]  = (input[3] + roundKey[3]) % 256;
    input[4]  = (input[4] + roundKey[4]) % 256;
    input[5]  = input[5] ^ roundKey[5];
    input[6]  = input[6] ^ roundKey[6];
    input[7]  = (input[7] + roundKey[7]) % 256;
    input[8]  = (input[8] + roundKey[8]) % 256;
    input[9]  = input[9] ^ roundKey[9];
    input[10] = input[10] ^ roundKey[10];
    input[11] = (input[11] + roundKey[11]) % 256;
    input[12] = (input[12] + roundKey[12]) % 256;
    input[13] = input[13] ^ roundKey[13];
    input[14] = input[14] ^ roundKey[14];
    input[15] = (input[15] + roundKey[15]) % 256;
}
/*
 * Function that implements the substitution boxes of the SAFER+ algorithm, modifying the input array
 * INPUT: input - the 128 bits array
 * OUTPUT: the 128 bits result of the substitution boxes
 */
void substitutionBoxes(unsigned char* input) {
    input[0] = eBox[input[0]];
    input[1] = lBox[input[1]];
    input[2] = lBox[input[2]];
    input[3] = eBox[input[3]];
    input[4] = eBox[input[4]];
    input[5] = lBox[input[5]];
    input[6] = lBox[input[6]];
    input[7] = eBox[input[7]];
    input[8] = eBox[input[8]];
    input[9] = lBox[input[9]];
    input[10] = lBox[input[10]];
    input[11] = eBox[input[11]];
    input[12] = eBox[input[12]];
    input[13] = lBox[input[13]];
    input[14] = lBox[input[14]];
    input[15] = eBox[input[15]];
}
/*
 * Function that implements the Pseudo-Hadamard Transform of the SAFER+ algorithm, modifying the input array
 * INPUT: input - the 128 bits array
 * OUTPUT: the 128 bits result of the Pseudo-Hadamard Transform
 */
void PHT(unsigned char* input){
    unsigned char a, b;
    for (int i = 0; i < KEYSIZE; i+=2) {
        a = input[i];
        b = input[i + 1];
        input[i] = ((a << 1) + b) % 256;   // a' = 2a + b (mod 2^n)
        input[i + 1] = (a + b) % 256;      // b' = a + b (mod 2^n)
    }
}
/*
 * Function that implements the Armenian Shuffle of the SAFER+ algorithm
 * INPUT: input - the 128 bits array
 * OUTPUT: the 128 bits result of the Armenian Shuffle
 */
void armenianShuffle(unsigned char* input) {
    unsigned char temp[16]; // temporary array
    temp[0] = input[8];
    temp[1] = input[11];
    temp[2] = input[12];
    temp[3] = input[15];
    temp[4] = input[2];
    temp[5] = input[1];
    temp[6] = input[6];
    temp[7] = input[5];
    temp[8] = input[10];
    temp[9] = input[9];
    temp[10] = input[14];
    temp[11] = input[13];
    temp[12] = input[0];
    temp[13] = input[7];
    temp[14] = input[4];
    temp[15] = input[3];
    memcpy(input, temp, sizeof(temp)); // copy the temporary array into the input array
}
/*
 * Function that implements the SAFER+ algorithm for the E1 authentication function of Bluetooth
 * INPUT: k - the 128 bits key, input - the random number of 128 bits, isArPrime - 1 if the function is Ar prime, 0 otherwise
 * OUTPUT: the 128 bits result of the function
 */
unsigned char* A_r(unsigned char** roundKeys, unsigned char* input, short isArPrime){
    unsigned char* result;
    unsigned char* roundKey;
    unsigned char* nextRoundKey;

    if(isArPrime) {
        printf("\n\nA_r prime metiendo modificada la entrada para el test xd");
        // 21, 143, 254, 67, 53, 32, 133, 232, 165, 236, 122, 136, 225, 255, 43, 168
        input[0] = 21;
        input[1] = 143;
        input[2] = 254;
        input[3] = 67;
        input[4] = 53;
        input[5] = 32;
        input[6] = 133;
        input[7] = 232;
        input[8] = 165;
        input[9] = 236;
        input[10] = 122;
        input[11] = 136;
        input[12] = 225;
        input[13] = 255;
        input[14] = 43;
        input[15] = 168;
    }

    /* Allocate memory for the result (at first is the input) */
    result = (unsigned char *) malloc(KEYSIZE * sizeof(unsigned char));
    memcpy(result, input, KEYSIZE);


    /* Apply the 8 rounds of the SAFER+ algorithm */
    printf("\n -------------------------- \n");
    for(int r=0; r < NUMROUNDS; r++){
        printf("\nRound %d", r+1);
        printf("\nInput: ");
        printHex(result);
        /* Add and xor the third input with the input if it is Ar prime */
        if(r == 2 && isArPrime){
            printf("\nResult aaaaa: ");
            printDec(result);
            printf("\nInput aaaaaa: ");
            printDec(input);
            firstAddXor(result, input);
        }
        /* Select the round keys */
        roundKey = roundKeys[2*r-1 + 1];
        nextRoundKey = roundKeys[2*r + 1];
        /* First layer of mod 256 additions and xors */
        firstAddXor(result, roundKey);
        /* Substitution layer */
        substitutionBoxes(result);
        /* Second layer of mod 256 additions and xors */
        secondtAddXor(result, nextRoundKey);


        /* Pseudo-Hadamard Transform */
        PHT(result);
        /* Armenian Shuffle */
        armenianShuffle(result);
        /* Pseudo-Hadamard Transform */
        PHT(result);
        /* Armenian Shuffle */
        armenianShuffle(result);
        /* Pseudo-Hadamard Transform */
        PHT(result);
        /* Armenian Shuffle */
        armenianShuffle(result);
        /* Pseudo-Hadamard Transform */
        PHT(result);
    }
    roundKey = roundKeys[NUMROUNDKEYS - 1];
    firstAddXor(result, roundKey);
    return result;
}