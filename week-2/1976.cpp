//
// Created by JongWoon on 2021-05-27.
//
// Link : https://www.acmicpc.net/problem/1976

#include <bits/stdc++.h>

#define SIZE (1000+2)

using namespace std;

struct dsu {
    vector<int> parent;

    dsu(int N) : parent(N, 0) { iota(parent.begin(), parent.end(), 0); }

    int find(int x) { return (parent[x] == x) ? x : (parent[x] = find(parent[x])); }

    bool connect(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        parent[y] = x;
        return true;
    }
};

int N, M;
int island[SIZE];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    dsu d(N + 1);

    for (int i = 1; i <= N; i++) {
        for (int j = 1, is_connected; j <= N; j++) {
            cin >> is_connected;
            if (is_connected) d.connect(i, j);
        }
    }

    bool is_impossible = true;
    for (int k = 0; k < M; k++) cin >> island[k];
    for (int k = 1; k < M; k++) if (is_impossible = (d.find(island[k]) != d.find(island[k - 1]))) break;
    cout << (is_impossible ? "NO\n" : "YES\n");

    return 0;
}
