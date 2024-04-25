#include <stdio.h>
#include <time.h>

int main(int argc, char** argv){
    time_t now;
    struct tm* clock;
    int hr;

    time(&now);
    clock = localtime(&now);
    hr = clock->tm_hour;

    printf("Current Time: %s",ctime(&now));
    printf("Good ");
    if(hr>5 && hr<12){
        printf("morning!");
    }else if(hr>12 && hr<17){
        printf("afternoon!");
    }else{
        printf("evening!");
    }
    if(argc>1){
        printf(" Sire %s.",argv[1]);
    }
    puts("\n");
    return (0);
}
// Current Time: Sat Apr 20 01:51:32 2024
// Good evening! Sire Khanna.
