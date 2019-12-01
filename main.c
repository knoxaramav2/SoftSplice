#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KB 1024

#define MD_SLICE    0
#define MD_COMB     1

typedef struct chunk{
    int width;      //Actual width
    char * data;    //Payload
    char * id;      //Id for manifest
} chunk;

typedef struct config{
    int segWidth;   //Max width to read for reach chunk (bytes)
    int mode;       //Divide=0, Combine!=0
    int divSlice;   //Slice by fraction if = 1

} config;

//Read partial data from stream and create output info
chunk * makeChunk(int width, char ** stream){
    chunk * c = NULL;
}

//Build default config structure
config * defConfig(){
    config * conf = malloc(sizeof(config));

    conf->mode=MD_SLICE;
    conf->segWidth=KB*100000;//Default at 100 MB

    return conf;
}

config * parseCmd(int argc, char ** argv){

    printf("Software Splicer Tool\r\nWoodrow Scott\r\n");

    config * conf = defConfig(argc, argv);

    //Combine/Divide mode select
    if (conf->mode==MD_SLICE){

    } else {

    }

    return conf;
}

int main(int argc, char**argv){
    
    config * conf = parseCmd(argc, argv);


    free(conf);

    return 0;
}