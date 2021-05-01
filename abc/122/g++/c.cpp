#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < n; ++val)

int main() {
    string str;
    int n, q, has[100005] = { 0 }, sum[100005] = { 0 }, ans[100005] = { 0 };
    cin >> n >> q;
    cin >> str;
    
    for (int i = 1; i < n; ++i) {
        if (str[i - 1] == 'A' && str[i] == 'C') 
            has[i]++;
        sum[i] = sum[i - 1] + has[i];
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        ans[i] = sum[r] - sum[l];
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << endl;
    }
    return 0;

}