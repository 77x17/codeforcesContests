#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 77 * 17;


int n, q;  vector<int> arr;

void Input() {
    cin >> n >> q;  arr.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> arr[i];
}


stack<int> s;

vector<int> nearMx;

vector<bool> ok;

void Process() {
    int mx = 0;  ok.assign(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (mx < arr[i]) {
            mx = arr[i];

            ok[i] = true;
        }
    }

    nearMx.assign(n + 1, 0);

    s = stack<int>();

    for (int i = n; i >= 1; i--) {
        if (s.size()) while (s.size() && arr[s.top()] <= arr[i]) s.pop();

        if (s.size()) nearMx[i] = s.top();

        s.push(i);
    }

    while (q--) {
        int x, k; cin >> x >> k;

        if (not ok[x]) cout << 0 << '\n'; else {
            if (nearMx[x] == 0) cout << max(0, k - x + 1 + (x != 1)) << '\n';
            else {
                k = min(k, nearMx[x] - 2);

                cout << max(0, k - x + 1 + (x != 1)) << '\n';
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
