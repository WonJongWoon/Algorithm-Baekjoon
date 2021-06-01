//
// Created by JongWoon on 2021-06-01.
//
// Link : https://www.acmicpc.net/problem/11660

#include <bits/stdc++.h>

using namespace std;

#define SIZE (1024+2)
int N, M;
int board[SIZE][SIZE], arr[SIZE][SIZE];
int sx, sy, ex, ey;


int calc_range(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return 0;
    else return board[x][y];
}

int calc(int sx, int sy, int ex, int ey) {
    int left = calc_range(sx - 1, ey), up = calc_range(ex, sy - 1);
    int ret = calc_range(ex, ey), intersection = calc_range(sx - 1, sy - 1);
    return ret - (left + up) + intersection;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    for (int i = 0; i < N; i++) board[i][0] = arr[i][0];
    for (int i = 0; i < N; i++)
        for (int j = 1; j < N; j++)
            board[i][j] += board[i][j - 1] + arr[i][j];

    for (int i = 1; i < N; i++)
        for (int j = 0; j < N; j++) {
            board[i][j] += board[i - 1][j];


    while (M--) {
        cin >> sx >> sy >> ex >> ey;
        cout << calc(sx - 1, sy - 1, ex - 1, ey - 1) << '\n';
    }

    return 0;
}
