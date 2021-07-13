//
// Created by JongWoon on 2021-07-10.
//
// Link : https://www.acmicpc.net/problem/2002

#include <bits/stdc++.h>

#define SIZE (1000+2)

using namespace std;

unordered_map<string, int> orders;
string car_number;
string out_orders[SIZE];

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> car_number;
        orders[car_number] = i;
    }

    for(int i = 1; i <= N; i++) {
        cin >> out_orders[i];
    }

    int ans = 0;

    for(int i = 1; i < N; i++) {
        for(int j = i + 1; j <= N; j++) {
            if (orders[out_orders[i]] > orders[out_orders[j]]) { // i번째로 나온 사람이 j번째로 나온 사람보다 늦게 들어간 경우는 추월한 경우이다.
                ans++;
                break; // i가 추월했다는건 명백하므로 중복 카운팅을 하지 않는다.
            }
        }
    }

    cout << ans;
    return 0;
}