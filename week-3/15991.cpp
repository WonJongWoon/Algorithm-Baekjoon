//
// Created by JongWoon on 2021-06-27.
//
// Link : https://www.acmicpc.net/problem/15991

#include <bits/stdc++.h>

using namespace std;

#define SIZE (100'000+2)
#define MOD 1'000'000'009

int T;
long long dp[SIZE];

long long mod_value(long long a, long long b, long long mod) {
    return ((a % mod) + (b % mod)) % mod;
}

long long get_dp(int k) {
    if (k < 0) return 0;
    else if (k == 0) return 1;
    return dp[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    cin >> T;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;

    for(int k = 4; k <= 100'000; k++) {
        dp[k] = mod_value(mod_value(get_dp(k-2), get_dp(k-4), MOD), get_dp(k - 6), MOD);
    }

    int n;
    while(T--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}