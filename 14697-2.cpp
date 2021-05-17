//
// Created by JongWoon on 2021-05-17.
//
// Link : https://www.acmicpc.net/problem/14697


#include <bits/stdc++.h>

using namespace std;

#define SIZE (300+2)
bool dp[SIZE];

bool get_dp(int n) {
    if (n < 0) return false;
    return dp[n];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C, N;
    cin >> A >> B >> C >> N;

    dp[0] = true;
    for(int i = 1; i <= N; i++) {
        dp[i] = get_dp(i - A) || get_dp(i - B) || get_dp(i - C);
    }
    cout << dp[N] << "\n";

    return 0;
}
