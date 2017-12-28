#include <stdio.h>
#include <stdlib.h>

int main() {
    long y = 0;
    long x = 100;
    long err = 0;
 
    while (x >= y) {
        //DrawPixels
        printf("%ld %ld %ld\n", x, y, err);
        err += 2 * y++ + 1;
        if (err - x + 1 > 0)
            err += -2 * x-- + 1;
    }
}
