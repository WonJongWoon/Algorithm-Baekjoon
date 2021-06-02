//
// Created by JongWoon on 2021-06-02.
//
// Link : https://www.acmicpc.net/problem/14846

#include <bits/stdc++.h>

using namespace std;

#define SIZE (300+2)

int N, Q;
int arr[SIZE][SIZE];
int dp[SIZE][SIZE][10+1];

void calc_minus(int sx, int sy, int ex, int ey) {
    if (sx < 0 || sx >= N || sy < 0 || sy >= N) return;
    for(int k = 1; k <= 10; k++) dp[ex][ey][k] -= dp[sx][sy][k];
}

void calc_plus(int sx, int sy, int ex, int ey) {
    if (sx < 0 || sx >= N || sy < 0 || sy >= N) return;
    for(int k = 1; k <= 10; k++) dp[ex][ey][k] += dp[sx][sy][k];
}

int count(int x, int y) {
    int ans = 0;
    for(int k = 1; k <= 10; k++) ans += (dp[x][y][k] >= 1);
    return ans;
}

int calc(int sx, int sy, int ex, int ey) {
    calc_minus(sx - 1, ey, ex, ey);
    calc_minus(ex, sy - 1, ex, ey);
    calc_plus(sx - 1, sy - 1, ex, ey);
    int ret = count(ex, ey);
    calc_minus(sx - 1, sy - 1, ex, ey);
    calc_plus(sx - 1, ey, ex, ey);
    calc_plus(ex, sy - 1, ex, ey);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int x = 0; x < N; x++)
        for(int y = 0; y < N; y++)
            cin >> arr[x][y];


    for(int x = 0; x < N; x++) dp[x][0][arr[x][0]]++;
    for(int x = 0; x < N; x++) {
        for (int y = 1; y < N; y++) {
            for (int k = 1; k <= 10; k++) {
                dp[x][y][k] = dp[x][y-1][k];
            }
            dp[x][y][arr[x][y]]++;
        }
    }

    for(int x = 1; x < N; x++) {
        for(int y = 0; y < N; y++) {
            for(int k = 1; k <= 10; k++) {
                dp[x][y][k] += dp[x-1][y][k];
            }
        }
    }

    cin >> Q;

    int sx, sy, ex, ey;
    while(Q--) {
        cin >> sx >> sy >> ex >> ey;
        cout << calc(sx - 1, sy - 1, ex - 1, ey - 1) << '\n';
    }
    return 0;
}
