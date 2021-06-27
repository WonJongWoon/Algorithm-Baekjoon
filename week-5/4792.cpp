//
// Created by JongWoon on 2021-06-27.
//
// Link : https://www.acmicpc.net/problem/4792

#include <bits/stdc++.h>

using namespace std;

#define RED 0
#define BLUE 1

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
    int color; // R : 0, B : 1

    edge(int s, int e, int c) : start(s), end(e), color(c) {}
};

int N, M, K;
int c[2][2] = { {1, 2}, {2, 1} };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while(true) {
        cin >> N >> M >> K;

        if (N == 0 && M == 0 && K == 0) break;

        vector<edge> edges;

        for(int i = 1; i <= M; i++) {
            int start, end;
            char color;
            cin >> color >> start >> end;
            edges.emplace_back(start, end, color == 'B' ? BLUE : RED);
        }

        // k = 0 R이 최대한 많이, B가 최대한 적게, ans[0] : B가 최대한 적은 경우
        // k = 1 R이 최대한 적게, B가 최대한 많이, ans[1] : B가 최대한 많은 경우

        int ans[2] = { 0, 0 };

        for(int k = 0; k < 2; k++) {
            dsu d(N+1);
            sort(edges.begin(), edges.end(), [c, k](const edge lhs, const edge rhs) -> bool {
                return c[k][lhs.color] < c[k][rhs.color];
            });
            int connected = 0, num_of_blue = 0;
            for(int i = 0; i < (int)edges.size(); i++) {
                if (d.connect(edges[i].start, edges[i].end)) {
                    connected++;
                    if (edges[i].color == BLUE) num_of_blue++;
                }
            }
            if (N-1 == connected) ans[k] = num_of_blue;
        }

        if (K >= ans[0] && K <= ans[1]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}
