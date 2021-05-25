//
// Created by JongWoon on 2021-05-25.
//
// Link : https://www.acmicpc.net/problem/10828

#include <bits/stdc++.h>

using namespace std;

int N, data;
string op;
stack<int> s;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    while (N--) {
        cin >> op;

        if (op == "push") {
            cin >> data;
            s.push(data);
        } else if (op == "pop") {
            if (s.empty()) {
                cout << "-1\n";
            } else {
                cout << s.top() << "\n";
                s.pop();
            }
        } else if (op == "size") {
            cout << s.size() << "\n";
        } else if (op == "empty") {
            cout << (s.empty() ? "1\n" : "0\n");
        } else if (op == "top") {
            cout << (s.empty() ? -1 : s.top()) << "\n";
        }
    }

    return 0;
}