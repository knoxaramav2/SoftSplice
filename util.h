#pragma once
#ifndef SPLICE_UTIL
#define SPLICE_UTIL

typedef struct cli_args{
    char * option;
    char * value;
} cli_args;

cli_args getOptionValue(char *);
#endif