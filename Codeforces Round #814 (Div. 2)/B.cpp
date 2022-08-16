#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 77 * 17;


int n, k;

void Input() {
    cin >> n >> k;
}


void Process() {
    if (k & 1) {
        cout << "YES\n";

        for (int i = 1; i <= n; i += 2) cout << i << ' ' << i + 1 << '\n';
    } else {
        if ((2 + k) * 1 % 4) {cout << "NO\n";  return;}

        cout << "YES\n";

        for (int i = 1; i <= n; i += 2) {
            if ((i + 1) % 4) cout << i + 1 << ' ' << i << '\n'; else cout << i << ' ' << i + 1 << '\n';
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
