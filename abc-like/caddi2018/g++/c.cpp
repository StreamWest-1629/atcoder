#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    long long n, p, ans = 1;
    bitset<10000005> isCmp = bitset<10000005>();
    cin >> n >> p;

    if (n == 1) 
        cout << p;
    else {
        for (long long i = 2; i < 10000005; i++) 
            if (!isCmp[i]) {
                for (long long j = i << 1; j < 10000005; j += i) isCmp[j] = true;
                long long sep = 1, exp = 0;
                if (i > p) break;
                while (p % (sep * i) == 0) {
                    sep *= i;
                    exp ++;
                }
                p /= sep;
                ans *= (long long)pow((long double)i, (long double)(exp / n));
            }
        cout << ans;
    }
    return 0;
}