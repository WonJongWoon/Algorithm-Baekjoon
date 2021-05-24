//
// Created by JongWoon on 2021-05-20.
//
// Link : https://www.acmicpc.net/problem/1300

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, K;

bool is_possible(long long m) {
    ll cnt = 0;
    for(ll i = 1; i <= N; i++) {
        if (m >= i * N) cnt += N;
        else {
            cnt += (m / i);
        }
    }
    return cnt >= K;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> K;

    ll l = 0, r = 1e10 + 1;

    // l = possible -> false, r = possible -> true

    while(l + 1 < r) {
        ll m = (l+r) / 2;
        if (is_possible(m)) r = m;
        else l = m;
    }

    cout << r << "\n";

    return 0;
}
