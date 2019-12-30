#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#if OS_NAME == WINDOWS
    #include "windows.h"
#elif OS_NAME == GNU
    #include "dirent.h"
#else

#endif

#include "splice.h"

objectManifest* createManifest(char*dir){

    struct stat st;

    if(stat(dir,&st) == 0){

    } else if (st.st_mode & S_IFREG) {

    } else {

    }


    FILE * fp = fopen(dir,"w+");



    return 0;
}

void destroyManifest(objectManifest*manifest){
    free(manifest);
}

void writeManifestLog(objectManifest*manifest, char*outputDir){

}

void manifestRewind(objectManifest*manifest){

}