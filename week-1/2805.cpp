//
// Created by JongWoon on 2021-05-19.
//
// Link : https://www.acmicpc.net/problem/2805

#include <bits/stdc++.h>
#define SIZE (1000000+2)

int arr[SIZE];
int N, M;

using namespace std;

int relu(int v) {
    return v < 0 ? 0 : v;
}

bool is_possible(int h) {
    long long sum = 0;
    for(int i = 0; i < N; i++) sum += relu(arr[i] - h);
    return sum >= M;
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> arr[i];

    int l = 0, r = 1e9;

    while (l + 1 < r) {
        int m = (l + r) / 2;

        if (is_possible(m)) l = m;
        else r = m;
    }


    cout << l << "\n";
    return 0;
}
