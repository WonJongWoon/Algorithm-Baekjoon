//
// Created by JongWoon on 2021-05-15.
//
// Link : https://www.acmicpc.net/problem/10211

#include <bits/stdc++.h>

using namespace std;

#define SIZE (1000+2)
int arr[SIZE];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N;
    cin >> T;

    while(T--) {
        cin >> N;
        for(int i = 0 ; i < N; i++) cin >> arr[i];
        for(int i = 1; i < N; i++) arr[i] = max(arr[i], arr[i] + arr[i-1]);
        cout << *max_element(arr, arr + N) << "\n";
    }
    return 0;
}
