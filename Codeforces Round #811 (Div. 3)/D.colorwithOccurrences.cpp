#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

const int MAX_N = 111;


int n;

string t, s[10 + 1];

void Input() {
    cin >> t >> n;  t = '^' + t;

    for (int i = 1; i <= n; i++) cin >> s[i];
}


int dp[MAX_N];  pair<int, int> trace[MAX_N];

int Calc(int x, int y) {
    int temp = x - s[y].size() + 1;

    if (temp >= 0 && t.substr(temp, s[y].size()) == s[y]) return temp;

    return -1;
}

void Process() {
    fill(dp + 1, dp + t.size(), INF);  dp[0] = 0;

    for (int i = 1; i < t.size(); i++) {
        for (int j = 1; j <= n; j++) {
            int temp = Calc(i, j);

            if (temp >= 1) {
                for (int k = temp; k <= i; k++) {
                    if (dp[i] > dp[k - 1] + 1) {
                        dp[i] = dp[k - 1] + 1;

                        trace[i] = {j, k};
                    }
                }
            }
        }
    }

    if (dp[t.size() - 1] == INF) cout << -1 << '\n';
    else {
        cout << dp[t.size() - 1] << '\n';

        int temp = t.size() - 1;

        while (trace[temp].first) {
            cout << trace[temp].first << ' ' << temp - s[trace[temp].first].size() + 1 << '\n';

            temp = trace[temp].second - 1;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int q; cin >> q; while (q--) {
        Input();

        Process();
    }

    return 0;
}


