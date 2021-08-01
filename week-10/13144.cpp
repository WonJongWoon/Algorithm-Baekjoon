//
// Created by JongWoon on 2021-08-01.
//
// Link : https://www.acmicpc.net/problem/13144

#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100000+2;

bool check[SIZE];
int arr[SIZE], dp[SIZE], N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];

    for(int i = 1; i <= N; i++) {
        int j = dp[i-1] + 1;
        check[arr[i-1]] = false;
        for(; j <= N; j++) {
            if (check[arr[j]]) break;
            check[arr[j]] = true;
        }
        dp[i] = j-1;
    }

    long long ans = 0;
    for(int i = 1; i <= N; i++) ans += dp[i] - i + 1;
    cout << ans;
    return 0;
}