#include <bits/stdc++.h>
using namespace std;


int p; string s;

void Input() {
    cin >> s >> p;
}


void Process() {
    vector<int> eraseOrder;

    multiset<pair<char, int>> order;

    int price = 0;

    int i = 0;
    for (char e : s) order.insert({e, i++}), price += e - 'a' + 1;

    while (price > p) {
        pair<char, int> temp = *order.rbegin();

        eraseOrder.push_back(temp.second);

        price -= temp.first - 'a' + 1; order.erase(--order.end());
    }

    sort(eraseOrder.begin(), eraseOrder.end(), greater<int>());

    for (int e : eraseOrder) s.erase(e, 1);

    cout << s << '\n';
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
