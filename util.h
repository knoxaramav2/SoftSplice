#pragma once
#ifndef SPLICE_UTIL
#define SPLICE_UTIL

typedef struct cli_args{
    char * option;
    char * value;
} cli_args;

char ** getDirListing(char*);

cli_args getOptionValue(char *);
#endif