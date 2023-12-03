#ifndef BEADANDO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BEADANDO_H_INCLUDED
#define BUFFER_SIZE 1024

typedef struct info
{
    int lin;
    int maxnum;
} info;
void reverse_file(FILE* file, int vanline, int sorhossz);

#endif
