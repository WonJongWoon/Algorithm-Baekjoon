//
// Created by JongWoon on 2021-05-21.
//
// Link : https://www.acmicpc.net/problem/2230

#include <bits/stdc++.h>

#define SIZE (100000+2)

using namespace std;

int N, M;
int arr[SIZE];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    int min_diff = arr[N-1] - arr[0];

    for(int i = 0; i < N; i++) {
        int base = arr[i];
        int* p1 = lower_bound(arr, arr + N, base + M);
        if (p1 != arr + N && (*p1 - base) >= M) min_diff = min(min_diff, *p1 - base);
    }

    cout << min_diff << "\n";
    return 0;
}