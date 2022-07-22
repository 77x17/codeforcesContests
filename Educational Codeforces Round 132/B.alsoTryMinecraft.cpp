#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100005;

int n, m, arr[MAX_N];

void Input() {
    cin >> n >> m;  for (int i = 1; i <= n; i++) cin >> arr[i];
}


long long prefix[MAX_N], suffix[MAX_N];

void Process() {
    prefix[0] = arr[0] = 0;

    for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + max(0, arr[i - 1] - arr[i]);

    suffix[n + 1] = arr[n + 1] = 0;

    for (int i = n; i >= 1; i--) suffix[i] = suffix[i + 1] + max(0, arr[i + 1] - arr[i]);

    while (m--) {
        int s, t; cin >> s >> t;

        cout << (s <= t ? prefix[t] - prefix[s] : suffix[t] - suffix[s]) << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
