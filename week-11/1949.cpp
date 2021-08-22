//
// Created by JongWoon on 2021-08-22.
//
// Link : https://www.acmicpc.net/problem/1949

#include <bits/stdc++.h>

using namespace std;

const int SIZE = 10000+2;
int N;

bool visited[SIZE];
vector<int> t[SIZE];
int weight[SIZE];
int dp[SIZE][2];

void dp_dfs(int x) {
    for(int child : t[x]) {
        if (visited[child]) continue;
        visited[child] = true;
        dp_dfs(child);
        dp[x][0] += max(dp[child][0], dp[child][1]);
        dp[x][1] += dp[child][0];
    }

    dp[x][1] += weight[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++) cin >> weight[i];

    for(int i = 1; i < N; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        t[v1].emplace_back(v2);
        t[v2].emplace_back(v1);
    }

    // dp[x][0] = k for x child max(dp[k][0], dp[k][1])
    // dp[x][1] = k for x child sum(dp[k][0]) + weight[x]

    visited[1] = true;
    dp_dfs(1);
    cout << max(dp[1][0], dp[1][1]);

    return 0;
}
