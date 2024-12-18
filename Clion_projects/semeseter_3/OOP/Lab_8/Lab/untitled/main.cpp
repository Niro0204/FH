#include <iostream>
#include <stdio.h>

int main() {
    unsigned int value =  0;
    unsigned int incr = 1;

    while(incr <= 4) {
        while(value <= 11) {
            printf("%u ", value);
            value += incr;
        }
        printf("\n");
        value = 0;
        incr+=1;
    }
    return 0;
}
