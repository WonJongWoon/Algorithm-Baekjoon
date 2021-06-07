//
// Created by JongWoon on 2021-06-07.
//
// Link : https://www.acmicpc.net/problem/14496

#include <bits/stdc++.h>

using namespace std;

#define SIZE (1000+2)

int a, b, N, M;

int g[SIZE][SIZE];
int visited[SIZE];

int bfs() {

    queue<int> q;

    visited[a] = 1;
    q.emplace(a);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int k = 1; k <= N; k++) {
            if (g[cur][k] && visited[k] == 0) {
                visited[k] = visited[cur] + 1;
                q.emplace(k);
            }
        }
    }

    return visited[b] == 0 ? - 1 : visited[b] - 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> a >> b;
    cin >> N >> M;

    for (int _ = 0; _ < M; ++_) {
        int f, s;
        cin >> f >> s;
        g[f][s] = g[s][f] = 1;
    }

    cout << bfs();
    return 0;
}

