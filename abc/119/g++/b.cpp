#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double yen, btc;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        double d;
        string s;
        cin >> d >> s;
        if (s == "JPY") {
            yen += d;
        }
        else {
            btc += d;
        }
    }
    cout << (double)yen + (btc * 380000.0) << endl;
    cout << "";
}