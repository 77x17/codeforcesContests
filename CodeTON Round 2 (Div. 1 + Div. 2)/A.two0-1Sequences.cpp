#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 77 * 17;


int n, m;  string a, b;

void Input() {
    cin >> n >> m >> a >> b;
}


void Process() {
    if (a == b) {cout << "YES\n";  return;}

    for (int i = n - 1, j = m - 1; j >= 1; i--, j--) {
        if (a[i] != b[j]) {cout << "NO\n";  return;}
    }

    for (int i = n - m; i >= 0; i--) {
        if (a[i] == b[0]) {cout << "YES\n"; return;}
    }

    cout << "NO\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
