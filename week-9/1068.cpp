//
// Created by JongWoon on 2021-07-23.
//
// Link : https://www.acmicpc.net/problem/1068

#include <bits/stdc++.h>

using namespace std;

const int SIZE = 50+2;

struct Node {
    int parent;
    vector<int> childs;
};

Node nodes[SIZE];
int N, R;
int leaf_nodes;

void dfs(int start) {
    if (nodes[start].childs.empty()) {
        leaf_nodes++;
        return;
    }

    for(int node : nodes[start].childs) {
        dfs(node);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for(int i = 0, parent; i < N; i++) {
        cin >> parent;
        if (parent == -1) {
            nodes[i].parent = i;
            R = i;
        }
        else {
            nodes[i].parent = parent;
            nodes[parent].childs.emplace_back(i);
        }
    }

    int delete_node;
    cin >> delete_node;

    int parent = nodes[delete_node].parent;

    if (parent == delete_node) { // 루트노드를 삭제하는 경우는 0 반환
        cout << 0 << '\n';
        return 0;
    }

    auto pos = find(nodes[parent].childs.begin(), nodes[parent].childs.end(), delete_node); // 삭제하고자 하는 노드의 부모 노드에서 스스로를 지운다.
    nodes[parent].childs.erase(pos);
    dfs(R);
    cout << leaf_nodes;

    return 0;
}
