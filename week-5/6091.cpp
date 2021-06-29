//
// Created by JongWoon on 2021-06-28.
//
// Link : https://www.acmicpc.net/problem/6091

#include <bits/stdc++.h>

using namespace std;

#define SIZE (1024+2)
#define INF (987654321)

int N;

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
    edge(int s, int e, int w) : start(s), end(e), weight(w) {}
    bool operator<(const edge rhs) const {
        return weight < rhs.weight;
    }
};

vector<edge> edges;
vector<int> g[SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for(int i = 1; i <= N-1; i++) {
        for(int j = 1, weight; j <= N-i; j++) {
            cin >> weight;
            edges.emplace_back(i, i + j, weight);
        }
    }

    sort(edges.begin(), edges.end());
    dsu d(N+1);
    int connected = 0;

    for(auto cur : edges) {
        int start = cur.start, end = cur.end;
        if (d.connect(start, end)) {
            g[start].emplace_back(end);
            g[end].emplace_back(start);
            connected++;
        }
        if(connected == N - 1) break;
    }

    for(int i = 1; i <= N; i++) {
        cout << g[i].size() << ' ';
        sort(g[i].begin(), g[i].end());
        for(int edge : g[i]) cout << edge << ' ';
        cout << '\n';
    }

    return 0;
}