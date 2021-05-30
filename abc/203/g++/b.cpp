#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    Int n, k, count = 0;

    cin >> n >> k;
    repi (Int, i, 1, n + 1) repi (Int, j, 1,  k + 1) 
        count += (100 * i + j);
    
    cout << count << endl;
    return 0;
}