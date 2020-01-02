#pragma once
#ifndef SPLICE_SPLICE
#define SPLICE_SPLICE 

#include "chunk.h"
#include "file.h"

//File partition information for chunking
typedef struct objectNode{
    unsigned start;
    unsigned length;
    char * fileName;

    FILE_META * fileMeta;

    struct objectNode * next;
} objectNode;

//Define file structure and metadata
typedef struct objectManifest{
    objectNode * head;
    objectNode * current;
    unsigned files;
    unsigned totalWidth;
} objectManifest;

//Create manifest from file/directory
objectManifest * createManifest(char*);
//free manifest resources
void destroyManifest(objectManifest*);
//write manifest information log
void writeManifestLog(objectManifest*,char*);
//Rewind objectManifest->current to head
void manifestRewind(objectManifest*);

#endif