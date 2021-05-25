//
// Created by JongWoon on 2021-05-25.
//
// Link : https://www.acmicpc.net/problem/1927

#include <bits/stdc++.h>

using namespace std;

int N, x;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    while (N--) {
        cin >> x;
        if (x > 0) {
            pq.push(x);
        } else {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
    return 0;
}