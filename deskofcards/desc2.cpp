//
// Created by Anton on 2016-09-26.
//
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

int doTest() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int lastPos = 0, pos = 0, bestSum = 0, sum = 0;
    bool best_set_yet = false;
    pair<int, int> best_pair;
    while (pos < n) {
        if (sum + v[pos] > k) {
            if (!best_set_yet || abs(k - sum) < abs(k - bestSum)) {
                bestSum = sum;
                best_pair = pair<int, int>(lastPos, pos - 1);
                best_set_yet = true;
            }
            while (sum + v[pos] > k && lastPos < pos) {
                sum = sum - v[lastPos];
                lastPos += 1;
            }
        }
        sum += v[pos];
        pos += 1;
    }
    if (!best_set_yet || abs(k - sum) < abs(k - bestSum)) {
        bestSum = sum;
        best_pair = pair<int, int>(lastPos, pos - 1);
        best_set_yet = true;
    }
    cout << best_pair.first << " " << best_pair.second << "\n";
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int test_count;
    cin >> test_count;
    for (int i = 0; i < test_count; ++i) {
        doTest();
    }
    return 0;
}

