#include <bits/stdc++.h>
using namespace std;

#define for(type, val, n) for(type val = 0; val < n; ++val)
#define fori(type, val, init, end) for(type val = init; val < n; ++val)

int main() {
    int n, q;
    vector<int> a, b, ans;
    
    cin >> n;
    a = vector<int>(n);
    for(int, i, n) cin >> a[i];
    
    cin >> q;
    b = vector<int>(q);
    ans = vector<int>(q);
    for(int, i, q) cin >> b[i];

    vector<pair<int, int>> bp = vector<pair<int, int>>(q);
    for(int, i, q) bp[i] = pair<int, int>(i, b[i]);
    sort(a.data(), a.data() + n);
    sort(bp.data(), bp.data() + q, [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    int idx = 0;
    for(int, i, q)
        while(idx < n) 
            if (idx + 1 == n) {
                ans[bp[i].first] = abs(a[idx] - bp[i].second);
                break;
            }
            else if (abs(a[idx] - bp[i].second) < abs(a[idx + 1] - bp[i].second)) {
                ans[bp[i].first] = abs(a[idx] - bp[i].second);
                break;
            }
            else 
                idx++;
    
    for(int, i, q)
        cout << ans[i] << endl;
}
