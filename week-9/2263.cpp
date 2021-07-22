//
// Created by JongWoon on 2021-07-22.
//
// Link : https://www.acmicpc.net/problem/2263

#include <bits/stdc++.h>

using namespace std;
const int SIZE = 100000+2;

int inorder[SIZE];
int postorder[SIZE];
int position[SIZE];

int N;

// root -> left -> right
void preorder(int in_start, int in_end, int post_start, int post_end) {
    // base condition
    if (in_start > in_end || post_start > post_end) return;

    int root_elem = postorder[post_end];
    int root_index = position[root_elem];
    cout << root_elem << ' ';

    preorder(in_start, root_index - 1, post_start, post_start +  root_index - in_start - 1);
    preorder(root_index + 1, in_end, post_start + (root_index - in_start), post_end - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++) cin >> inorder[i];
    for(int i = 1; i <= N; i++) position[inorder[i]] = i;
    for(int i = 1; i <= N; i++) cin >> postorder[i];

    preorder(1, N, 1, N);
    return 0;
}