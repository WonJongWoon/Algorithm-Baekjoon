//
// Created by JongWoon on 2021-07-14.
//
// Link : https://www.acmicpc.net/problem/17940

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

#define INF (987654321)
#define SIZE (1000+2)
#define x first
#define y second

int N, M;

int v[SIZE]; // 정점 i의 회사 : v[i], v[i] = 0 or 1
int weight;
vector<pii> g[SIZE];

vector<pii> dijkstra(int s) {
    vector<pii> d(N, { INF, INF });
    priority_queue<tiii, vector<tiii>, greater<>> q;

    q.emplace(0, 0, s); // x : 환승 횟수, y : 거리, z : 다음 정점
    d[s] = { 0, 0 }; // x : 거리, y : 환승 횟수

    while (!q.empty()) {
        tiii cur = q.top(); q.pop();
        int now_change, now_d, now_v;
        tie(now_change, now_d, now_v) = cur;

         if (d[now_v] != pii(now_d, now_change)) continue;

        for (pii next : g[now_v]) {
            int cost = next.y;
            int nxt_v = next.x, nxt_d = now_d + cost;
            int nxt_change = now_change + (v[now_v] != v[nxt_v] ? 1 : 0);

            if ((nxt_change < d[nxt_v].y) || (nxt_change == d[nxt_v].y && nxt_d < d[nxt_v].x)) {
                d[nxt_v] = pii(nxt_d, nxt_change);
                q.emplace(nxt_change, nxt_d, nxt_v);
            }
        }
    }

    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> weight;
            if (weight != 0) {
                g[i].emplace_back(j, weight);
            }
        }
    }


    vector<pii> ret = dijkstra(0);
    cout << ret[M].second << " " << ret[M].first;
    return 0;
}
