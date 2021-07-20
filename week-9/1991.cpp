//
// Created by JongWoon on 2021-07-20.
//
// Link : https://www.acmicpc.net/problem/1991

#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 26+2;

int N;
int tree[MAX_V][2];

void preorder(int current)
{
    if (current == -1) return;

    cout << (char)(current + 'A');
    preorder(tree[current][0]);
    preorder(tree[current][1]);
}

void inorder(int current)
{
    if (current == -1) return;

    inorder(tree[current][0]);
    cout << (char)(current + 'A');
    inorder(tree[current][1]);
}

void postorder(int current)
{
    if (current == -1) return;

    postorder(tree[current][0]);
    postorder(tree[current][1]);
    cout << (char)(current + 'A');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        char root, left, right;
        cin >> root >> left >> right;
        tree[root - 'A'][0] = left != '.' ? (left - 'A') : -1;
        tree[root - 'A'][1] = right != '.' ? (right - 'A') : -1;
    }

    preorder('A' - 'A'); cout << '\n';
    inorder('A' - 'A'); cout << '\n';
    postorder('A' - 'A'); cout << '\n';

    return 0;
}
