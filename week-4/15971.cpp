//
// Created by JongWoon on 2021-06-24.
//
// Link : https://www.acmicpc.net/problem/15971

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

#define SIZE (100000+2)
int N, sr, er;

vector<pii> g[SIZE];
bool visited[SIZE];
int ans;

void dfs(int start, int total_cost, int max_cost) {
    if (visited[start]) return;
    visited[start] = true;

    if (start == er) {
        ans = total_cost - max_cost;
        return;
    }

    for(const pii p : g[start]) {
        dfs(p.first, total_cost + p.second, max(max_cost, p.second));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> sr >> er;

    for(int i = 1; i <= N-1; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        g[s].emplace_back(make_pair(e, w));
        g[e].emplace_back(make_pair(s, w));
    }

    dfs(sr, 0, 0);

    cout << ans;
    return 0;
}