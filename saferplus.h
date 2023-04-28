//
// Created by Alberto Villasante González on 14/4/23.
//

#ifndef IMPLEMENTACION_SAFERPLUS_H
#define IMPLEMENTACION_SAFERPLUS_H

#define KEYSIZE 16
#define NUMROUNDKEYS 17
#define NUMROUNDS 8



unsigned char* A_r(unsigned char** roundKeys, unsigned char* rand); // Function that implements the SAFER+ algorithm
unsigned char** keyScheduling(const unsigned char* k); // Function that implements the key scheduling algorithm

#endif //IMPLEMENTACION_SAFERPLUS_H
