#include<iostream>
#include <cstring>
#include <cmath>

using namespace std;
//#define DEBUG
//#ifdef DEBUG
//#endif

void doTest();

void equal(int bigger[], int smaller[], int p);

void changeWeight(int bigger[], int smaller[], int p);

int coins[1001];
bool onlyEquals = true;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        doTest();
    }

    return 0;
}

void doTest() {
    int n = 0;
    onlyEquals = true;
    cin >> n;
    int k;
    memset(coins, 0, sizeof(coins));
    cin >> k;
    int p = 0;
    for (int i = 0; i < k; ++i) {
        cin >> p;
        int leftCoins[p];
        int rightCoins[p];

        for (int j = 0; j < p; ++j) {
            cin >> leftCoins[j];
        }
        for (int j = 0; j < p; ++j) {
            cin >> rightCoins[j];
        }
        char sign;
        cin >> sign;
        switch (sign) {
            case '>':
                changeWeight(leftCoins, rightCoins, p);
                break;
            case '<':
                changeWeight(rightCoins, leftCoins, p);
                break;
            case '=':
                equal(rightCoins, leftCoins, p);
                break;
        }
    }
    int foundCoin = 0;
    int max = 0;
    int zeroCoin = 0;
    int count_zero = 0;
    int count_max = 0;
    if (!onlyEquals) {
        for (int l = 1; l < n + 1; ++l) {
            if (coins[l] != 7777 && coins[l] != 0) {
                if (abs(coins[l]) > max) {
                    foundCoin = l;
                    max = abs(coins[l]);
                    count_max = 1;
                } else if (coins[l] == max) {
                    count_max++;
                }
            }
        }
    } else {

        for (int l = 1; l < n + 1; ++l) {

            if (coins[l] == 0) {
                count_zero++;
                zeroCoin = l;
            }
        }
    }
    if (count_zero > 1) {
        cout << 0 << endl;
        return;
    } else if (count_zero == 1) {
        foundCoin = zeroCoin;
    }
    if (count_max > 1) {
        cout << 0 << endl;
        return;
    }
    cout << foundCoin << endl;
}

void changeWeight(int bigger[], int smaller[], int p) {
    onlyEquals = false;
    for (int i = 0; i < p; ++i) {
        if (coins[bigger[i]] != 7777) {
            coins[bigger[i]]++;
        }

        if (coins[smaller[i]] != 7777) {
            coins[smaller[i]]--;
        }
    }
}

void equal(int bigger[], int smaller[], int p) {
    for (int i = 0; i < p; ++i) {
        coins[bigger[i]] = 7777;
        coins[smaller[i]] = 7777;
    }
}


