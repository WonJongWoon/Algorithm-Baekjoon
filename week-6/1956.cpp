//
// Created by JongWoon on 2021-07-03.
//
// Link : https://www.acmicpc.net/problem/1956

#include <bits/stdc++.h>

#define SIZE (400+2)
#define INF (1e8)

using namespace std;

int V, E;
int w[SIZE][SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> V >> E;
    // V개 정점, E 간선

    fill_n(&w[0][0], SIZE * SIZE, INF);

    for(int i = 1; i <= E; i++) {
        int s, e, cost;
        cin >> s >> e >> cost;
        w[s][e] = min(w[s][e], cost);
    }

    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);

    int ans = INT32_MAX;
    for(int i = 1; i <= V; i++) {
        ans = min(ans, w[i][i]);
    }

    cout << (ans >= INF ? -1 : ans);

    return 0;
}

