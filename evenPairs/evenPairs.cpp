#include <iostream>

void doTest();

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        doTest();
    }
}

void doTest() {
    int n;
    cin >> n;
    int array[n];
    int evenSub = 0, oddSub = 0;
    int sub=0;
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
        sub = sub + array[i];
        if (sub % 2 == 0) {
            evenSub++;
        } else { oddSub++; }
    }
    cout<<evenSub+evenSub*(evenSub-1)/2+oddSub*(oddSub-1)/2<<endl;
}