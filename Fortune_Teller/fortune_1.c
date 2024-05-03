#include <stdio.h>
#include <stdlib.h>

#define BSIZE 256
int main(int argc, char** argv){
    const char* fileName = "pithy.txt";
    FILE* fp;
    char buffer[BSIZE];
    char* r;
    fp = fopen(fileName,"r");
    if(fp == NULL){
        fprintf(stderr,"Unable to open file %s\n",fileName);
        exit(1);
    }
    while(!feof(fp)){
        r = fgets(buffer,BSIZE,fp);
        if( r == NULL){
            break;
        }
        printf("%s",buffer);
    }
    fclose(fp);
    return(0);
}

//look into fgets, fprinf, feof next time
