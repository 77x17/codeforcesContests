#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000 + 77 * 17;


int n;

void Input() {
    cin >> n;
}


bool visited[MAX_N];

void Process() {
    cout << 2 << '\n';

    memset(visited, 0, sizeof visited);

    for (int k = 1; k <= n; k++) if (not visited[k]) {
        for (int i = k; i <= n; i *= 2) visited[i] = true, cout << i << ' ';
    }

    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
