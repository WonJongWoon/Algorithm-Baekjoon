//
// Created by JongWoon on 2021-06-27.
//
// Link : https://www.acmicpc.net/problem/15988

#include <bits/stdc++.h>

using namespace std;

#define SIZE (1'000'000+2)
#define MOD 1'000'000'009

int T;
long long dp[SIZE];

long long get_dp(int k) {
    if (k < 0) return 0;
    return dp[k];
}

long long mod_value(long long a, long long b, long long mod) {
    return ((a % mod) + (b % mod)) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    cin >> T;
    dp[0] = dp[1] = 1;

    for(int k = 2; k <= 1'000'000; k++) {
        dp[k] = mod_value(mod_value(get_dp(k - 1), get_dp(k - 2), MOD), get_dp(k - 3), MOD);
    }

    int n;
    while(T--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}