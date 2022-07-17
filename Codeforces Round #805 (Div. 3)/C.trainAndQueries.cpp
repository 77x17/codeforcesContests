#include <bits/stdc++.h>
using namespace std;


int n, k;
vector<int> arr;

void Input() {
    cin >> n >> k;
    arr.assign(n + 1, 0); for (int i = 1; i <= n; i++) cin >> arr[i];
}


void Process() {
    map<int, int> minIdx, maxIdx;

    for (int i = 1; i <= n; i++) if (minIdx[arr[i]] == 0) minIdx[arr[i]] = i;
    for (int i = n; i >= 1; i--) if (maxIdx[arr[i]] == 0) maxIdx[arr[i]] = i;

    while (k--) {
        int a, b; cin >> a >> b;

        if (minIdx[a] < maxIdx[b] && minIdx[a] && maxIdx[b]) cout << "YES\n"; else cout << "NO\n";
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
