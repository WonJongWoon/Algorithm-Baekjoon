//
// Created by JongWoon on 2021-06-04.
//
// Link : https://www.acmicpc.net/problem/7453

#include <bits/stdc++.h>

using namespace std;

#define SIZE (4000)
int N, A[SIZE], B[SIZE], C[SIZE], D[SIZE], E[SIZE*SIZE], F[SIZE*SIZE];
int k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            E[k] = A[i] + B[j];
            F[k] = -(C[i] + D[j]);
            k++;
        }
    }

    sort(E, E + k);
    sort(F, F + k);

    long long ans = 0;

    for(int i = 0; i < k; i++) {
        int* l = lower_bound(F, F + k, E[i]);
        if (*l == E[i]) {
            int* r = upper_bound(F, F + k, E[i]);
            ans += (r - l);
        }
    }

    cout << ans;
    return 0;
}

