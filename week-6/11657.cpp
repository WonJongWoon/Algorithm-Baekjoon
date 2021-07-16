//
// Created by JongWoon on 2021-07-16.
//
// Link : https://www.acmicpc.net/problem/11657

#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 500+2;
const int MAX_E = 6000+2;
const int INF = 987654321;

int N, M;

int a[MAX_E], b[MAX_E], w[MAX_E];
long long d[MAX_V];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        cin >> a[i] >> b[i] >> w[i];
    }

    fill(d, d + MAX_V, INF);
    d[1] = 0;

    for(int _ = 1; _ <= N-1; _++) {
        for(int j = 1; j <= M; j++) {
            if (d[a[j]] != INF && d[a[j]] + w[j] < d[b[j]]) {
                d[b[j]] = d[a[j]] + w[j];
            }
        }
    }

    bool is_negative_cycle = false;
    for(int j = 1; j <= M; j++) {
        if (d[a[j]] != INF && d[a[j]] + w[j] < d[b[j]]) {
            is_negative_cycle = true;
            break;
        }
    }

    if (is_negative_cycle) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 2; i <= N; i++) {
        cout << (d[i] == INF ? -1 : d[i]) << '\n';
    }

    return 0;
}