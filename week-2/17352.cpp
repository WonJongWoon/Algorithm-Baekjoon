//
// Created by JongWoon on 2021-05-27.
//
// Link : https://www.acmicpc.net/problem/17352

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

int N;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    dsu d(N+1);

    for(int i = 0, f, s; i < N - 2; i++) {
        cin >> f >> s;
        d.connect(f, s);
    }

    for(int i = 1, cnt = 0; i <= N; i++) if (d.parent[i] == i && cnt++ < 2) cout << i << ' ';
    return 0;
}
