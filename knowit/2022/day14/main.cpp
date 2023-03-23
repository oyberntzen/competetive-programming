#include <iostream>

#define LENGTH 100000
#define LENGTH_PER_REINDEER 1000

int main() {
    int shifts = LENGTH/LENGTH_PER_REINDEER;
    unsigned long long weight = 900+100;
    unsigned long long reindeers = 0;
    for (int i = 0; i < shifts; i++) {
        weight += LENGTH_PER_REINDEER;
        unsigned long long new_reindeers = (weight+199)/200 + (reindeers+1)/2;
        reindeers += new_reindeers;
        /*for (int j = 0; j*200 < weight; j++) {
            new_weight += 100;
            reindeers++;
        }*/
        printf("%lld %lld %lld\n", weight, new_reindeers, reindeers);
        
    }
    printf("%lld\n", reindeers);
}
