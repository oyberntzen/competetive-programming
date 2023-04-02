#include <cstdio>

typedef long long ll;

ll prefix[20];
int main() {
    int q;
    scanf("%d", &q);

    
    prefix[0] = 0;
    ll pow = 1;
    for (int i = 1; i < 18; i++) {
        prefix[i] = prefix[i-1] + (pow*10-pow)*i;
        pow *= 10;
        //printf("%lld\n", prefix[i]);
    }

    for (int i = 0; i < q; i++) {
        ll k;
        scanf("%lld", &k);
        k--;

        ll j = 0;
        for (; prefix[j] <= k; j++);
        j--;
        //printf("j: %lld\n", j);
        k -= prefix[j];
        //printf("k: %lld\n", k);
        ll digit = j - k % (j+1);
        //printf("d: %lld\n", digit);
        ll num = 1;
        for (int m = 0; m < j; m++) num*=10;
        num += k/(j+1);
       //printf("n: %lld\n", num);
        for (int m = 0; m < digit; m++) num /= 10;
        printf("%lld\n", num%10);
    }
}

//123456789101112131415