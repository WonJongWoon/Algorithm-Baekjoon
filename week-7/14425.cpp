//
// Created by JongWoon on 2021-07-08.
//
// Link : https://www.acmicpc.net/problem/14425

#include <bits/stdc++.h>

using namespace std;

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

int N, M;
string word;
set<int> filter;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        cin >> word;
        filter.insert(hashing(R, MOD, word));
    }

    int ans = 0;

    for(int i = 1; i <= M; i++) {
        cin >> word;
        if (filter.count(hashing(R, MOD, word))) ans++;
    }

    cout << ans;
    return 0;
}
