#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    Int arg_n, arg_k;
    multimap<Int, Int> arg_ab;

    cin >> arg_n >> arg_k;
    rep(Int, fr_i, arg_n) {
        Int a, b;
        cin >> a >> b;
        arg_ab.insert(make_pair(a, b));
    }

    Int before = 0;

    for (auto f = arg_ab.begin(); f != arg_ab.end(); f++) {
        if (arg_k < (*f).first - before) {
            cout << (arg_k + before);
            return 0;
            
        } else {
            arg_k -= (*f).first - before;
            arg_k += (*f).second;
            before = (*f).first;
        }
    };

    cout << (before + arg_k);
    return 0;
}