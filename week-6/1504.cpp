//
// Created by JongWoon on 2021-07-01.
//
// Link : https://www.acmicpc.net/problem/1504

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

#define SIZE (800+2)
#define x first
#define y second
#define INF (1e8)

int N, E, v1, v2;

vector<pii> g[SIZE];

vector<int> dijkstra(int s) {
    vector<int> d(N+1, INF);
    priority_queue<pii, vector<pii>, greater<>> q;

    q.emplace(0, s);
    d[s] = 0;

    while (!q.empty()) {
        pii cur = q.top(); q.pop();
        int now_d = cur.x, now = cur.y;
        if (d[now] != now_d) continue;

        for (pii next : g[now]) {
            int nxt = next.x, nxt_d = now_d + next.y;
            if (nxt_d < d[nxt]) {
                d[nxt] = nxt_d;
                q.emplace(nxt_d, nxt);
            }
        }
    }

    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> E;

    for(int i = 1, s, e, w; i <= E; i++) {
        cin >> s >> e >> w;
        g[s].emplace_back(e, w);
        g[e].emplace_back(s, w);
    }

    cin >> v1 >> v2;

    vector<int> d1 = dijkstra(1);
    vector<int> d2 = dijkstra(v1);
    vector<int> d3 = dijkstra(v2);

    int first = d1[v1] + d2[v2] + d3[N]; // 1 -> v1 + v1 -> v2 + v2 -> N
    int second = d1[v2] + d3[v1] + d2[N]; // 1 -> v2 + v2 -> v1 + v1 -> N
    int ret = min(first, second);
    cout << (ret >= INF ? -1 : ret);

    return 0;
}
