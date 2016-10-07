#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;


struct Bomb {
    int time;
    int index;
    bool dependent;
    int first_parent;
    int second_parent;

    Bomb() {};

    Bomb(int t, int i, int n) : time(t), index(i) {
        dependent = (i <= ((n - 3) / 2));
        if (dependent) {
            first_parent = 2 * i + 1;
            second_parent = 2 * i + 2;
        } else {
            first_parent = -1;
            second_parent = -1;
        }
    }
};


bool ballComparator(const Bomb &a, const Bomb &b) {
    if (a.time == b.time) {
        return a.dependent ;
    }
    return a.time < b.time;
}

bool defuse(Bomb &ball, int &time, vector<bool> &ball_disarmed) {

    if (ball_disarmed[ball.index]) {
        return true;
    }
    if (time >= ball.time) {
        //  cout<<"BOOM "<<time<<" "<<ball.index<<endl;
        return false;
    }
    ball_disarmed[ball.index] = true;
    time++;
    return true;
}


void solve() {
    int n, i, t;
    cin >> n;
    vector<Bomb> balls(n);
    for (i = 0; i < n; ++i) {
        cin >> t;
        balls[i] = Bomb(t, i, n);
    }
    sort(balls.begin(), balls.end(), ballComparator);

    vector<bool> ball_disarmed(n, false);


    vector<int> ball_index(n);
    for (i = 0; i < n; ++i) {
        ball_index[balls[i].index] = i;
    }

    int time = 0;
    for (i = 0; i < n; ++i) {
        Bomb cur_ball = balls[i];
        if (cur_ball.dependent) {
            Bomb first_parent = balls[ball_index[cur_ball.first_parent]];
            Bomb second_parent = balls[ball_index[cur_ball.second_parent]];
            bool flag = false;
            if (first_parent.time <= second_parent.time) {
                flag = defuse(first_parent, time, ball_disarmed) && defuse(second_parent, time, ball_disarmed);
            } else if (first_parent.time > second_parent.time) {
                flag = defuse(second_parent, time, ball_disarmed) && defuse(first_parent, time, ball_disarmed);
            }
            flag = flag && defuse(cur_ball, time, ball_disarmed);
            if (!flag) {
                cout << "no" << endl;
                return;
            }
        } else {
            if (!defuse(cur_ball, time, ball_disarmed)) {
                cout << "no" << endl;
                return;
            }
        }
    }
    for (int j = 0; j < n; ++j) {
        if(!ball_disarmed[j]){
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
    return;


}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }


}

