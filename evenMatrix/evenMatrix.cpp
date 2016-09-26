#include <iostream>
#include <cstring>

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
    cin >> n;
    int matrix[n][n];
    int partsum[n][n];
    int parity = 0;
    int countEven = 0, countOdd = 0;
    int answer = 0;

    for (int i = 0; i < n; ++i) {
        parity = 0;
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
            parity = (parity + matrix[i][j]) % 2;
            partsum[i][j] = parity;
        }
    }

    int lineSum[n];
    memset(lineSum, 0, sizeof(n));
    answer = 0;

    for (int i = 0; i < n; ++i) {
        memset(lineSum, 0, sizeof(lineSum));
        for (int j = i; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                lineSum[k] = (lineSum[k] + partsum[j][k]) % 2;
                if (lineSum[k] % 2 == 0) {
                    countEven++;
                } else {
                    countOdd++;
                }
            }
            answer = answer + countEven + countEven * (countEven - 1) / 2 + countOdd * (countOdd - 1) / 2;

            countEven = 0;
            countOdd = 0;
        }
        countEven = 0;
        countOdd = 0;
    }

    cout << answer << endl;

}
