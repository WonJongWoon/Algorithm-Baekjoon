//
// Created by JongWoon on 2021-06-07.
//
// Link : https://www.acmicpc.net/problem/11055


#include <bits/stdc++.h>

using namespace std;

#define SIZE (1000+2)

int N, ans = - 1;
int arr[SIZE], dp[SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int i = 1; i <= N; i++) dp[i] = arr[i];

    for(int i = N; i >= 1; --i) {
        int max_v = dp[i];
        for(int j = i; j <= N; j++) {
            if (arr[i] < arr[j] && max_v < dp[j] + arr[i]) {
                max_v = dp[j] + arr[i];
            }
        }
        dp[i] = max_v;
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}