//
// Created by JongWoon on 2021-07-30.
//
// Link : https://www.acmicpc.net/problem/2410

#include <bits/stdc++.h>

using namespace std;

const int SIZE = int(1e6+2);
const int MOD = int(1e9);

int dp[SIZE][20];
int N;

inline int sum(int x, int y, int mod) { return (x+(long long)y) % mod; }
inline int mul(int x, int y, int mod) { return (x*(long long)y) % mod; }
inline int sub(int x, int y, int mod) { return sum(x, mod-y, mod); }

int pow2(int k) {
    return (1 << k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for(int i = 0; i < 20; i++) dp[0][i] = 1;

    for(int i = 1; i <= N; i++) {
        dp[i][0] = 1;
        for(int j = 1; j < 20; j++) {
            if (i >= pow2(j)) {
                dp[i][j] = sum(dp[i][j-1], dp[i - pow2(j)][j], MOD);
            } else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    cout << dp[N][19];

    return 0;
}
