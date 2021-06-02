//
// Created by JongWoon on 2021-06-02.
//
// Link : https://www.acmicpc.net/problem/14651

#include <bits/stdc++.h>

using namespace std;

#define SIZE (33333+2)
#define MOD int(1e9+9)
int N;
long long dp[SIZE][3];

long long mod_value(long long a, long long b, long long mod) {
    return ((a % MOD) + (b % MOD)) % mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    dp[1][0] = dp[1][1] = dp[1][2] = 1;

    cin >> N;

    for(int i = 2; i < N; i++) {
        long long v = mod_value(mod_value(dp[i-1][0], dp[i-1][1], MOD), dp[i-1][2], MOD);
        dp[i][0] = dp[i][1] = dp[i][2] = v;
    }

    long long ans = mod_value(dp[N-1][2], dp[N-1][1], MOD);
    cout << ans << '\n';
    return 0;
}
