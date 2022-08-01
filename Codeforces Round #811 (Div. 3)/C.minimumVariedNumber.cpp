#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

const int MAX_N = 77 * 17;


int s;

void Input() {
    cin >> s;
}


bool ok, visited[10];

void Backtrack(int s) {
    if (s == 0) {
        for (int i = 1; i <= 9; i++) if (visited[i]) cout << i;

        cout << '\n';

        ok = true;

        return;
    }

    if (s <= 9 && not visited[s]) {
        visited[s] = true;

        for (int i = 1; i <= 9; i++) if (visited[i]) cout << i;

        cout << '\n';

        ok = true;

        return;
    }

    for (int i = min(9, s); not ok && i >= 1; i--) if (not visited[i]) {
        if (s >= i) {
            visited[i] = true;

            Backtrack(s - i);

            visited[i] = false;
        }
    }
}

void Process() {
    fill(visited, visited + 10, false);

    ok = false;

    Backtrack(s);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}


