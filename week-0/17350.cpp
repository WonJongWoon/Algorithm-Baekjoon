//
// Created by JongWoon on 2021-05-15.
//
// Link : https://www.acmicpc.net/problem/17350

#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    bool is_exist = false;

    while(N--) {
        string input; cin >> input;
        transform(all(input), input.begin(), ::tolower);
        if (is_exist = (input == "anj")) break;
    }

    cout << "뭐야" << (is_exist ? ";" : "?") << '\n';
    return 0;
}