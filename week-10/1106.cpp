//
// Created by JongWoon on 2021-07-31.
//
// Link : https://www.acmicpc.net/problem/1106

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

#define cost first
#define num second

const int SIZE = 1000+2;
const int INF = 987654321;

int C, N;
int dp[SIZE];
vector<pii> cities;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> C >> N;

    for(int i = 1; i <= N; i++) {
        int cost, num;
        cin >> cost >> num;
        cities.emplace_back(cost, num);
    }

    for(int i = 1; i <= C; i++) {
        dp[i] = INF;
        for(const pii city : cities) {
            int lower = max(i - city.num, 0);
            for(int k = lower; k < i; k++) {
                dp[i] = min(dp[i], dp[k] + city.cost);
            }
        }
    }

    cout << dp[C];
    return 0;
}
