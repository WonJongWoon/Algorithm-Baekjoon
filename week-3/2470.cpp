//
// Created by JongWoon on 2021-06-02.
//
// Link : https://www.acmicpc.net/problem/2470

#include <bits/stdc++.h>

#define SIZE (100000+2)

using namespace std;

int N;
int arr[SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr +N);

    int l = 0, r = N-1;
    int i = 0, j = N-1;
    int min_sum = 2'000'000'001;

    while(l < r) {
        int sum = arr[l] + arr[r];
        if (abs(min_sum) > abs(sum)) {
            i = l; j = r;
            min_sum = sum;
        }
        if (sum < 0) l++;
        else r--;
    }

    cout << arr[i] << ' ' << arr[j];

    return 0;
}
