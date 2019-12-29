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
        
        printf("%s\r\n", op);

        if (strlen(op)<2 || op[0]!='-'){
            printf("Please format options with '-' or '--' (%s)\r\n", op);
            continue;
        }

        if (op[1]=='-'){

            cli_args args = getOptionValue(op);

            char * param = 0;

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
    
    if(conf->mode==MD_COMB){

    } else {
        
    }

    free(conf);

    return 0;
}