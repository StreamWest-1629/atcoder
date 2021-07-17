#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

template<typename Ty>
using in = const Ty&;

int main() {
    
    int n;
    string s;
    cin >> n;
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cout << (i % 2 == 0 ? "Takahashi" : "Aoki") << endl;
            return 0;
        }
    }
    return 0;
}