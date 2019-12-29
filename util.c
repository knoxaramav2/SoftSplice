#include <stdlib.h>
#include <string.h>

#include "util.h"

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