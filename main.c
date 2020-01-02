#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "chunk.h"

#define VERSION 0.1

typedef struct config{
    int segWidth;   //Max width to read for reach chunk (bytes)
    int mode;       //Divide=0, Combine!=0
    int divSlice;   //Slice by fraction if = 1

    char ** inputList;
    int inputSize;

} config;

void addFile(config*c, char * target){
    if (c->inputSize == 0){
        c->inputList = malloc(sizeof(char*) * 5);
    }

    c->inputList[c->inputSize] = malloc(255);

    strncpy(c->inputList[c->inputSize], target, strlen(target)+1);
    printf("Added %s\r\n", c->inputList[c->inputSize]);
    ++c->inputSize;

    if (c->inputSize%5==0){
        c->inputList=realloc(c->inputList, sizeof(char*) * (c->inputSize+5));
    }
}

//Read partial data from stream and create output info
chunk * makeChunk(int width, char ** stream){
    //chunk * c = NULL;


    return 0;
}

//Build default config structure
config * defConfig(){
    config * conf = malloc(sizeof(config));

    conf->mode=MD_SLICE;
    conf->segWidth=KB*100000;//Default at 100 MB

    conf->inputSize = 0;

    return conf;
}

void printVersion(){
    printf("Version %.2f\r\n", VERSION);
}

void printHelp(){

    FILE * fp;
    fp = fopen("./help.txt", "r");
    if (fp==0){
        printf("Unable to open help file\r\n");
        return;
    }

    size_t size;
    fseek(fp, 0, SEEK_END);
    size=ftell(fp);
    rewind(fp);

    char * help = malloc(size+2);
    int i=0;
    for(i=0; i<size; ++i){
        help[i]=fgetc(fp);
    }

    help[i]=0;

    printf("%s\r\n", help);
}

config * parseCmd(int argc, char ** argv){

    config * conf = defConfig(argc, argv);

    for (int i=1; i< argc; ++i){
        char * op = argv[i];
        
        //printf("%s\r\n", op);

        if (op[0]!='-'){
            addFile(conf, op);
            continue;
        }

        if (op[1]=='-'){

            cli_args args = getOptionValue(op);

            if(strcmp(args.option,"--help")==0){
                printHelp();
            } else if (strcmp(args.option, "")){

            }
        } else {
            for(int j=1; j<strlen(op); ++j){
                switch(op[j]){
                    case 'h': printHelp(); break;
                    case 'v': printVersion(); break;
                    case 's': conf->mode=MD_SLICE; break;
                    case 'c': conf->mode=MD_COMB; break;
                    default: break;
                }
            }
        }

        fflush(stdout);
    }

    return conf;
}

int main(int argc, char**argv){
    
    printf("Software Splicer Tool\r\nWoodrow Scott\r\n");

    config * conf = parseCmd(argc, argv);
    
    getDirListing(".");

    if(conf->mode==MD_COMB){

    } else {

    }

    free(conf);

    return 0;
}