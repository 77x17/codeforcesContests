#include <bits/stdc++.h>

using namespace std;


int n;  vector<int> arr;

void Input() {
    cin >> n;  arr.assign(n + 1, 0);  for (int i = 1; i <= n; i++) cin >> arr[i];
}


void Process() {
    bool ok = true;

    for (int i = 1; i <= n; i++) if (arr[i] % arr[1] != 0) ok = false;

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
