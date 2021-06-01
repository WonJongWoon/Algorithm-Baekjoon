//
// Created by JongWoon on 2021-06-01.
//
// Link : https://www.acmicpc.net/problem/11659

#include <bits/stdc++.h>

using namespace std;

#define SIZE (100000+2)

int N, M;
int arr[SIZE], sum[SIZE];
int s, e;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int i = 1; i <= N; i++) sum[i] = sum[i-1] + arr[i];

    while(M--) {
        cin >> s >> e;
        cout << (sum[e] - sum[s-1]) << '\n';
    }
    return 0;
}
