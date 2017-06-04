#ifndef INC_IOFUNC
#define INC_IOFUNC

#include <stdio.h>
#include <stdlib.h>
#include "definitions.hpp"

float parseFloat(FILE*,int*);
Star *loadGalaxy(char*,int*,int*);
FILE *initStorage(char*,int,int);
void storeGalaxy(FILE*,Star*,int);

#endif
