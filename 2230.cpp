//
// Created by JongWoon on 2021-05-17.
//
// Link : https://www.acmicpc.net/problem/2230

#include <bits/stdc++.h>

using namespace std;

#define SIZE (100000+2)
int arr[SIZE];
int N, M;

bool possible(int a, int b) {
    return b - a >= M;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) cin >> arr[i];
    sort(arr + 1, arr + N + 1);

    int l = 0, r = N;

    while(l + 1 < r) {
        int m = (l + r) / 2;
        if (possible(arr[l], arr[m])) r = m;
        else if(possible(arr[m], arr[r])) l = m;
        else break;
    }

    cout << (arr[r] - arr[l]) << "\n";
    return 0;
}
