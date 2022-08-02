#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 77 * 17;


int n, m, k, arr[MAX_N];

void Input() {
    cin >> n >> m >> k;  for (int i = 1; i <= k; i++) cin >> arr[i];
}


vector<long long> delta;

bool ok(int n, int m) {
    delta.clear();

    for (int i = 1; i <= k; i++) if (arr[i] / n >= 2) delta.push_back(arr[i] / n);

    if ((m + 1) & 1) {
        long long sum = 0;

        for (int e : delta) sum += e;

        return sum >= m;
    } else {
        for (long long& e : delta) if (e >= 3) {
            if (m <= e) return true;

            m -= 3;

            e = (e <= 4 ? 0 : e - 3);

            break;
        }

        if (m & 1) return false;

        long long sum = 0;

        for (int e : delta) sum += e;

        return sum >= m;
    }
}

void Process() {
    if (ok(n, m) || ok(m, n)) cout << "Yes\n";  else cout << "No\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
