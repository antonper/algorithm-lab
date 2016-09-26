#include <iostream>

void solve();

using namespace std;


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }

}

void solve() {
    int m;
    cin >> m;
    float sum = 0;
    for (int i = 0; i < m; ++i) {
        float temp;
        cin >> temp;
        sum = sum + temp;
    }
    cout << sum << endl;
}