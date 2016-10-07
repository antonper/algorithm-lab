#include <iostream>
#include <queue>
#include <algorithm>

void solve();

using namespace std;
//friends strength
vector<int> fs;
//book weights
vector<int> bw;

int main() {
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        solve();
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    fs.clear();
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        fs.push_back(tmp);
    }
    sort(fs.rbegin(), fs.rend());

    bw.clear();
    for (int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        bw.push_back(tmp);
    }
    sort(bw.rbegin(), bw.rend());

    if (bw[0] > fs[0]) {
        cout << "impossible" << endl;
        return;
    }


    long  e = 0, g = 0, r = 0;
    int si = 0, bi = 0;

    while (bi < m) {
        //higest str
        int hs = fs[si];
        //count same str
        long  cs = 0;
        for (; si < n && fs[si] == hs; cs++, si++);

        int t = (si < n) ? fs[si] : 0;
        //book count
        long  bc = 0;
        for (; bw[bi] > t && bi < m; bi++, bc++);

        bc = bc - r * cs;
        //extra
        e = e - bc;
        g = g + cs;

        if (e < 0) {
            int ri =(-e%g)?(-e/g)+1:-e/g;

            e = e + ri * g;
            r = r + ri;
        }


    }
    cout << r * 3 - 1 << endl;

}