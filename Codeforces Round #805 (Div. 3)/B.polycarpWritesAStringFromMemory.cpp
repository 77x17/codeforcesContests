#include <bits/stdc++.h>
using namespace std;

const int MAX_C = 26 + 1;


string s;

void Input() {
    cin >> s;
}


int visited[MAX_C + 1];

void Process() {
    long long result = 0;

    memset(visited, 0, sizeof visited);

    int l = 0, r = 0, cnt = 0;

    while (l < s.size() && r < s.size()) {
        if (visited[s[r] - 'a'] == 0) {
            visited[s[r++] - 'a']++;

            if (cnt == 3) {
                l = r - 1;

                memset(visited, 0, sizeof visited);

                visited[s[l] - 'a']++;

                result++;

                cnt = 1;
            } else cnt++;
        } else visited[s[r++] - 'a']++;
    }

    cout << result + 1 << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();
        Process();
    }

    return 0;
}

