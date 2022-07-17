#include <bits/stdc++.h>

using namespace std;


int n;  vector<int> arr;

void Input() {
    cin >> n;  arr.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> arr[i];
}


int m;  string s;

void Process() {
    for (int i = 1; i <= n; i++) {
        cin >> m >> s;

        for (char e : s) if (e == 'U') arr[i]--; else arr[i]++;
    }

    for (int i = 1; i <= n; i++) cout << (arr[i] + 10) % 10 << ' '; cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (fopen("Task.inp", "r")) freopen("Task.inp", "r", stdin), freopen("Task.out", "w", stdout);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
