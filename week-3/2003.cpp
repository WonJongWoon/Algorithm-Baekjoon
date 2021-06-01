//
// Created by JongWoon on 2021-06-01.
//
// Link : https://www.acmicpc.net/problem/2003
#include <bits/stdc++.h>

using namespace std;

#define SIZE (10000+2)
int N, M;
int A[SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> A[i];

    int j = 0, sum = A[0];
    int ans = 0;

    for(int i = 0; i < N; i++) {
        while(sum < M && j < (N - 1)) {
            sum += A[++j];
        }
        ans += (sum == M);
        sum -= A[i];
    }

    cout << ans;
    return 0;
}