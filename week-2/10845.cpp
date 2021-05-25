//
// Created by JongWoon on 2021-05-25.
//
// Link : https://www.acmicpc.net/problem/10845

#include <bits/stdc++.h>

using namespace std;

int N, data;
string op;
queue<int> q;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    while(N--) {
        cin >> op;

        if (op == "push") {
            cin >> data;
            q.push(data);
        } else if (op == "pop") {
            int value = q.empty() ? -1 : q.front();
            if (value != -1) q.pop();
            cout << value << "\n";
        } else if (op == "front") {
            cout << (q.empty() ? -1 : q.front()) << "\n";
        } else if (op == "size") {
            cout << q.size() << "\n";
        } else if (op == "empty") {
            cout << (q.empty() ? 1 : 0) << "\n";
        } else if (op == "back") {
            cout << (q.empty() ? -1 : q.back()) << "\n";
        }
    }

    return 0;
}