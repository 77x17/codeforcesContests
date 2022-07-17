#include <bits/stdc++.h>

using namespace std;


int n, c, q;  string arr;

struct queries {
    long long l, r, s;
};

vector<queries> order;

void Input() {
    cin >> n >> c >> q >> arr;

    long long sum = n;  order.push_back({1, n, sum});

    while (c--) {
        long long l, r; cin >> l >> r;  order.push_back({l, r, sum + (r - l + 1)});

        sum += (r - l + 1);
    }
}


void Backtrack(long long k) {
    if (k <= n) {
        cout << arr[k - 1] << '\n';
    } else {
        for (int i = order.size() - 1; i >= 1; i--) if (k > order[i - 1].s) {
            Backtrack(k - order[i - 1].s + order[i].l - 1);

            break;
        }
    }
}

void Process() {
    while (q--) {
        long long k; cin >> k;

        Backtrack(k);
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
