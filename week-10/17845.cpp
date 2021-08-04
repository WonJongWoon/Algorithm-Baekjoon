//
// Created by JongWoon on 2021-08-04.
//
// Link : https://www.acmicpc.net/problem/17845

#include <bits/stdc++.h>

using namespace std;

const int LECTURE_SIZE = 1000+2;
const int TIME_SIZE = 10000+2;

int dp[LECTURE_SIZE][TIME_SIZE];

int N, K;
int times[LECTURE_SIZE], prices[LECTURE_SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;
    for(int i = 1; i <= K; i++) {
        cin >> prices[i] >> times[i];
    }

    // dp [i][t] = i개 과목에서만 선택할때 총 공부시간이 t를 초과하지 않을 때 최대 중요도
    for(int i = 1; i <= K; i++) {
        for(int t = 0; t <= N; t++) {
            int price = prices[i], time = times[i];
            if (t >= time) {
                dp[i][t] = max(dp[i-1][t], price + dp[i-1][t-time]);
            } else dp[i][t] = dp[i-1][t];
        }
    }

    cout << dp[K][N];
    return 0;
}
