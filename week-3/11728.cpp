//
// Created by JongWoon on 2021-06-01.
//
// Link : https://www.acmicpc.net/problem/11728

#include <bits/stdc++.h>

using namespace std;

#define SIZE (1'000'000 + 2)

int A[SIZE], B[SIZE];
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    int i = 0, j = 0;

    while(i < N && j < M) {
        if (A[i] < B[j]) cout << A[i++] << ' ';
        else cout << B[j++] << ' ';
    }
    while(i < N) cout << A[i++] << ' ';
    while(j < M) cout << B[j++] << ' ';
    return 0;
}
