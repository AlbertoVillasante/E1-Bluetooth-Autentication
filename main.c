#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "saferplus.h"
#include "aux.h"

int main() {
    unsigned char *random;
    srand(10);
    random = generateRandom();

    free(random);






    return 0;
}
