//
// Created by JongWoon on 2021-07-17.
//
// Link : https://www.acmicpc.net/problem/1865

#include <bits/stdc++.h>

using namespace std;

int T, N, M, W;

const int INF = 987654321;
const int MAX_E = 2500+2;
const int MAX_V = 500+2;
int a[MAX_E], b[MAX_E];

int w[MAX_V][MAX_V];

long long d[MAX_V];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    while(T--) {
        cin >> N >> M >> W;

        fill_n(&w[0][0], MAX_V * MAX_V, INF);

        for(int i = 1; i <= M; i++) {
            int s, e, weight;
            cin >> s >> e >> weight;
            w[s][e] = w[e][s] = min(w[e][s], weight);
        }

        for(int i = 1; i <= W; i++) {
            int s, e, weight;
            cin >> s >> e >> weight;
            w[s][e] = -weight;
        }

        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                    w[i][j] = min(w[i][j], w[i][k] + w[k][j]);


        bool is_possible = false;
        for(int i = 1; i <= N; i++) {
            if (w[i][i] < 0) {
                is_possible = true;
                break;
            }
        }

        cout << (is_possible ? "YES\n" : "NO\n");
    }

    return 0;
}
