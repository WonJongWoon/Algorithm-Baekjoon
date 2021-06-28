//
// Created by JongWoon on 2021-06-28.
//
// Link : https://www.acmicpc.net/problem/1753

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

#define SIZE (20000+2)
#define x first
#define y second
#define INF int(1e9)

int V, E, S;
int d[SIZE];

priority_queue<pii, vector<pii>, greater<>> q;
vector<pii> g[SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> V >> E;
    cin >> S;

    for(int i = 1; i <= E; i++) {
        int s, e, w;
        cin >> s >> e>> w;
        g[s].emplace_back(e, w);
    }

    for (int i = 1; i <= V; i++) d[i] = INF;
    q.emplace(0, S);
    d[S] = 0;

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

    for(int i = 1; i <= V; i++) {
        if (d[i] == INF) cout << "INF\n";
        else cout << d[i] << '\n';
    }

    return 0;
}