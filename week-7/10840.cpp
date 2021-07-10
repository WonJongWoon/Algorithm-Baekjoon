//
// Created by JongWoon on 2021-07-10.
//
// Link : https://www.acmicpc.net/problem/10840

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

string S1, S2;

const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;

int primes1[27], primes2[27];

inline int sum(int x, int y, int mod) { return (x+(long long)y) % mod; }
inline int mul(int x, int y, int mod) { return (x*(long long)y) % mod; }

unordered_map<int, pii> filter;

void init() {
    for(int i = 1; i <= 26; i++) {
        primes1[i] =(int)(rand() % (MOD1-2)) + 2;
        primes2[i] =(int)(rand() % (MOD2-2)) + 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> S1;
    cin >> S2;
    init();

    for(int i = 0; i < (int)S1.length(); i++) {
        int ans1 = 0, ans2 = 0;
        for(int j = i ; j < (int)S1.length(); j++) {
            int c = S1[j] - 'a' + 1, len = j - i + 1;
            int k1 = primes1[c], k2 = primes2[c];
            ans1 = sum(ans1, mul(k1, c, MOD1), MOD1);
            ans2 = sum(ans2, mul(k2, c, MOD2), MOD2);

            filter[ans1] = { ans2, len };
        }
    }

    int max_len = 0;

    for(int i = 0; i < (int)S2.length(); i++) {
        int ans1 = 0, ans2 = 0;
        for(int j = i ; j < (int)S2.length(); j++) {
            int c = S2[j] - 'a' + 1;
            int k1 = primes1[c], k2 = primes2[c];
            ans1 = sum(ans1, mul(k1, c, MOD1), MOD1);
            ans2 = sum(ans2, mul(k2, c, MOD2), MOD2);
            if (filter.count(ans1) && filter[ans1].first == ans2) {
                max_len = max(max_len, filter[ans1].second);
            }
        }
    }

    cout << max_len;

    return 0;
}
