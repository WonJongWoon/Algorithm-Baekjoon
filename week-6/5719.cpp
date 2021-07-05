//
// Created by JongWoon on 2021-07-05.
//
// Link : https://www.acmicpc.net/problem/5719

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

#define SIZE (500+2)
#define INF (1e9)
#define x first
#define y second

int N, M, S, D;
int s, e, w;

bool except[SIZE][SIZE];
int d[SIZE][SIZE];
int weight[SIZE][SIZE];

int dis[SIZE];
priority_queue<pii, vector<pii>, greater<>> q;

int dijkstra(vector<pii>* graph, int V, int src, int dst) {

    fill(dis, dis + SIZE, INF);
    dis[src] = 0;
    q.emplace(0, src);

    while (!q.empty()) {
        pii cur = q.top(); q.pop();
        int now_d = cur.x, now = cur.y;
        if (dis[now] != now_d) continue;

        for (pii next : graph[now]) {
            int nxt = next.x, nxt_d = now_d + next.y;
            if (nxt_d < dis[nxt] && !except[now][nxt]) {
                dis[nxt] = nxt_d;
                q.emplace(nxt_d, nxt);
            }
        }
    }

    return dis[dst] >= INF ? (-1) : dis[dst];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while(true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        vector<pii> g[SIZE];

        cin >> S >> D;

        fill_n(&d[0][0], SIZE * SIZE, INF);
        for(int i = 1; i <= N; i++) d[i][i] = 0;

        for(int i = 1; i <= M; i++) {
            cin >> s >> e >> w;
            weight[s+1][e+1] = d[s+1][e+1] = w;
            g[s+1].emplace_back(e+1, w);
        }

        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

        fill_n(&except[0][0], SIZE * SIZE, false);
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if (weight[i][j] != 0 && d[S+1][i] + weight[i][j] + d[j][D+1] == d[S+1][D+1]) {
                    except[i][j] = true;
                }
            }
        }

        int ans = dijkstra(g, N, S + 1, D + 1);
        cout << ans << '\n';
    }
    return 0;
}