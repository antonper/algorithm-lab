#include <iostream>

#include <vector>
#include <queue>


using namespace std;

class Data {
public:
    int  length,min_pos, ring_pos;

    Data(int length, int ring_pos) : length(length), ring_pos(ring_pos), min_pos(ring_pos) {}

    bool operator< (const Data& other) const {
        if(min_pos == other.min_pos) {
            return ring_pos > other.ring_pos;
        }
        return min_pos > other.min_pos;
    }

};


int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        //read data
        int boat_count;
        cin >> boat_count;
        priority_queue<Data> boats;
        for (int boat_index = 0; boat_index < boat_count; ++boat_index) {
            int length, position;
            cin >> length >> position;
            boats.push(Data(length, position));
        }
        int current_pos = boats.top().ring_pos;
        boats.pop();
        //iterate over boats
        int places_boats = 1;
        while (!boats.empty()) {
            Data boat = boats.top();
            boats.pop();
            if (current_pos <= boat.min_pos - boat.length) {
                current_pos = boat.min_pos;
                places_boats++;
            } else if (current_pos <= boat.ring_pos) {
                boat.min_pos = current_pos + boat.length;
                boats.push(boat);
            }


        }
        cout << places_boats << endl;


    }


}