//
// Created by JongWoon on 2021-06-22.
//
// Link : https://www.acmicpc.net/problem/1197

#include <bits/stdc++.h>

using namespace std;

struct edge {
    int start;
    int end;
    int weight;

    bool operator<(const edge rhs) {
        return weight < rhs.weight;
    }
};

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


#define SIZE (100000)
int V, E;
edge edges[SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> V >> E;

    dsu d(V+1);
    int ans = 0;

    for(int i = 1; i <= E; i++)
        cin >> edges[i].start >> edges[i].end >> edges[i].weight;

    sort(edges + 1, edges + 1 + E);

    for(int i = 1; i <= E; i++)
        if (d.connect(edges[i].start, edges[i].end))
            ans += edges[i].weight;

    cout << ans;
    return 0;
}

