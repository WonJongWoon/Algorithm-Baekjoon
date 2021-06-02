//
// Created by JongWoon on 2021-06-02.
//
// Link : https://www.acmicpc.net/problem/17609

#include <bits/stdc++.h>

using namespace std;

#define SIZE (30+2)

int T;

int solve(string& input, int i, int j, int cnt) {
    int l = i, r = j;
    if (cnt >= 2) return 2;

    while(l <= r) {
        if (input[l] != input[r]) {
            int p = solve(input, l+1, r, cnt + 1);
            int q = solve(input, l, r-1, cnt + 1);
            return min(p, q);
        } else {
            l++; r--;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    string input;
    while(T--) {
        cin >> input;
        cout << solve(input, 0, (int)input.size() - 1, 0) << '\n';
    }
    return 0;
}
