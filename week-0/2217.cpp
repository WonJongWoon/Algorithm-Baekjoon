//
// Created by JongWoon on 2021-05-15.
//
// Link : https://www.acmicpc.net/problem/2217

#include <bits/stdc++.h>

using namespace std;

#define SIZE  (100000 + 2)
int rope_weights[SIZE];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) cin >> rope_weights[i];
    sort(rope_weights, rope_weights + N, greater<int>());
    int max_value = -1;

    for(int i = 0; i < N; i++) max_value = max(max_value, rope_weights[i] * (i+1));
    cout << max_value << '\n';
    return 0;
}