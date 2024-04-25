//somewhat flexible
#include <stdio.h>
int main(int argc, char** argv){
    if(argc<2){
        printf("Hello Khanna!\n");
    }else{
        printf("Hello, Sire %s\n",argv[1]);
    }
}
