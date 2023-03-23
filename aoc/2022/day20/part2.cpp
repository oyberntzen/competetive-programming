#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    freopen("input.txt", "r", stdin);

    int num;
    vector<ll> nums;
    vector<int> indicies;
    int i = 0;
    while (scanf("%d", &num) != EOF) {
        nums.push_back(num);
        indicies.push_back(i);
        i++;
    }
    
    int size = nums.size();

    for (int i = 0; i < size; i++) {
        nums[i] *= 811589153l;
    }

    for (int n = 0; n < 10; n++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (indicies[j] == i) {
                    ll num = nums[j];
                    nums.erase(nums.begin()+j);
                    indicies.erase(indicies.begin()+j);
                    ll index = j+num;
                    if (index <= 0) {
                        index %= size-1;
                        if (index <= 0) index += size-1;
                    } else if (index >= size-1) {
                        index %= size-1;
                    }
                    nums.insert(nums.begin()+index, num);
                    indicies.insert(indicies.begin()+index, i);
                    break;
                }
            }
        }
    }
    

    int k;
    for (int i = 0; i < size; i++) {
        if (nums[i] == 0) k = i;
    }

    long a = nums[(k+1000)%size];
    long b = nums[(k+2000)%size];
    long c = nums[(k+3000)%size];
    printf("%ld %ld %ld %ld\n", a, b, c, a+b+c);
}