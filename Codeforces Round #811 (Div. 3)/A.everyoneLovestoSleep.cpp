#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

const int MAX_N = 77 * 17;


int n, H, M, h[MAX_N], m[MAX_N];

void Input() {
    cin >> n >> H >> M;

    for (int i = 1; i <= n; i++) cin >> h[i] >> m[i];
}


void Process() {
    int result = INF;

    for (int i = 1; i <= n; i++) {
        if (h[i] == H) {
            if (m[i] >= M) {
                result = min(result, m[i] - M);
            }
        } else if (h[i] > H) {
            result = min(result, (h[i] - H) * 60 + m[i] - M);
        }
    }

    H -= 24;

    for (int i = 1; i <= n; i++) {
        if (h[i] == H) {
            if (m[i] >= M) {
                result = min(result, m[i] - M);
            }
        } else if (h[i] > H) {
            result = min(result, (h[i] - H) * 60 + m[i] - M);
        }
    }

    cout << result / 60 << ' ' << result % 60 << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
