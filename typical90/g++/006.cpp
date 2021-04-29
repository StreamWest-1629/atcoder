#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> idx_list[30];
    for (int i = 0; i < 30; ++i) 
        idx_list[i] = vector<int>();
    
    int n, k, idx, stop[30] = { 0 };
    string s;
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; ++i) 
        idx_list[(s[i] - 'a')].push_back(n - i);
    
    idx = k;
    int str_idx = -1;

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < 30; ++j) {
            if (stop[j] >= idx_list[j].size()) continue;
            else if (idx > idx_list[j][stop[j]] || str_idx > n - idx_list[j][stop[j]]) continue;
            else {
                cout << (char)(j + 'a');
                str_idx = n - idx_list[j][stop[j]];
                ++stop[j];
                --idx;
                break;
            }
        }
    }
    cout << endl;
}