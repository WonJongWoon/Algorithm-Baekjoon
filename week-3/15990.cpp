//
// Created by JongWoon on 2021-06-07.
//
// Link : https://www.acmicpc.net/problem/15990

#include <bits/stdc++.h>

using namespace std;

#define SIZE (100000+2)
#define MOD 1'000'000'009

int T, n;
long long dp[SIZE][4];

long long get_dp(int i, int k) {
    if (i == k) return 1;
    if (i < k) return 0;
    return dp[i][k];
}

long long mod_value(long long a, long long b, long long mod) {
    return ((a % mod) + (b % mod)) % mod;
}

long long calc(int i, long long mod) {
    return mod_value(mod_value(dp[i][1], dp[i][2], mod), dp[i][3], mod);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

    for(int i = 4; i <= 100000; i++) {
        dp[i][1] = mod_value(get_dp(i-1, 2), get_dp(i-1, 3), MOD);
        dp[i][2] = mod_value(get_dp(i-2, 1), get_dp(i-2, 3), MOD);
        dp[i][3] = mod_value(get_dp(i-3, 1), get_dp(i-3, 2), MOD);
    }

    while(T--) {
        cin >> n;
        cout << calc(n, MOD) << '\n';
    }

    return 0;
}