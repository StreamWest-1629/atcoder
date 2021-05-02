#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    long n, k, init;
    cin >> n >> k;

    vector<int> a = vector<int>(n);
    vector<int> check = vector<int>(n);
    vector<int> route = vector<int>(0);

    rep(int, i, n) {
        cin >> a[i];
        a[i] = a[i] - 1;
        int ac = a[i];
        check[i] = -1;
    }
    
    check[0] = 0;
    route.push_back(0);
    
    for (int i = a[0]; true; i = a[i]) {
        check[i] = route.size();
        route.push_back(i);
        if (check[a[i]] != -1) {
            init = check[a[i]];
            break;
        }
    }

    int ans;
    int size = route.size();

    if (k > init) 
        ans = init + ((k - init) % (route.size() - init));
    else
        ans = k;
    
    cout << route[ans] + 1 << endl;
    return 0;
    
}