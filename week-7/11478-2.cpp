//
// Created by JongWoon on 2021-07-08.
//
// Link : https://www.acmicpc.net/problem/11478

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

string S;
set<pii> filter;

const int R1 = 127;
const int R2 = 131;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;

inline int sum(int x, int y, int mod) { return (x+(long long)y) % mod; }
inline int mul(int x, int y, int mod) { return (x*(long long)y) % mod; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> S;

    for(int i = 0; i < (int)S.length(); i++) {
        int ans1 = 0, ans2 = 0, k1 = 1, k2 = 1;
        for(int j = i; j < (int)S.length(); j++) {
            int c = S[j] - 'a' + 1;
            ans1 = sum(ans1, mul(k1, c, MOD1), MOD1);
            k1 = mul(k1, R1, MOD1);
            ans2 = sum(ans2, mul(k2, c, MOD2), MOD2);
            k2 = mul(k2, R2, MOD2);
            filter.emplace(ans1, ans2);
        }
    }

    cout << filter.size() << '\n';
    return 0;
}
