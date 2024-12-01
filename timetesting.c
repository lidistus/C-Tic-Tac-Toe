#include <stdio.h>
#include <time.h>
#include <unistd.h>

int testTime() {


    time_t time1 = time(NULL); // Grabs current system time since epoch.
    sleep(1);
    time_t time2 = time(NULL); // I have no idea what im doing.

    for(int i = 3; time2 > time1 && i > 0; i--) {
    sleep(1);
    printf("Current: %d\n", i);
    }
}   


int main(void) {
int state = 1;

  while(state == 1) {
    testTime();
  }  
    }