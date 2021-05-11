#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    uInt n, ans[100005] = { 0 };
    cin >> n;
    
    rep (int, i, n + 1) ans[i] = 1;
    repi(int, i, 2, n + 1) {
        if (ans[i] == 1) {
            for (uInt check_pow = i; check_pow < n + 1; check_pow *= i) 
                for (uInt add_i = check_pow << (check_pow == i ? 1 : 0); add_i < n + 1; add_i += check_pow) {
                    ans[add_i]++;
                }
            
            ans[i]++;
        }
        else {}
    }
    repi (int, i, 1, n)
        cout << ans[i] << " ";
    cout << ans[n] << endl;
        
    return 0;
}