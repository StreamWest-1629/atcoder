#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    Int arg_n, arg_c, arg_k;
    Int arg_t[100005] = { 0 };
    cin >> arg_n >> arg_c >> arg_k;
    rep (Int, i, arg_n) cin >> arg_t[i];

    sort(arg_t, arg_t + arg_n);

    Int query_i = 0, ans = 0;
    for (; query_i < arg_n; ans++) {
        Int limit_t = arg_t[query_i] + arg_k;
        Int solve_n = 0;
        for (; solve_n < arg_c && arg_t[query_i] <= limit_t; query_i++, solve_n++);
    }

    cout << ans << endl;

    return 0;
}