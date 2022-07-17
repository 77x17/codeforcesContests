#include <bits/stdc++.h>

#define fi first

#define se second

using namespace std;


int n;  vector<pair<string, int>> arr;

void Input() {
    cin >> n;  arr.assign(n + 1, {"", 0});

    for (int i = 1; i <= n; i++) arr[i].se = i, cin >> arr[i].fi;
}


void Process() {
    map<string, int> cnt;

    vector<int> result(n + 1, 0);

    sort(arr.begin() + 1, arr.end(), [] (const pair<string, int>& x, const pair<string, int>& y) {return x.fi.size() < y.fi.size();});

    for (int i = 1; i <= n; i++) {
        string e = arr[i].fi;

        for (int j = 1; j < e.size(); j++) {
            string u = e.substr(0, j),  v = e.substr(0 + j, e.size() - j);

            if (cnt[u] && cnt[v]) result[arr[i].se] = 1;
        }

        cnt[arr[i].fi] = 1;
    }

    for (int i = 1; i <= n; i++) cout << result[i]; cout << '\n';
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
