//
// Created by JongWoon on 2021-06-01.
//
// Link : https://www.acmicpc.net/problem/2670

#include <bits/stdc++.h>

using namespace std;

#define SIZE (10000+2)

int N;
double arr[SIZE], mul[SIZE];
double max_ans = DBL_MIN;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];

    for(int i = 1; i <= N; i++) {
        mul[i] = max(mul[i-1] * arr[i], arr[i]);
        max_ans = max(max_ans, mul[i]);
    }

    cout << fixed;
    cout.precision(3);
    cout << max_ans << '\n';
    return 0;
}
