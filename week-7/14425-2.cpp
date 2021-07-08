//
// Created by JongWoon on 2021-07-08.
//
// Link : https://www.acmicpc.net/problem/14425

#include <bits/stdc++.h>

using namespace std;

int N, M;
string word;
unordered_set<string> filter;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        cin >> word;
        filter.insert(word);
    }

    int ans = 0;

    for(int i = 1; i <= M; i++) {
        cin >> word;
        if (filter.count(word)) ans++;
    }

    cout << ans;
    return 0;
}
