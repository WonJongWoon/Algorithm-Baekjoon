//
// Created by JongWoon on 2021-07-08.
//
// Link : https://www.acmicpc.net/problem/11478

#include <bits/stdc++.h>

using namespace std;

string S;

unordered_set<string> filter;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> S;

    for(int i = 0; i < (int)S.length(); i++) {
        for(int j = 1; j <= (int)S.length() - i; j++) {
            filter.insert(S.substr(i, j));
        }
    }
    cout << filter.size() << '\n';
    return 0;
}
