#include <stdio.h>
#include <time.h>

int main(int argc, char** argv){
    time_t now;
    struct tm* clock;

    time(&now);
    clock = localtime(&now);
    puts("Time Details: ");
    printf("Day of the year: %d\n",clock->tm_yday);
    printf("Day of the week: %d\n",clock->tm_wday);
    printf("Year\t       : %d\n",(1900+clock->tm_year));
    printf("Month\t       : %d\n",(1+clock->tm_mon));
    printf("Date\t       : %d\n",clock->tm_mday);
    printf("Hour\t       : %d\n",clock->tm_hour);
    printf("Minute\t       : %d\n",clock->tm_min);
    printf("Second\t       : %d\n",clock->tm_sec);
    return 0;

}
//OUTPUT
// Time Details:
// Day of the year: 109
// Day of the week: 5
// Year	          : 2024
// Month	      : 4
// Date	          : 19
// Hour	          : 21
// Minute	      : 28
// Second	      : 23
