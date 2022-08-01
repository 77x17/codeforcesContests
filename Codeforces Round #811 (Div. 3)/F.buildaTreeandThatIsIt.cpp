#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

const int MAX_N = 77 * 17;


int n, d12, d23, d31;

void Input() {
    cin >> n >> d12 >> d23 >> d31;
}


int root;  vector<int> order;

void Calc(int curr, int x) {
    for (int i = 2; i <= x; i++) {
        cout << curr << ' ' << order.back() << '\n';

        curr = order.back(); order.pop_back();
    }

    if (curr != root) cout << curr << ' ' << root << '\n';
}

void Process() {
    int a, b, c;

//    a + b = d12;          a: 1 - root
//
//    b + c = d23;          b: 2 - root
//
//    a + c = d13;          c: 3 - root
//
//    a - c = d12 - d23;

    a = (d12 - d23 + d31);

    if (a & 1) {
        cout << "NO\n";

        return;
    } else a /= 2;

    b = d12 - a;

    c = d31 - a;

    if (a >= 0 && b >= 0 && c >= 0 && a + b + c + 1 <= n) {
        cout << "YES\n";

        root = 4;

        if (a == 0) root = 1;
        if (b == 0) root = 2;
        if (c == 0) root = 3;

        if (root != 4 && n >= 4) order.push_back(4);

        for (int i = 5; i <= n; i++) order.push_back(i);

        Calc(1, a);

        Calc(2, b);

        Calc(3, c);

        while (order.size()) {
            cout << order.back() << ' ' << root << '\n';

            order.pop_back();
        }
    } else cout << "NO\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}


