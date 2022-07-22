#include <bits/stdc++.h>

using namespace std;


int x, arr[4];

void Input() {
    cin >> x;  for (int i = 1; i <= 3; i++) cin >> arr[i];
}


void Process() {
    bool ok = true;

    if (arr[x] == 0) ok = false;

    for (int i = 1; i <= 3; i++) if (arr[i] == i) ok = false;

    cout << (ok ? "YES" : "NO") << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
