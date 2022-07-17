#include <bits/stdc++.h>

using namespace std;


int n;  string s;

void Input() {
    cin >> n >> s;
}


void Process() {
    int cnt[26], result = 0;

    memset(cnt, 0, sizeof cnt);

    for (char e : s) {
        if (cnt[e - 'A'] == 0) result += 2, cnt[e - 'A']++;
        else result++;
    }

    cout << result << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (fopen("Task.inp", "r")) freopen("Task.inp", "r", stdin), freopen("Task.out", "w", stdout);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
