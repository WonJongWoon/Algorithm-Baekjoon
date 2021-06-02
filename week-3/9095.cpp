//
// Created by JongWoon on 2021-06-02.
//
// Link : https://www.acmicpc.net/problem/9095

#include <bits/stdc++.h>

using namespace std;

#define SIZE (10+2)

int T;
int dp[SIZE][SIZE];

int get_dp(int i, int k) {
    return k <= 0 ? 0 : dp[i][k];
}

int calc(int n) {
    int ret = 0;
    for(int k = 1; k <= 10; k++) ret += get_dp(k, n);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    cin >> T;
    dp[1][1] = dp[1][2] = dp[1][3] = 1;

    for(int i = 2; i <= 10; i++) {
        for(int k = 1; k <= 10; k++) {
            dp[i][k] = get_dp(i-1, k-1) + get_dp(i-1, k-2) + get_dp(i-1, k - 3);
        }
    }

    int n;
    while(T--) {
        cin >> n;
        cout << calc(n) << '\n';
    }
    return 0;
}
