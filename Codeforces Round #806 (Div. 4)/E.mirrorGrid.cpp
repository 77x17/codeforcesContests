#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;


int n;  vector<string> arr;  vector<vector<int>> cnt;

void Input() {
    cin >> n;  arr.assign(n + 1, "");

    for (int i = 1; i <= n; i++) {cin >> arr[i];  arr[i] = ' ' + arr[i];}
}


void Rotate(vector<string>& a) {
    for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) swap(a[i][j], a[j][i]);

    for (int i = 1; i <= n; i++) for (int j = 1, k = n; j <= k; j++, k--) swap(a[j][i], a[k][i]);
}

void Process() {
    int result = 0;

    cnt.assign(n + 1, vector<int> (n + 1, 0));

    vector<string> temp = arr;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cnt[i][j] += temp[i][j] == '1';

    Rotate(temp);

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cnt[i][j] += temp[i][j] == '1';

    Rotate(temp);

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cnt[i][j] += temp[i][j] == '1';

    Rotate(temp);

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cnt[i][j] += temp[i][j] == '1';

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (cnt[i][j] >= 2) temp[i][j] = '1'; else temp[i][j] = '0';

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (arr[i][j] != temp[i][j]) result++;

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
