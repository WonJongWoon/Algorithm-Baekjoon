//
// Created by JongWoon on 2021-07-02.
//
// Link : https://www.acmicpc.net/problem/11779

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

#define SIZE (1000+1)
#define INF (1e8)
#define x first
#define y second

priority_queue<pii, vector<pii>, greater<>> q;
vector<pii> g[SIZE];

int path[SIZE];
int d[SIZE];
int N, M;
int start_city, end_city;
int num_of_cities;
int ans[SIZE];

void travel(int city) {
    if (!path[city]) {
        ans[++num_of_cities] = city;
        return;
    }
    travel(path[city]);
    ans[++num_of_cities] = city;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    cin >> M;

    for(int i = 1; i <= M; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        g[v1].emplace_back(v2, w);
    }

    cin >> start_city >> end_city;

    fill(d, d + SIZE, INF);
    d[start_city] = 0;
    q.emplace(0, start_city);

    while(!q.empty()) {
        pii cur = q.top(); q.pop();
        int now_d = cur.x, now_v = cur.y;
        if (d[now_v] != now_d) continue;

        for(pii v : g[now_v]) {
            int next_v = v.x; int next_d = v.y;
            int cost = now_d + next_d;
            if(cost < d[next_v]) {
                d[next_v] = cost;
                path[next_v] = now_v;
                q.emplace(cost, next_v);
            }
        }
    }

    cout << d[end_city] << '\n';
    travel(end_city);
    cout << num_of_cities << '\n';
    for(int i = 1; i <= num_of_cities; i++) cout << ans[i] << ' ';

    return 0;
}
