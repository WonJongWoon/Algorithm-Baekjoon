//
// Created by jongwoon on 21. 7. 24..
//
// Link : https://www.acmicpc.net/problem/1167

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int SIZE = 100000+2;
vector<pii> g[SIZE];
int N;
bool visited[SIZE];
int max_cost = -1;
int far_node;

void dfs(int start, int cost) {
    if (visited[start]) return;
    visited[start] = true;

    if (max_cost < cost) {
        far_node = start;
        max_cost = cost;
    }

    for(pii edge : g[start]) {
        dfs(edge.first, cost + edge.second);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        int parent, child, cost;
        cin >> parent;

        while(true) {
            cin >> child;
            if (child == -1) break;
            cin >> cost;
            g[parent].emplace_back(child, cost);
            g[child].emplace_back(parent, cost);
        }
    }

    dfs(1, 0);
    fill(visited + 1 , visited + 1 + N, false);

    dfs(far_node, 0);
    cout << max_cost;

    return 0;
}