#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BZ 256
int main(int argc, char** argv){
    const char* filename = "pithy.txt";
    FILE* fp;
    char buffer[BZ];
    char* r, *entry;
    int items, x;
    char** list_base;
    fp = fopen(filename,"r");
    if(fp == NULL){
        fprintf(stderr, "Unable to open file %s\n",filename);
        exit(1);
    }
    items = 0;
    list_base = (char**)malloc(sizeof(char*)*100);
    if(list_base == NULL){
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }
    while(!feof(fp)){
        r = fgets(buffer, BZ, fp);
        if(r == NULL){
            break;
        }
        entry = (char*)malloc(sizeof(char)*strlen(buffer)+1);
        if(entry == NULL){
            fprintf(stderr, "Unable to allocate memory\n");
            exit(1);
        }
        strcpy(entry, buffer);
        *(list_base+items) = entry;
        items++;
        if(items%100==0){
            list_base = (char**)realloc(list_base,sizeof(char*)*(items+100));
            if(list_base == NULL){
                fprintf(stderr, "Unable to allocate memory\n");
                exit(1);
            }
        }
    }
    for(x=0;x<items;x++){
        printf("%s",*(list_base+x)); //we didn't have to do multiple-indirection because it's a char-array
    }
    fclose(fp);
    return(0);
}