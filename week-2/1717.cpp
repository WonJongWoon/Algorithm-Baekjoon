//
// Created by JongWoon on 2021-05-26.
//
// Link : https://www.acmicpc.net/problem/1717

#include <bits/stdc++.h>

using namespace std;

struct dsu {
    vector<int> parent;

    dsu(int N) : parent(N, 0) { iota(parent.begin(), parent.end(), 0);}
    int find(int x) { return (parent[x] == x) ? x : (parent[x] = find(parent[x])); }
    bool connect(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        parent[y] = x;
        return true;
    }
};

int N, M;
int op, a, b;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    dsu d(N+1);

    while(M--) {
        cin >> op >> a >> b;
        if (op == 0) d.connect(a, b);
        else cout << (d.find(a) == d.find(b) ? "YES\n" : "NO\n");
    }
    return 0;
}
