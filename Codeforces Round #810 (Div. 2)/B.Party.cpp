#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

const int MAX_N = 1e5 + 77 * 17;


int n, m, arr[MAX_N];

vector<int> adj[MAX_N];

void Input() {
    cin >> n >> m;  for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 1; i <= n; i++) adj[i].clear();

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);  adj[v].push_back(u);
    }
}


int Calc(int u) {
    int result = INF;

    for (int v : adj[u]) if (adj[v].size() % 2 == 0) result = min(result, arr[v]);

    return result;
}

void Process() {
    if (m % 2 == 0) {cout << 0 << '\n'; return;}

    int result = INF;

    for (int i = 1; i <= n; i++) {
        if (adj[i].size() & 1) {
            result = min(result, arr[i]);
        } else {
            int delta = Calc(i);

            result = min(result, arr[i] + delta);
        }
    }

    cout << result << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
