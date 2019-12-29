#pragma once
#ifndef SPLICE_CHUNK
#define SPLICE_CHUNK

#define KB 1024

#define MD_SLICE    0
#define MD_COMB     1

typedef struct chunk{
    int width;      //Actual width
    char * data;    //Payload
    char * id;      //Id for manifest
} chunk;

#endif