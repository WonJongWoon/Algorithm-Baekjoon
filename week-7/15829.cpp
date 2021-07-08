//
// Created by JongWoon on 2021-07-08.
//
// Link : https://www.acmicpc.net/problem/15829

#include <bits/stdc++.h>

using namespace std;

int L;
string S;

const int MOD = 1234567891;
const int R = 31;

inline int sum(int x, int y, int mod) { return (x+(long long)y) % mod; }
inline int mul(int x, int y, int mod) { return (x*(long long)y) % mod; }

int hashing(int r, int mod, string& src) {
    int ans = 0, k = 1;
    for(char i : src) {
        ans = sum(ans, mul(k, i - 'a' + 1, mod), mod);
        k = mul(k, r, mod);
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> L;
    cin >> S;

    int ans = hashing(R, MOD, S);

    cout << ans;
    return 0;
}
