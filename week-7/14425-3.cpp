//
// Created by JongWoon on 2021-07-13.
//
// Link : https://www.acmicpc.net/problem/14425

#include <bits/stdc++.h>

using namespace std;

int N, M;

struct Node {
    Node() {
        end = false;
        for (Node* node : next) node = nullptr;
    }
    bool end;
    Node *next[26]{};
};

Node* root;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    cin >> M;

    root = new Node();

    for (int i = 1; i <= N; i++) {
        cin >> s;

        Node *now = root;

        for (char c : s) {
            if (!now->next[c-'a']) now->next[c-'a'] = new Node();
            now = now->next[c-'a'];
        }

        now->end = true;
    }

    int ans = 0;
    for (int i = 1; i <= M; i++) {
        cin >> s;

        Node *now = root;

        bool ok = true;
        for (char c : s) {
            if (!now->next[c-'a']) {
                ok = false;
                break;
            }
            now = now->next[c-'a'];
        }

        ok &= now->end;

        ans += ok == true;
    }

    cout << ans << '\n';
    return 0;
}