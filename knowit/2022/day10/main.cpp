#include <iostream>

#define rmax 1000000
#define rmaxinv 1/rmax
#define a 0.2
#define b 0.000075
#define c 1/83
#define d 0.1

int main() {
    long n = 1000000000000;

    long r = 125000;
    long u = 3500;

    for (long i = 0; i < n; i++) {
        double lr = double(r);
        double lu = double(u);

        r = long(lr * (1+(a*(rmax-lr))*rmaxinv-b*lu));
        u = long(lu * (1 + b*lr*c - d));

        if (i%1000000000==0) {
            printf("%ld %ld %ld\n", i/1000000000, r, u);
        }
    }

    printf("%ld %ld\n", r, u);
}