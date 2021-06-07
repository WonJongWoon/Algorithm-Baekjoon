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

vector<int> get_freq(int sx, int sy) {
    vector<int> freq(11, 0);
    if (sx < 0 || sx >= N || sy < 0 || sy >= N) return freq;
    freq.assign(dp[sx][sy], dp[sx][sy] + 11);
    return freq;
}

int count(vector<int> freq) {
    int ans = 0;
    for(int k = 1; k <= 10; k++) ans += (freq[k] >= 1);
    return accumulate()
}

int calc(int sx, int sy, int ex, int ey) {
    vector<int> origin = get_freq(ex, ey);
    vector<int> up = get_freq(sx-1, ey);
    vector<int> left = get_freq(ex, sy - 1);
    vector<int> intersection = get_freq(sx-1, sy-1);

    for(int k = 1; k <= 10; k++)
        origin[k] += -(up[k] + left[k]) + intersection[k];
    return count(origin);
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
