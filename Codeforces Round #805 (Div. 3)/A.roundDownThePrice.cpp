#include <bits/stdc++.h>
using namespace std;


long long m;

void Input() {
    cin >> m;
}


void Process() {
    long long temp = 1;

    while (temp * 10 <= m) temp *= 10;

    cout << m - temp << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();
        Process();
    }

    return 0;
}
