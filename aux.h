#ifndef IMPLEMENTACION_AUX_H
#define IMPLEMENTACION_AUX_H

#define RANDOM_SIZE 16


unsigned char* generateRandom(short randomSize); // Function that generates a random number of 128 bits and allocs the memory for it
void printHex(unsigned char* number);            // Function that print the 128 bits number in hexadecimal
void printDec(unsigned char* number);            // Function that print the 128 bits number in decimal
#endif //IMPLEMENTACION_AUX_H
