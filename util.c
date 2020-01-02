#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>

#include "util.h"

#define PAGE_SIZE 10

#define DIRENT_FOLDER   4
#define DIRENT_FILE     8

cli_args getOptionValue(char * str){

    cli_args args;

    int len = strlen(str);

    char * arg = malloc(len+1);
    char * val = malloc(len+1);

    int i = 0;

    for (; i<len; ++i){
        if (str[i]=='='){
            break;
        }

        arg[i]=str[i];
    }

    arg[i]=0;

    for (; i<len; ++i){
        val[i]=str[i];
    }

    val[i]=0;

    args.option = arg;
    args.value = val;

    return args;
}

char ** getDirListing(char * dir){

    char ** dirList=malloc((sizeof (char *)) * PAGE_SIZE);

    struct dirent * d;
    DIR * dr = opendir(dir);

    if (dr == NULL){
        //TODO add exceptions
        return NULL;
    }

    int results = 0;
    int page = 1;

    while((d=readdir(dr)) != NULL){
        if (d->d_type!=DIRENT_FOLDER){
            continue;
        }

        printf(">> %s\r\n", d->d_name);

        if (results==PAGE_SIZE-1){
            char ** tmp = realloc(dirList, (sizeof (char *)) * PAGE_SIZE * page);
            if (tmp!=NULL){
                //TODO Throw exception
                return NULL;
            }
        }


    

    }

    closedir(dr);

    return dirList;
}

char * getFileListing(char * dir){

    return 0;
}