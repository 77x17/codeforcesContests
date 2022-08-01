#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

const int MAX_N = 2e5 + 77 * 17;


int n, arr[MAX_N];

void Input() {
    cin >> n;  for (int i = 1; i <= n; i++) cin >> arr[i];
}


bool visited[MAX_N];

void Process() {
    fill(visited + 1, visited + n + 1, false);

    for (int i = n; i >= 1; i--) {
        if (visited[arr[i]]) {
            cout << i << '\n';

            return;
        } else visited[arr[i]] = true;
    }

    cout << 0 << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}

