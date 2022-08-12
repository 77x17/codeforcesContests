#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 77 * 17;


int n;

void Input() {
    cin >> n;
}


vector<int> result;

inline bool Good(const int& x) {
    return (int)sqrt(x) * (int)sqrt(x) == x;
}

bool Find(int x) {
    for (int i = 0; i < x; i++) {
        if (Good(x - 1 + i)) {
            for (int j = 0; i + j < x; j++) result[i + j] = x - j - 1;

            if (i) return Find(i);

            return true;
        }
    }

    return false;
}

void Process() {
    result.assign(n, 0);

    if (not Find(n)) cout << -1 << '\n';
    else for (int i = 0; i < n; i++) cout << result[i] << " \n"[i == n - 1];
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
