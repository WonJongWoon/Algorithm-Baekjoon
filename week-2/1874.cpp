//
// Created by JongWoon on 2021-05-26.
//
// Link : https://www.acmicpc.net/problem/1874

#include <bits/stdc++.h>

using namespace std;

#define SIZE (100000+2)

int N, i, n;
int arr[SIZE];
stack<int> s;
bool is_not_valid;

string answer;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];

    while(i < N) {
        if (!s.empty() && arr[i] == s.top()) {
            answer.append("-\n");
            s.pop();
            ++i;
        } else {
            if (is_not_valid = (!s.empty() && (s.top() > arr[i]))) break;
            do {
                s.push(++n);
                answer.append("+\n");
            } while(arr[i] != s.top());
        }
    }

    cout << (is_not_valid ? "NO\n" : answer);
    return 0;
}
