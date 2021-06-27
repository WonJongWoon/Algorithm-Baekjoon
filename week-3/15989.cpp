//
// Created by JongWoon on 2021-06-27.
//
// Link : https://www.acmicpc.net/problem/15989

#include <bits/stdc++.h>

using namespace std;

#define SIZE (10000+2)

int T;
long long dp[SIZE][4];

long long get_dp(int k, int m) {
    if (k < 0 || k < m) return 0;
    return dp[k][m];
}

long long solve(int n) {
    return dp[n][1] + dp[n][2] + dp[n][3];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    cin >> T;
    dp[1][1] = 1;
    dp[2][1] = dp[2][2] = 1;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;

    for(int k = 4; k <= 10000; k++) {
        dp[k][1] = get_dp(k - 1, 1);
        dp[k][2] = get_dp(k - 2, 1) + get_dp(k - 2, 2);
        dp[k][3] = get_dp(k - 3, 1) + get_dp(k - 3, 2) + get_dp(k - 3, 3);
    }

    int n;
    while(T--) {
        cin >> n;
        cout << solve(n) << '\n';
    }
    return 0;
}