#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
#define int64min -9223372036854775807
#define seg_length 1048576 

struct seg_tree {
    vector<ll> s;
    vector<ll> z;

    void init() {
        s.resize(seg_length, 0);
        z.resize(seg_length, 0);
    }

    ll add(int a, int b, ll u, int i = 1, int x = 0, int y = seg_length/2) {
        //printf("%d %d %lld %d %d %d\n", a, b, u, i, x, y);
        if (b <= x || a >= y) return s[i]+z[i];
        if (a <= x && b >= y) {
            if (y-x == 1) {
                s[i] += u;
                return s[i];
            }
            z[i] += u;
            return s[i]+z[i];
        }
        int mid = (x+y)/2;
        if (z[i] != 0) {
            add(x, mid, z[i], i*2, x, mid);
            add(mid, y, z[i], i*2+1, mid, y);
            z[i] = 0;
        }
        ll m1 = add(a, b, u, i*2, x, mid);
        ll m2 = add(a, b, u, i*2+1, mid, y);
        s[i] = max(m1, m2);
        //printf("%d %lld\n", i, s[i]);
        return s[i];
    }

    ll maxx(int a, int b, int i = 1, int x = 0, int y = seg_length/2) {
        //printf("%d %d %d %d %d\n", a, b, i, x, y);
        if (b <= x || a >= y) return int64min;
        if (a <= x && b >= y) return s[i]+z[i];
        int mid = (x+y)/2;
        if (z[i] != 0) {
            ll m1 = add(x, mid, z[i], i*2, x, mid);
            ll m2 = add(mid, y, z[i], i*2+1, mid, y);
            s[i] = max(m1, m2);
            z[i] = 0;
        }
        ll m1 = maxx(a, b, i*2, x, mid);
        ll m2 = maxx(a, b, i*2+1, mid, y);
        //printf("%d: %lld %lld\n", i, m1, m2);
        return max(m1, m2);
    }

    void print() {
        printf("s ");
        for (int i = 0; i < seg_length; i++) {
            printf("%lld ", s[i]);
        }
        printf("\n");
        printf("z ");
        for (int i = 0; i < seg_length; i++) {
            printf("%lld ", z[i]);
        }
        printf("\n\n");
    }
};

int main() {
    seg_tree s1;
    //s1.init();
    //s1.print();
    //s1.add(0, 2, 5);
    //s1.print();
    /*s1.add(1, 2, 3);
    s1.print();
    s1.add(2, 3, 4);
    s1.print();
    printf("%lld\n", s1.maxx(0, 3));
    printf("%lld\n", s1.maxx(0, 2));
    *///printf("%lld\n", s1.maxx(1, 3));
    //s1.print();

    int n, q;
    scanf("%d %d\n", &n, &q);

    vector<ll> p;
    for (int i = 0; i < n; i++) {
        ll pi;
        scanf("%lld", &pi);
        p.push_back(pi);
    }
    sort(p.begin(), p.end(), greater<int>());
    scanf("\n");

    seg_tree left;
    seg_tree right;
    left.init();
    right.init();
    for (int i = 0; i < n; i++) {
        left.add(i, i+1, p[i] + i+1);
        right.add(i, i+1, p[i] + i);
    }
    //left.print();
    //right.print();

    for (int i = 0; i < q; i++) {
        char q;
        scanf("%c\n", &q);
        //printf("q%d %c\n", i, q);
        if (q == 'B') {
            ll x, y;
            scanf("%lld %lld\n", &x, &y);

            int a = 0;
            int b = n;
            while (b-a > 0) {
                int m = (a+b+1)/2;
                if (right.maxx(m, m+1)-m >= x) {
                    a = m;
                } else {
                    b = m-1;
                }
            }
            if (right.maxx(0, 1) >= x) {
                left.add(0, a+1, y);
                right.add(0, a+1, y);
            }
        } else if (q == 'K') {
            ll x, y;
            scanf("%lld %lld\n", &x, &y);

            int a = 0;
            int b = n;
            while (b-a > 1) {
                int m = (a+b+1)/2;
                if (right.maxx(m, m+1)-m <= x) {
                    b = m-1;
                } else {
                    a = m;
                }
            }
            if (a < n-1) {
                left.add(a+1, n, -y);
                right.add(a+1, n, -y);
            }
        } else if (q == 'Z') {
            int a = 0;
            int b = n;
            while (b-a > 0) {
                int m = (a+b)/2;
                ll ml = left.maxx(0, m);
                ll mr = right.maxx(m+1, n);

                if (max(ml, mr) <= right.maxx(m, m+1)-m+n) {
                    a = m+1;
                } else {
                    b = m;
                }
            }
            printf("%d\n", a);
        }
        //left.print();
        //right.print();
    }
}