//
// Created by JongWoon on 2021-05-15.
//
// Link : https://www.acmicpc.net/problem/14697

#include <bits/stdc++.h>

using namespace std;

int solve() {

    int A, B, C, N;
    cin >> A >> B >> C >> N;
    int MAX_A = N / A, MAX_B = N / B, MAX_C = N / C;

    for (int i = 0; i <= MAX_A; i++) {
        for (int j = 0; j <= MAX_B; j++) {
            for (int k = 0; k <= MAX_C; k++) {
                if (A * i + B * j + C * k == N) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve();
    return 0;
}