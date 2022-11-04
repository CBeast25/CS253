#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    vector<int> v;
    int i;
    while ((cin >> i) && (i != 0)) {
        v.push_back(i);
    }
    for (auto val : v)
        cout << val << '\n';
    ifstream res("/etc/resolv.conf");
    string s;
    char c;
    while (res.get(c))
        s.push_back(c);
    multiset<char> ms;
    for (auto val : s)
        ms.insert(val);
    set<char> fin;
    for (auto val : ms)
        fin.insert(val);
    cout << "string: size=" << s.size() << " " << s << '\n'; 
    cout << "set: size=" << fin.size() << " ";
    for (auto val : fin)
        cout << val;
    cout << '\n';
    cout << "multiset: size=" << ms.size() << " ";
    for (auto val : ms)
        cout << val;
    cout << '\n';
    // QUESTION 7 
    // the sizes are different because
    // string stores all the characters
    // set stores only the unique characters in sorted order
    // multiset stores all the characters in sorted order
}
