//
// Created by JongWoon on 2021-06-22.
//
// Link : https://www.acmicpc.net/problem/16202

#include <bits/stdc++.h>

using namespace std;

struct edge {
    int start;
    int end;
    int weight;

    bool operator<(const edge rhs) const {
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

#define SIZE (10000+2)
int N, M, K;
edge edges[SIZE];
bool visited[SIZE];

int calc_mst() {
    int ans = 0, selected_edges = 0, min_w = 987654321;
    dsu d(N+1);

    for (int i = 1; i <= M; i++) {
        if (!visited[edges[i].weight] && d.connect(edges[i].start, edges[i].end)) {
            selected_edges++;
            if (min_w > edges[i].weight) {
                visited[edges[i].weight] = true;
                min_w = edges[i].weight;
            }
            ans += edges[i].weight;
        }
    }

    return (selected_edges == N-1) ? ans : 0;
}

void end_game(int k) {
    for(int i = k; i <= K; i++) cout << 0 << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> K;

    for(int i = 1; i <= M; i++) {
        cin >> edges[i].start >> edges[i].end;
        edges[i].weight = i;
    }

    sort(edges + 1, edges + 1 + M);

    int ans = calc_mst();
    if (ans == 0) {
        end_game(1);
        return 0;
    }

    cout << ans << ' ';

    for(int k = 2; k <= K; k++) {
        ans = calc_mst();
        if (ans == 0) {
            end_game(k);
            return 0;
        }
        cout << ans << ' ';
    }

    return 0;
}



