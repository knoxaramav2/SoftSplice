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
        printf("A1\r\n");
    } else if (st.st_mode & S_IFREG) {
        printf("A2\r\n");
    } else {
        printf("A3\r\n");
    }


    FILE * fp = fopen(dir,"w+");

    fclose(fp);

    return 0;
}

void destroyManifest(objectManifest*manifest){
    
    if (manifest==0) return;
    
    objectNode * on = manifest->head;

    while(on!=0){

        

        on=on->next;
    }

    deleteAllFileMeta();

    free(manifest);
}

void writeManifestLog(objectManifest*manifest, char*outputDir){

}

void manifestRewind(objectManifest*manifest){

}