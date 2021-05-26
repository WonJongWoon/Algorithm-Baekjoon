//
// Created by JongWoon on 2021-05-26.
//
// Link : https://www.acmicpc.net/problem/11286

#include <bits/stdc++.h>

using namespace std;

struct compare {
    bool operator()(const int lhs, const int rhs) {
        if (abs(lhs) == abs(rhs)) {
            return lhs > rhs;
        }
        return abs(lhs) > abs(rhs);
    }
};

int N, x;
priority_queue<int, vector<int>, compare> pq;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    while(N--) {
        cin >> x;
        if (x != 0) {
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
