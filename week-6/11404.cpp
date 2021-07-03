//
// Created by JongWoon on 2021-07-03.
//
// Link : https://www.acmicpc.net/problem/11404

#include <bits/stdc++.h>

using namespace std;

#define SIZE (100+2)
#define INF (1e9)

int N, M;
int w[SIZE][SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    cin >> M;

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

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << (w[i][j] == INF ? 0 : w[i][j]) << ' ';
        }
        cout << '\n';
    }

    return 0;
}
