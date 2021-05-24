//
// Created by JongWoon on 2021-05-15.
//
// Link : https://www.acmicpc.net/problem/10211

#include <bits/stdc++.h>

using namespace std;

#define SIZE (1000+2)
#define MINUS_INF (-987654321)

int arr[SIZE];
int prefix[SIZE];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N;
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) cin >> arr[i];
        for (int i = 1; i <= N; i++) prefix[i] = prefix[i - 1] + arr[i - 1];
        int max_value = MINUS_INF;

        for (int i = 0; i < N; i++)
            for (int j = i + 1; j <= N; j++)
                max_value = max(prefix[j] - prefix[i], max_value);

        cout << max_value << "\n";
    }

    return 0;
}