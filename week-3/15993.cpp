//
// Created by JongWoon on 2021-06-27.
//
// Link : https://www.acmicpc.net/problem/15993

#include <bits/stdc++.h>

using namespace std;

#define SIZE (1'00'000+2)
#define MOD 1'000'000'009

int T;
long long dp[SIZE][2];

long long get_dp(int k, int flag) {
    if (k < 0) return 0;
    return dp[k][flag];
}

long long mod_value(long long a, long long b, long long mod) {
    return ((a % mod) + (b % mod)) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> T;
    dp[0][0] = 1;

    for (int k = 1; k <= 100'000; k++) {
        dp[k][0] = mod_value(mod_value(get_dp(k - 1, 1), get_dp(k - 2, 1), MOD), get_dp(k - 3, 1), MOD); // 짝수 : 홀수 + 1
        dp[k][1] = mod_value(mod_value(get_dp(k - 1, 0), get_dp(k - 2, 0), MOD), get_dp(k - 3, 0), MOD); // 홀수 : 짝수 + 1
    }

    int n;
    while (T--) {
        cin >> n;
        cout << dp[n][1] << ' ' << dp[n][0] << '\n';
    }
    return 0;
}