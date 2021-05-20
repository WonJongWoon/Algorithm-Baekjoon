//
// Created by JongWoon on 2021-05-19.
//
// Link : https://www.acmicpc.net/problem/20500

#include <bits/stdc++.h>

using namespace std;

#define SIZE (1515+2)
#define MOD (1'000'000'007)

int N;
long long dp[SIZE][3];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    dp[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
    }

    cout << (dp[N][0] % MOD) << "\n";
    return 0;
}