#include<iostream>
#include <vector>
#include <cmath>


using namespace std;

void solve();

int searchBinary(int element, vector<int> word);

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }


}

void solve() {
    //read data
    int n;
    int minWord = 0;
    int minWordIndex = 0;
    int bestDistance = 0;
    cin >> n;
    vector<vector<int> > words(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        if (i == 0) {
            minWord = m;
            minWordIndex = i;
        }

        words[i].resize(m);
        if (m < minWord) { minWordIndex = i; }
        minWord = min(minWord, m);
    }
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < words[j].size(); ++i) {
            cin >> words[j][i];
            bestDistance = max(bestDistance, words[j][i]);
        }
    }
    int bestStart, bestEnd, closestElement;
    for (int i = 0; i < words[minWordIndex].size(); ++i) {
        bestStart = words[minWordIndex][i];
        bestEnd = words[minWordIndex][i];
        for (int j = 0; j < words.size(); ++j) {
            if (j != minWordIndex) {
                closestElement = searchBinary(words[minWordIndex][i], words[j]);
                if (closestElement > bestEnd) { bestEnd = closestElement; }
                else if (closestElement < bestStart) { bestStart = closestElement; }

            }
        }
        bestDistance = min(bestDistance, bestEnd - bestStart + 1);

    }
    cout << bestDistance << endl;
}


int searchBinary(int element, vector<int> word) {
    int index = 0;
    int closestMatch = -99999;
    bool wasBigger = false;
    int step = 0;
    while (!wasBigger || step > 0) {
        if (abs(word[index] - element) < abs(closestMatch - element)) {
            closestMatch = word[index];
        }
        if (word[index] > element) {
            wasBigger = true;
        }
        if (wasBigger) {
            if (step == 1) step = 0;
            else {
                step = step / 2;
            }
        } else {
            step = step * 2;
            if (step == 0)step = 1;
        }
        if (word[index] > element) {
            index = index - step;
        }
        if (word[index] < element) {
            index = index + step;
        }


    }

    return closestMatch;
}



