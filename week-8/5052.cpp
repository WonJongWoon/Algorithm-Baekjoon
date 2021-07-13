//
// Created by JongWoon on 2021-07-13.
//
// Link : https://www.acmicpc.net/problem/5052

#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node() {
        end = false;
        for (Node* node : next) node = nullptr;
    }
    bool end;
    Node *next[10]{};
};

int T, N, ans;

bool dfs(Node* root) {
    if (root->end) {
        for(Node* node : root->next) {
            if (node != nullptr) {
                ans++;
                return true; // 한 번호가 다른 번호의 접두사인 경우가 존재하므로 더 이상 내려가지 않아도 된다.
            }
        }
        return false; // 더이상 밑으로 안 타고 내려가도 된다. 내려갈 자식이 없다.
    }


    for(Node* node : root->next) {
        if (node != nullptr && dfs(node)) return true;
    }

    return false; // 루트의 next가 아무것도 없는 경우
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    while(T--) {
        cin >> N;

        Node* root = new Node();

        for (int i = 1; i<= N; i++) {
            string s;
            cin >> s;

            Node *now = root;

            for (char c : s) {
                if (!now->next[c-'0']) now->next[c-'0'] = new Node();
                now = now->next[c-'0'];
            }

            now->end = true;
        }

        dfs(root);
        cout << (ans >= 1 ? "NO\n" : "YES\n");
        ans = 0;
    }
}