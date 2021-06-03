//
// Created by JongWoon on 2021-06-03.
//
// Link : https://www.acmicpc.net/problem/14494

#include <bits/stdc++.h>

using namespace std;

#define SIZE (1000+2)
#define MOD int(1e9+7)

int N, M;
long long dp[SIZE][SIZE];

long long mod_value(long long a, long long b, long long mod) {
    return ((a % mod) + (b % mod)) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 1; i <= N; i++) dp[i][1] = 1;
    for(int j = 1; j <= M; j++) dp[1][j] = 1;

    for(int i = 2; i <= N; i++) {
        for(int j = 2; j <= M; j++) {
            dp[i][j] = mod_value(mod_value(dp[i-1][j], dp[i][j-1], MOD), dp[i-1][j-1], MOD);
        }
    }

    cout << dp[N][M] << '\n';

    return 0;
}
