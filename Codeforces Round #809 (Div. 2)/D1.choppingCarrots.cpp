#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;


int n, k;  vector<int> arr;

void Input() {
    cin >> n >> k;  arr.assign(n + 1, 0);  for (int i = 1; i <= n; i++) cin >> arr[i];
}


void Process() {
    int result = INF;

    for (int myMin = 1; myMin <= arr[1]; myMin++) {
        int myMax = 0;

        for (int i = 1; i <= n; i++) {
            int x = min(arr[i] / myMin, k);

            while (x >= 1 && arr[i] / x < myMin) x--;

            if (x == 0 || arr[i] / x < myMin) {
                myMax = INF;

                break;
            }

            myMax = max(myMax, arr[i] / x);
        }

        result = min(result, myMax - myMin);
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

