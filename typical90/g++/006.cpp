#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n, arr_n[30] = {0}, arr_i[30] = {0};
    vector<int> arr[30];
    for (int i = 0; i < 30; ++i)
        arr[i] = vector<int>();

    string s;
    cin >> n >> k;
    cin >> s;

    for (int str_i = 0; str_i < n; ++str_i) {
        int sel_i = (int)(s[str_i]) - (int)('a');
        arr[sel_i].push_back(str_i);
        ++arr_n[sel_i];
    }

    for (int ans_l = k, str_i = -1; ans_l > 0; --ans_l)
        for (int i = 0; i < 30; ++i) { 

            if (arr_i[i] >= arr_n[i]) continue;
            int isContinue = 1;

            for (; arr_i[i] < arr_n[i] && isContinue; ++arr_i[i]) {
                int val = arr[i][arr_i[i]];
                if (str_i >= val) 
                    continue;
                else if (ans_l > n - val) 
                    break;
                else {
                    cout << (char)(i + (int)('a'));
                    str_i = val;
                    isContinue = 0;
                }
            }
            if (!isContinue) break;
        }
    cout << endl;
}