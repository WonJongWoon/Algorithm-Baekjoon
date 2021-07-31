//
// Created by JongWoon on 2021-07-31.
//
// Link : https://www.acmicpc.net/problem/2410

#include <bits/stdc++.h>

using namespace std;

inline int sum(int x, int y, int mod) { return (x+(long long)y) % mod; }
inline int mul(int x, int y, int mod) { return (x*(long long)y) % mod; }
inline int sub(int x, int y, int mod) { return sum(x, mod-y, mod); }

const int SIZE = int(1e6) + 2;
const int MOD = int(1e9);

int N;
int dp[SIZE][20];

int pow2(int k) {
    return (1 << k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for(int i = 0; i <= N; i++) dp[i][0] = 1;

    for(int i = 1; i <= N; i++) {
        for(int k = 1; k < 20; k++) {
            if (i >= pow2(k)) {
                for(int j = 0; j <= k; j++) {
                    dp[i][k] = sum(dp[i][k], dp[i-pow2(k)][j], MOD);
                }
            } else {
                dp[i][k] = 0;
            }
        }
    }

    int ans = 0;
    for(int k = 0; k < 20; k++) {
        ans = sum(ans, dp[N][k], MOD);
    }
    cout << ans;
    return 0;
}