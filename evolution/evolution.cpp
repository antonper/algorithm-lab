#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Specie {
    string name;
    int index;
    int parent;
    long  long age;

    Specie() {}

    Specie(string n, int i, int a) : name(n), index(i), age(a) {
        parent = -1;
    }


};


void solve() {
    int n, q;
    cin >> n >> q;
    vector<Specie> s(n);
    map<string, int> dic;
    for (int i = 0; i < n; ++i) {
        string str;
        long long age;
        cin >> str >> age;
        s[i] = Specie(str, i, age);
        dic.insert(pair<string, int>(str, i));
    }

    for (int j = 0; j < n - 1; ++j) {
        string child, parent;
        cin >> child >> parent;
        s[dic.find(child)->second].parent = dic.find(parent)->second;
    }

    for (int i = 0; i < q; ++i) {
        string name;
        long long years;
        cin >> name >> years;
        Specie current = s[dic.find(name)->second];

        while (years >= current.age ) {
            name=current.name;
            if(current.parent!=-1){current=s[current.parent];}else{
                break;
            }
        }
        cout<<name<<" ";
    }


    return;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
        cout<<endl;
    }


}