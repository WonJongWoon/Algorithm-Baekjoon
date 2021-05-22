//
// Created by JongWoon on 2021-05-22.
//
// Link : https://www.acmicpc.net/problem/16210

#include <bits/stdc++.h>

using namespace std;

#define SIZE (500000+2)
#define x first
#define y second

using ppi = pair<int, int>;
using ll = long long;

struct bank {
    int id;
    ppi position;
    ll distance;

    bool operator<(const bank& rhs) const {
        if (this->distance == rhs.distance) {
            return this->id < rhs.id;
        }
        return this->distance < rhs.distance;
    }
};

int N;
bank banks[SIZE];

ll calc_distance(ppi p1, ppi p2) {
    return (long long)(abs(p1.x - p2.x))+ (long long)(abs(p1.y - p2.y));
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 0, x, y; i < N; i++) {
        cin >> x >> y;
        banks[i].id  = i + 1;
        banks[i].position = make_pair(x, y);
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            banks[i].distance += calc_distance(banks[i].position, banks[j].position);
        }
    }

    sort(banks, banks + N);
    cout << banks[0].id << '\n';
    return 0;
}