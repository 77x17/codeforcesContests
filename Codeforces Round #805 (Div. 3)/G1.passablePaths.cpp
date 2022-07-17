#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000;


int n, LOG;  vector<int> adj[MAX_N + 1];

void Input() {
    cin >> n;  LOG = log(n) / log(2);  for (int i = 1; i <= n; i++) adj[i].clear();

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;  adj[u].push_back(v);  adj[v].push_back(u);
    }
}


vector<int> high;  vector<vector<int>> par;

void Dfs(const int& u) {
    for (int v : adj[u]) if (v != par[u][0]) {
        high[v] = high[u] + 1;

        par[v][0] = u;

        Dfs(v);
    }
}

int findLCA(int u, int v) {
    if (high[u] < high[v]) return findLCA(v, u);

    for (int j = LOG; j >= 0; j--) if (high[par[u][j]] >= high[v]) u = par[u][j];

    if (u == v) return u;

    for (int j = LOG; j >= 0; j--) if (par[u][j] != par[v][j]) u = par[u][j], v = par[v][j];

    return par[u][0];
}

inline int Calc(const int& u, const int& v) {return high[u] + high[v] - 2 * high[findLCA(u, v)];}

void Process() {
    high.assign(n + 1, 0);  par.assign(n + 1, vector<int> (LOG + 1, 0));

    Dfs(1);

    for (int j = 1; j <= LOG; j++) for (int i = 1; i <= n; i++) par[i][j] = par[par[i][j - 1]][j - 1];


    int q; cin >> q; while (q--) {
        int k; cin >> k;

        if (k <= 2) {
            for (int i = 1; i <= k; i++) {
                int x; cin >> x;
            }

            cout << "YES\n";

            continue;
        }


        bool ok = true;

        int l, r;  cin >> l >> r;

        for (int i = 3; i <= k; i++) {
            int x; cin >> x;

            if (Calc(x, l) + Calc(l, r) == Calc(x, r)) l = x; else

            if (Calc(l, r) + Calc(r, x) == Calc(l, x)) r = x; else

            if (Calc(l, x) + Calc(x, r) != Calc(l, r)) ok = false;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}