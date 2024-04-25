#include <stdio.h>
#include <time.h>

int main(int argc, char** argv){
    time_t now;
    struct tm* clock;
    char time_string[64];

    time(&now); //this initialized now to the value that represents time from epoch till now
    clock = localtime(&now);

    strftime(time_string, 64, "Today is %A, %B %d, %Y%nIt is %r%n",clock);

    printf("Greetings");
    if(argc>1)
        printf(", %s",argv[1]);
    printf("!\n%s", time_string);

    return 0;
}
// Greetings!
// Today is Sunday, April 21, 2024
// It is 04:53:55 PM
