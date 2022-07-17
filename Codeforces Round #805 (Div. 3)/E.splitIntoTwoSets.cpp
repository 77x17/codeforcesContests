#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int MAX_N = 200000;


int n;  vector<int> adj[MAX_N + 1];  bool ok = true;

void Input() {
    cin >> n;  for (int i = 1; i <= n; i++) adj[i].clear();

    for (int i = 1; i <= n; i++) {
        int u, v; cin >> u >> v;  adj[u].push_back(v);  adj[v].push_back(u);

        if (u == v || adj[u].size() > 2 || adj[v].size() > 2) ok = false;
    }
}


vector<bool> visited;

int Dfs(int u) {
    visited[u] = true;

    for (int v : adj[u]) if (not visited[v]) return Dfs(v) + 1;

    return 1;
}

void Process() {
    visited.assign(n + 1, false);

    for (int i = 1; i <= n; i++) if (not visited[i]) if (Dfs(i) & 1) ok = false;

    if (ok) cout << "YES\n"; else ok = true, cout << "NO\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
