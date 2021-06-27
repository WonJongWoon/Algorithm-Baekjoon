//
// Created by JongWoon on 2021-06-27.
//
// Link : https://www.acmicpc.net/problem/16195

#include <bits/stdc++.h>

using namespace std;

#define SIZE (1000+2)
#define MOD 1'000'000'009

int T;
long long dp[SIZE][SIZE];

long long get_dp(int k, int m) {
    if (k < 0 || m < 0) return 0;
    if (k == 0) return 1;
    return dp[k][m];
}

long long mod_value(long long a, long long b, long long mod) {
    return ((a % mod) + (b % mod)) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    cin >> T;

    for(int k = 1; k <= 1000; k++) {
        for(int m = 1; m <= 1000; m++) {
            dp[k][m] = mod_value(mod_value(get_dp(k - 1, m - 1), get_dp(k - 2, m - 1), MOD), get_dp(k - 3, m - 1), MOD);
        }
    }

    int n, m;
    while(T--) {
        cin >> n >> m;
        cout << dp[n][m] << '\n';
    }
    return 0;
}