//
// Created by JongWoon on 2021-06-10.
//
// Link : https://www.acmicpc.net/problem/11725

#include <bits/stdc++.h>

using namespace std;

#define SIZE (100000+2)

int N;
vector<vector<int>> g;
bool visited[SIZE];
int parent[SIZE];

void bfs(int start) {

    queue<int> q;
    q.emplace(start);
    visited[start] = true;

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int node : g[cur]) {
            if (!visited[node]) {
                parent[node] = cur;
                visited[node] = true;
                q.emplace(node);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    g.resize(N+1);

    for (int _ = 0, se, ee; _ < N-1; ++_) {
        cin >> se >> ee;
        g[se].emplace_back(ee);
        g[ee].emplace_back(se);
    }

    bfs(1);

    for (int i = 2; i <= N; ++i) {
        cout << parent[i] << '\n';
    }
    return 0;
}