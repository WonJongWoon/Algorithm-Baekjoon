//
// Created by JongWoon on 2021-06-07.
//
// Link : https://www.acmicpc.net/problem/9095

#include <bits/stdc++.h>

using namespace std;

#define SIZE (10+2)

int T;
int dp[SIZE];

int get_dp(int k) {
    if (k < 0) return 0;
    else if (k == 0) return 1;
    return dp[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    cin >> T;
    dp[1] = 1;

    for(int k = 2; k <= 10; k++) {
        dp[k] = get_dp(k-1) + get_dp(k-2) + get_dp(k - 3);
    }

    int n;
    while(T--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}