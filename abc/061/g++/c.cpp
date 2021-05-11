#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    Int que_n, select_k, num_count[100005] = { 0 };
    cin >> que_n >> select_k;

    rep (Int, i, que_n) {
        Int a, b;
        cin >> a >> b;
        num_count[a] += b;
    }

    Int sum = 0;

    rep (int, ans_i, 100005) 
        if (num_count[ans_i]) {
            sum += num_count[ans_i];
            if (sum >= select_k) {
                cout << ans_i << endl;
                return 0;
            }
        }
    return 0;
}