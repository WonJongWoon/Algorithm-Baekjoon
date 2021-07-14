//
// Created by JongWoon on 2021-07-13.
//
// Link : https://www.acmicpc.net/problem/6800

#include <bits/stdc++.h>

using namespace std;

int K;

unordered_map<string, char> table;
string v, code, huffman;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> K;

    for(int i = 1; i <= K; i++) {
        cin >> v >> code;
        table[code] = v.at(0);
    }


    cin >> huffman;
    int i = 0, j = 0;

    while(i <= j && j < (int)huffman.length()) {
        string test = huffman.substr(i, j - i + 1);

        if (table.count(test)) {
            cout << table[test];
            i = j + 1;
            j = i;
        } else { // 못찾은 경우
            j++;
        }
    }

    return 0;
}
