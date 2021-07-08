#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

template<typename Ty>
using in = const Ty&;

int main() {
    int num, a[1005] = { 0 };
    cin >> num;
    rep(Int, i, num) {
        int b;
        cin >> b;
        a[b]++;
    }
    repi(Int, i, 1, num + 1) 
        if (a[i] != 1) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    
    return 0;
}