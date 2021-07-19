//
// Created by JongWoon on 2021-07-19.
//
// Link : https://www.acmicpc.net/problem/13505

#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node *next[2]{};
};

const int SIZE = 100000+2;

Node* root;
int N, arr[SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    root = new Node();

    for(int i = 1; i <= N; i++) cin >> arr[i];

    for(int i = 1; i <= N; i++) {
        Node* now = root;
        for(int k = 30; k >= 0; k--) {
            int bit = (arr[i] >> k) & 1;
            if (!now->next[bit]) now->next[bit] = new Node();
            now = now->next[bit];
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        Node* now = root;

        int nans = 0;
        for(int k = 30; k >=0; k--) {
            int bit = (arr[i] >> k) & 1;

            if(!now->next[!bit]) now = now->next[bit]; // 반대 비트가 없는 경우
            else { // 반대 비트가 있는 경우
                nans |= (1 << k); // 반대인 경우는 1로 셋업, 위치는 k, 비트 마스킹 이용
                now = now->next[!bit];
            }
        }
        ans = max(ans, nans);
    }
    cout << ans << '\n';

    return 0;
}