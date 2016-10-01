#include<iostream>
#include <vector>
#include <queue>
#include <set>
#include <limits>


using namespace std;

class PairCompare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};


int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int word_count;
        cin >> word_count;

        //read words occurrences number
        vector<int> occurs(word_count, 0);
        for (int j = 0; j < word_count; ++j) {
            cin >> occurs[j];
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, PairCompare> locs;

        //read data
        for (int word_index = 0; word_index < word_count; ++word_index) {
            for (int j = 0; j < occurs.at(word_index); ++j) {
                int l;
                cin >> l;
                locs.push(make_pair(l, word_index));
            }
        }


        //find first range with all words
        vector<int> first_set_loc(word_count, -1);
        set<pair<int, int> > words;
        int words_found = 0;
        int last_loc = numeric_limits<int>::min();
        while (word_count != words_found && !locs.empty()) {
            pair<int, int> cur = locs.top();
            locs.pop();

            if (first_set_loc.at(cur.second) == -1) {
                words_found++;
            } else {
                words.erase(make_pair(first_set_loc.at(cur.second), cur.second));
            }

            first_set_loc.at(cur.second) = cur.first;
            words.insert(cur);
            last_loc = cur.first;
        }

        int min_dist = last_loc - words.begin()->first;

        while (!locs.empty()) {
            pair<int, int> cur = locs.top();
            locs.pop();

            words.erase(make_pair(first_set_loc.at(cur.second), cur.second));
            first_set_loc.at(cur.second) = cur.first;
            words.insert(cur);

            int d = cur.first - words.begin()->first;
            min_dist = min(d, min_dist);
        }
        cout << min_dist + 1 << endl;


    }
}






