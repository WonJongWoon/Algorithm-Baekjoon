//
// Created by JongWoon on 2021-07-13.
//
// Link : https://www.acmicpc.net/problem/6800

#include <bits/stdc++.h>

using namespace std;

int K;
string s, code, huffman;

struct Node {
    Node() {
        end = false;
        for (Node* node : next) node = nullptr;
    }
    bool end;
    char v{};
    Node *next[2]{};
};

Node* root;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> K;
    root = new Node();

    while(K--) {
        cin >> s >> code;

        Node *now = root;

        for (char c : code) {
            if (!now->next[c-'0']) now->next[c-'0'] = new Node();
            now = now->next[c-'0'];
        }

        now->v = s.at(0);
        now->end = true;
    }

    cin >> huffman;
    int i = 0, j = 0;

    while(i <= j && j < (int)huffman.length()) {
        Node *now = root;
        string test = huffman.substr(i, j - i + 1);

        bool ok = true;
        for (char c : test) {
            if (!now->next[c-'0']) {
                ok = false;
                break;
            }
            now = now->next[c-'0'];
        }
        ok &= now->end;

        if (ok) { // i ~ j 까지
            cout << now->v;
            i = j + 1;
            j = i;
        } else { // 못찾은 경우
            j++;
        }
    }

    return 0;
}
