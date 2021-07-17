//
// Created by JongWoon on 2021-07-17.
//
// Link : https://www.acmicpc.net/problem/13505

#include <bits/stdc++.h>

#include <utility>

using namespace std;

const int SIZE = 100000+2;

int N, ans = -1;
int arr[SIZE];

struct Node {
    int v = -1, b;
    bool end;
    Node *next[2]{};
    explicit Node(int _b = -1) : b(_b), end(false) {
        for(Node* node : next) node = nullptr;
    }
};

Node* root;

Node* chk(Node* l, Node* r) {
    return (l == nullptr ? r : l);
}

void dfs(Node* l, Node* r) {
    if (l->end) {
        ans = max(ans, l->v ^ r->v);
        return;
    }

    if (l->next[0] != nullptr) dfs(l->next[0], chk(r->next[1], r->next[0]));
    if (l->next[1] != nullptr) dfs(l->next[1], chk(r->next[0], r->next[1]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];

    root = new Node();

    for(int i = 1; i <= N; i++) {
        bitset<32> b(arr[i]);
        string s = b.to_string();
        Node* now = root;

        for(char c : s) {
            if (!now->next[c-'0']) now->next[c-'0'] = new Node(c-'0');
            now = now->next[c-'0'];
        }

        now->v = arr[i];
        now->end = true;
    }

    Node* l = chk(root->next[0], root->next[1]);
    Node* r = chk(root->next[1], root->next[0]);

    while(l->b == r->b) {
        Node* tmp = l;
        l = chk(tmp->next[0], tmp->next[1]);
        r = chk(tmp->next[1], tmp->next[0]);
    }

    dfs(l, r);
    cout << ans;

    return 0;
}
