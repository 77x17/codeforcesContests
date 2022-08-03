#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 77 * 17;


int n, a[MAX_N], b[MAX_N];

vector<int> adj[MAX_N];

void Input() {
    cin >> n;

    for (int i = 1; i <= n; i++) adj[i].clear();

    for (int i = 2; i <= n; i++) {
        int p; cin >> p >> a[i] >> b[i];

        adj[p].push_back(i);
    }
}


long long aSum = 0, bSum = 0;  int result[MAX_N];

vector<long long> order;

void Dfs(int u) {
    aSum += a[u];  bSum += b[u];

    order.push_back(bSum);

    result[u] = upper_bound(order.begin(), order.end(), aSum) - order.begin();

    for (int v : adj[u]) Dfs(v);

    aSum -= a[u];  bSum -= b[u];

    order.pop_back();
}

void Process() {
    Dfs(1);

    for (int i = 2; i <= n; i++) cout << result[i] - 1 << " \n"[i == n];
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
