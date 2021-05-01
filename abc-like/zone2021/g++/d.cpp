#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;


int main() {
    string in;
    vector<char> str = vector<char>(1000005);
    bitset<1000005> val = bitset<1000005>(true);
    int ed = 500000;

    rep(int, i, 1000005)
        val[i] = true;

    cin >> in;
    int n = in.length(), st = 500000;
    bool rev = false;
    rep(int, i, n) {
        if (in[i] == 'R')
            rev = !rev;
        else if (rev) {
            str[st] = in[i];
            st--;
        }
        else {
            str[ed] = in[i];
            ed++;
        }
    }

    repi(int, i, st + 1, ed - 1) 
        if (val[i]) 
            for (int j = 0; st < i - j && i + j + 1 < ed; ++j)
                if (val[i - j] && val[i + j + 1] && str[i - j] == str[i + j + 1]) {
                    val[i - j] = false;
                    val[i + j + 1] = false;
                }
                else break;

    if (rev)
        for (int i = ed - 1; i > st; --i)
            if (val[i])
                cout << (char)str[i];
            else;
    else
        repi(int, i, st + 1, ed) 
            if (val[i])
                cout << (char)str[i];

    cout << endl;
    return 0;
}
