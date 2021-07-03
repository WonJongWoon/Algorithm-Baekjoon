//
// Created by JongWoon on 2021-07-03.
//
// Link : https://www.acmicpc.net/problem/1238

#include <bits/stdc++.h>

#define SIZE (1000+2)
#define INF (1e8)

using namespace std;

int N, M, X;
int w[SIZE][SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> X;
    // N개 정점, M개 간선, X 정점에서 파티

    fill_n(&w[0][0], SIZE * SIZE, INF);
    for(int i = 1; i <= N; i++) w[i][i] = 0;

    for(int i = 1; i <= M; i++) {
        int s, e, cost;
        cin >> s >> e >> cost;
        w[s][e] = min(w[s][e], cost);
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);

    int ans = -1;
    for(int i = 1; i <= N; i++) {
        ans = max(ans, w[i][X] + w[X][i]);
    }

    cout << ans;
    return 0;
}
