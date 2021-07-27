//
// Created by JongWoon on 2021-07-27.
//
// Link : https://www.acmicpc.net/problem/13250

#include <bits/stdc++.h>

using namespace std;
const int SIZE = 1'000'000+2;
int N;

double dp[SIZE];

double get_dp(int x) {
    if (x <= 0) return 0;
    return dp[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        double ret = 0;
        for(int k = 1; k <= 6; k++) ret += get_dp(i-k);
        dp[i] = 1 + (ret / 6.0);
    }

    cout << fixed;
    cout.precision(11);
    cout << get_dp(N);

    return 0;
}
