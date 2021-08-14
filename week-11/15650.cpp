//
// Created by JongWoon on 2021-08-14.
//
// Link : https://www.acmicpc.net/problem/15650

#include <bits/stdc++.h>

using namespace std;

const int SIZE = 8 + 2;
int N, M, P[SIZE];
bool visited[SIZE];

void permutation(int l) {
    if (l == M) {
        for (int i = 1; i <= l; i++) cout << P[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i] && P[l] <= i) {
            visited[i] = true;
            P[l + 1] = i;
            permutation(l + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    permutation(0);

    return 0;
}
