#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2000 + 1;

struct segment {
    int s, l, r;

    segment(int _s = 0, int _l = 0, int _r = 0) {
        s = _s, l = _l, r = _r;
    }

    bool operator < (const segment& x) const {
        return s < x.s || (s == x.s && l < x.l);
    }
};

int n, arr[MAX_N];

void Input() {
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> arr[i];
}

vector<segment> order;

void Process() {
    order.clear();

    for (int i = 1; i <= n; i++) {
        int sum = 0;

        for (int j = i; j <= n; j++) {
            sum += arr[j];

            order.push_back(segment(sum, i, j));
        }
    }

    int result = n;

    sort(order.begin(), order.end());

    for (int k = 0; k < order.size();) {
        int curr = 0, sum = order[k].s, p[n + 1]; for (int i = 1; i <= n; i++) p[i] = 0;

        for (; k < order.size() && order[k].s == sum; k++) {
            p[order[k].l] = order[k].r;
        }

        int x = 0;

        while (x + 1 <= n && p[x + 1] != 0) {
            curr = max(curr, p[x + 1] - (x + 1) + 1);

            x = p[x + 1];
        }

        if (x == n) result = min(result, curr);
    }

    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
