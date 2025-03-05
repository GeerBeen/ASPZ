#include <stdio.h>
#include <time.h>
#include <limits.h> 

int main() {
    time_t max_time_64 = LLONG_MAX/137; // a number that I obtained manually by binary brute force
    // for some reason, numbers greater than this,
    // for example LLONG_MAX/136, break the ctime() function and it return null instead of date
    printf("Day when time_t expires in 64 bit system: %s,\n%ld\n", ctime(&max_time_64),max_time_64);
    
    time_t max_time_32 = INT_MAX;
    printf("Day when time_t expires in 32 bit system: %s,\n%ld\n", ctime(&max_time_32),max_time_32);
    
    return 0;
}
