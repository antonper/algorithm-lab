#include<iostream>
#include <vector>


using namespace std;

void solve();

int minOfIndex(vector<vector<int> > words);

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
    int minWord;
    int minIndex;
    int maxIndex = 0;
    cin >> n;
    vector<vector<int> > words(n);
    for (int i = 0; i < n; ++i) {
        unsigned int m;
        cin >> m;
        words[i].resize(m);
    }
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < words[j].size(); ++i) {
            cin >> words[j][i];
            if (i == 0) {
                maxIndex = max(maxIndex, words[j][0]);
            }
        }
    }

    minWord = minOfIndex(words);
    minIndex = words[minWord][0];

    int bestDistance = maxIndex - minIndex + 1;
    bool limitFound = false;

    while (!limitFound) {

        if (words[minWord].size() <= 1) {
            limitFound = true;
        } else {
            words[minWord].erase(words[minWord].begin());
            maxIndex = max(maxIndex, words[minWord][0]);
            minWord = minOfIndex(words);
            minIndex = words[minWord][0];
            bestDistance = min(bestDistance, maxIndex - minIndex + 1);
        }
    }

    cout << bestDistance << endl;
    return;


}

int minOfIndex(vector<vector<int> > words) {
    int minIndex = words[0][0];
    int wordNumber = 0;
    for (int i = 0; i < words.size(); ++i) {

        if (words[i][0] < minIndex) {
            minIndex = words[i][0];
            wordNumber = i;
        }
    }
    return wordNumber;
}



