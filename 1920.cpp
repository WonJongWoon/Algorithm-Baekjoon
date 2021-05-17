//
// Created by JongWoon on 2021-05-17.
//
// Link : https://www.acmicpc.net/problem/1920


#include <bits/stdc++.h>

#define SIZE (100000+2)
int arr[SIZE];

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);

    int M; cin >> M;

    while(M--) {
        int k; cin >> k;
        cout << binary_search(arr, arr + N, k) << "\n";
    }

    return 0;
}
