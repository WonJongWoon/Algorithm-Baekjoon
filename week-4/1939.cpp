//
// Created by JongWoon on 2021-06-28.
//
// Link : https://www.acmicpc.net/problem/1939

#include <bits/stdc++.h>

using namespace std;

#define SIZE (100'000+2)
#define INF (1e9+1)

struct dsu {
    vector<int> parent;

    explicit dsu(int n) : parent(n, 0) { iota(parent.begin(), parent.end(), 0);}
    int find(int x) { return (parent[x] == x) ? x : (parent[x] = find(parent[x])); }
    bool connect(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        parent[y] = x;
        return true;
    }
};

struct edge {
    int start;
    int end;
    int weight;
    edge() {}
    edge(int s, int e, int w) : start(s), end(e), weight(w) {}
    bool operator<(const edge rhs) const {
        return weight < rhs.weight;
    }
};

int N, M, si, ei;

edge edges[SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for(int i = 1; i <= M; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        edges[i].start = s; edges[i].end = e; edges[i].weight = w;
    }

    cin >> si >> ei;

    sort(edges + 1, edges + 1 + M);
    reverse(edges + 1, edges + 1 + M);
    dsu d(N+1);

    for(int i = 1; i <= M; i++) {
        edge cur = edges[i];
        d.connect(cur.start, cur.end);
        if (d.find(si) == d.find(ei)) {
            cout << cur.weight;
            return 0;
        }
    }
    return 0;
}