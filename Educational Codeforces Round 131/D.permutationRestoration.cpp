#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 5e5 + 77 * 17;


int n, arr[MAX_N];

void Input() {
    cin >> n;  for (int i = 1; i <= n; i++) cin >> arr[i];
}


vector<int> adj[MAX_N];

int L[MAX_N], R[MAX_N], result[MAX_N];

void Process() {
    for (int i = 1; i <= n; i++) {
        // floor(i / x[i]) = arr[i]
        // arr[i]   <= i / x[i] < arr[i] + 1
        // i / (arr[i] + 1) < x[i] <= i / arr[i]

        L[i] = i / (arr[i] + 1) + 1;

        R[i] = (arr[i] == 0 ? n : i / arr[i]);
    }

    for (int i = 1; i <= n; i++) adj[i].clear();

    for (int i = 1; i <= n; i++) adj[L[i]].push_back(i);

    set<pair<int, int>> s;

    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) s.insert({R[j], j});

        result[s.begin()->second] = i;

        s.erase(s.begin());
    }

    for (int i = 1; i <= n; i++) cout << result[i] << ' '; cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
