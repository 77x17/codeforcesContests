#include <bits/stdc++.h>
using namespace std;

int n;

void Input() {
    cin >> n;
}

void Process() {
    if (n == 3) {cout << "-1\n"; return;}

    if (n & 1) {
        for (int i = 1; i <= n / 2; i++) cout << n - i + 1 << ' ';

        for (int i = 1; i <= n / 2 + 1; i++) cout << i << " \n"[i == n / 2 + 1];
    } else for (int i = 1; i <= n; i++) cout << n - i + 1 << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
