//
// Created by JongWoon on 2021-06-07.
//
// Link : https://www.acmicpc.net/problem/1260

#include <bits/stdc++.h>

using namespace std;

#define SIZE (1000+2)

int N, M, V;
int g[SIZE][SIZE];
int visited[SIZE];

void bfs(int se) {
    queue<int> q;

    cout << se << ' ';
    visited[se] = true;
    q.emplace(se);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int next = 1; next <= N; ++next) {
            if (g[cur][next] && !visited[next]) {
                cout << next << ' ';
                visited[next] = true;
                q.emplace(next);
            }
        }
    }
}

void dfs(int se) {
    visited[se] = true;
    cout << se << ' ';

    for(int next = 1; next <= N; ++next) {
        if(g[se][next] && !visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> V;
    while(M--) {
        int se, ee;
        cin >> se >> ee;
        g[se][ee] = g[ee][se] = 1;
    }

    fill(visited + 1, visited + 1 + N, 0);
    dfs(V);
    cout << '\n';

    fill(visited + 1, visited + 1 + N, 0);
    bfs(V);
    cout << '\n';
    return 0;
}
