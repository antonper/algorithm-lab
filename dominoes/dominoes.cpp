#include <iostream>

using namespace std;


void doTest();

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        doTest();
    }

}


void doTest() {
    int m;
    cin >> m;
    int toFall;
    cin >> toFall;
    int counter = 1;
    while (toFall > 1 && counter < m) {
        toFall--;
        counter++;

        int current;
        cin >> current;
        toFall = toFall > current ? toFall : current;
    }
    for (int i = counter; i < m; ++i) {
        cin>>toFall;
    }
    cout << counter << endl;
}

