#include <bits/stdc++.h>

using namespace std;


int n, x;  vector<int> arr;

void Input() {
    cin >> n >> x;  arr.assign(2 * n + 1, 0);

    for (int i = 1; i <= 2 * n; i++) cin >> arr[i];
}


void Process() {
    sort(arr.begin() + 1, arr.end());

    bool ok = true;

    for (int i = 1; i <= n; i++) {
        if (arr[i + n] - arr[i] < x) ok = false;
    }

    if (ok) cout << "YES\n"; else cout << "NO\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
