//
// Created by JongWoon on 2021-05-26.
//
// Link : https://www.acmicpc.net/problem/1715

#include <bits/stdc++.h>

using namespace std;

int N, total;
priority_queue<int, vector<int>, greater<>> pq;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 0, x; i < N; i++)  {
        cin >> x;
        pq.push(x);
    }

    while(--N) {
        int s1 = pq.top(); pq.pop();
        int s2 = pq.top(); pq.pop();
        total += (s1 + s2);
        pq.push(s1 + s2);
    }

    cout << total << '\n';
    return 0;
}
