//
// Created by JongWoon on 2021-05-19.
//
// Link : https://www.acmicpc.net/problem/1654


#include <bits/stdc++.h>

using namespace std;

#define SIZE (10000+2)
int arr[SIZE];
int K, N;

bool is_possible(long long len) {
    long long cnt = 0;
    for(int i = 0; i < K; i++) cnt += (arr[i] / len);
    return cnt >= N;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K >> N;
    for (int i = 0; i < K; i++) cin >> arr[i];

    long long l = 0, r = 1e10;

    while(l + 1 < r) {
        long long m = (l + r) / 2;

        if (is_possible(m)) l = m;
        else r = m;
    }

    cout << l << "\n";
    return 0;
}