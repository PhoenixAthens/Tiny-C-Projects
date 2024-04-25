#include <stdio.h>
#include <time.h>
int main(int argc, char** argv){
    time_t now;
    time(&now);
    //if we don't use the time(now) function, we get this warning "initialize the variable 'now' to silence this warning",
    // time_t now;
    //               ^
    //                = 0

    printf("The computer thinks, current time is %ld\n",now);
    printf("I think, it means %s\n",ctime(&now));
    return 0;
}
//OUTPUT without time(&now)
// The computer thinks, current time is 3251176725343423160
// I think, it means (null)
//
// OUTPUT with time(&now)
//The computer thinks, current time is 1713541395
//I think, it means Fri Apr 19 21:13:15 2024
