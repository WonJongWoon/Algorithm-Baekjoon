//
// Created by JongWoon on 2021-06-04.
//
// Link : https://www.acmicpc.net/problem/1890

#include <bits/stdc++.h>

using namespace std;

#define SIZE (100+2)

int N, arr[SIZE][SIZE];
long long dp[SIZE][SIZE];

long long get_dp(int x, int y) {
    if (x < 1 || x > N || y < 1 || y > N) return 0;
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> arr[i][j];

    dp[1][1] = 1;

    for(int x = 1; x <= N; x++) {
        for(int y = 1; y <= N; y++) {
            if(x == 1 && y == 1) continue;
            long long sum = 0;
            for(int k = 1; k < 9; k++) {
                if (x - k >= 1 && arr[x-k][y] == k) sum += get_dp(x-k, y);
                if (y - k >= 1 && arr[x][y-k] == k) sum += get_dp(x, y-k);
            }
            dp[x][y] = sum;
        }
    }

    cout << dp[N][N];

    return 0;
}
