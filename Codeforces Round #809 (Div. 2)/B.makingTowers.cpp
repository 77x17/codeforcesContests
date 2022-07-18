#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;


int n;  vector<int> arr;

void Input() {
    cin >> n;  arr.assign(n + 1, 0);  for (int i = 1; i <= n; i++) cin >> arr[i];
}


vector<int> adj[MAX_N + 1];

void Process() {
    for (int i = 1; i <= n; i++) adj[i].clear();

    for (int i = 1; i <= n; i++) adj[arr[i]].push_back(i);

    for (int i = 1; i <= n; i++) {
        int result = not adj[i].empty();

        for (int j = 1; j < adj[i].size(); j++) {
            if ((adj[i][j] - adj[i][j - 1]) & 1) result++;
        }

        cout << result << ' ';
    } cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
