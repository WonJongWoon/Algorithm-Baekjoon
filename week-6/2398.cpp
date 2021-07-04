//
// Created by JongWoon on 2021-07-04.
//
// Link : https://www.acmicpc.net/problem/2398

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

#define SIZE (1000+2)
#define INF (1e8)
#define x first
#define y second

int N, M;
int v1, v2, v3;

vector<pii> g[SIZE];

struct dijkstra_result {
    vector<int> dis;
    vector<int> path;
    explicit dijkstra_result(int size) {
        dis.resize(size + 1);
        path.resize(size + 1);
    }
};

dijkstra_result dijkstra(vector<pii>* graph, int size, int src) {
    dijkstra_result result(size);

    vector<int> dis(N+1, INF);
    priority_queue<pii, vector<pii>, greater<>> q;

    q.emplace(0, src);
    for(int i = 1; i <= size; i++) result.dis[i] = INF;
    result.dis[src] = 0;

    while (!q.empty()) {
        pii cur = q.top(); q.pop();
        int now_d = cur.x, now = cur.y;
        if (result.dis[now] != now_d) continue;

        for (pii next : graph[now]) {
            int nxt = next.x, nxt_d = now_d + next.y;
            if (nxt_d < result.dis[nxt]) {
                result.dis[nxt] = nxt_d;
                result.path[nxt] = now;
                q.emplace(nxt_d, nxt);
            }
        }
    }

    return result;
}

vector<pii> travel(int v, vector<int>& path) {
    vector<pii> edges;
    int k;
    while((k = path[v]) != 0) {
        edges.emplace_back(v, k);
        v = k;
    }
    return edges;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for(int i = 1; i <= M; i++) {
        int s, e, cost;
        cin >> s >> e >> cost;
        g[s].emplace_back(e, cost);
        g[e].emplace_back(s, cost);
    }

    cin >> v1 >> v2 >> v3;

    dijkstra_result r1 = dijkstra(g, SIZE, v1);
    dijkstra_result r2 = dijkstra(g, SIZE, v2);
    dijkstra_result r3 = dijkstra(g, SIZE, v3);

    int ans = INT32_MAX;
    int middle = -1;
    for(int i = 1; i <= N; i++) {
        if (ans > r1.dis[i] + r2.dis[i] + r3.dis[i]) {
            ans = r1.dis[i] + r2.dis[i] + r3.dis[i];
            middle = i;
        }
    }

    vector<int> p1 = r1.path;
    vector<int> p2 = r2.path;
    vector<int> p3 = r3.path;

    vector<pii> e1 = travel(middle, p1);
    vector<pii> e2 = travel(middle, p2);
    vector<pii> e3 = travel(middle, p3);

    cout << ans <<  ' ' << (e1.size() + e2.size() + e3.size()) << '\n';

    for(const vector<pii>& edges : { e1, e2, e3 }) {
        for(pii edge : edges) {
            cout << edge.x << ' ' << edge.y << '\n';
        }
    }
    return 0;
}

