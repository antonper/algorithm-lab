#include <iostream>
#include <vector>
#include <cmath>

void solve();

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}

void solve() {
    int n;
    int k;

    cin >> n;
    vector<int> cards(n);
    cin >> k;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        cards[i] = tmp;
    }
    int sum = 0;
    int start = 0, end = 0, bestStart = 0, bestEnd = 0;
    int bestRes = cards[0];
    bool bestIsSet=false;
    sum = cards[0];

    while (end < n) {
        if (sum == k) {
            bestStart = start;
            bestEnd = end;
            bestRes = sum;
            bestIsSet=true;
            cout << bestStart << " " << bestEnd << endl;
            return;
        }

        if (sum < k) {
            if (end + 1 < n) {
                end++;
                sum=sum + cards[end];
                if (sum > k) {
                    if (abs(sum-cards[end] - k) < abs(bestRes - k)) {
                        bestStart = start;
                        bestIsSet=true;
                        bestEnd = end-1;
                        bestRes = sum-cards[end];
                    }
                }

            } else {
                if (!bestIsSet) {
                    bestStart = start;
                    bestEnd = end;
                    bestRes = sum;
                }
                cout << bestStart << " " << bestEnd << endl;
                return;
            }
        }

        if (sum > k) {
            if (start == end) {
                end++;
                start++;
                sum = cards[end];
            } else {
                sum = sum - cards[start];
                start++;
                if (sum < k) {
                    if (abs(sum+cards[start-1] - k) < abs(bestRes - k)) {
                        bestIsSet=true;
                        bestStart = start-1;
                        bestEnd = end;
                        bestRes = sum+cards[start-1];
                    }
                }

            }
        }

    }
    cout << bestStart << " " << bestEnd << endl;
    return;
}