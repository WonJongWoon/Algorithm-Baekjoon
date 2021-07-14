//
// Created by JongWoon on 2021-07-14.
//
// Link : https://www.acmicpc.net/problem/17940

#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

#define INF (987654321)
#define SIZE (1000+2)
#define x first
#define y second
#define BASE int(1e6)

int N, M;

int v[SIZE]; // 정점 i의 회사 : v[i], v[i] = 0 or 1
int weight;
vector<pii> g[SIZE];

vector<int> dijkstra(int s) {
    vector<int> d(N, INF);
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

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> weight;
            if (weight != 0) {
                g[i].emplace_back(j, weight + (v[i] != v[j] ? BASE : 0));
            }
        }
    }

    vector<int> d = dijkstra(0);
    int change = d[M] / BASE;
    int distance = d[M] % BASE;

    cout << change << " " << distance;
    return 0;
}