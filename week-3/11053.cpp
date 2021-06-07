//
// Created by JongWoon on 2021-06-07.
//
// Link : https://www.acmicpc.net/problem/11053


#include <bits/stdc++.h>

using namespace std;

#define SIZE (1000+2)

int N;
int arr[SIZE], dp[SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int i = 1; i <= N; i++) dp[i] = 1;

    int ans = -1;
    for(int i = N; i >= 1; --i) {
        int max_len = dp[i];
        for(int j = i; j <= N; j++) {
            if (arr[i] < arr[j] && dp[j] + 1 > max_len) {
                max_len = dp[j] + 1;
            }
        }
        dp[i] = max_len;
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}