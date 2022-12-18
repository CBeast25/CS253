#include "Doc.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
        ofstream("data") << "\r \r  \n\n Peter  \n   Ray\r \nEgon  \n \n\r\n\n";
    Doc d;
    assert(d.empty() && !d);
    ifstream in("data");
    in >> d;
    assert(d && !d.empty());
    assert(d.size()==3);
    assert(d[0].indent == 1);
    assert(d[1].indent == 3);
    assert(d[2].indent == 0);
    assert(d[0].data == "Peter");
    assert(d[1].data == "Ray");
    assert(d[2].data == "Egon");

    d += "      Winston     ";
    assert(d.size() == 4);
    assert(d[3].indent == 6);
    assert(d[3].data == "Winston     ");

    for (size_t n=0; n<d.size(); n++) {
        const auto stuff = d[n];
        cout << n << ": " << stuff.indent << ' ' << stuff.data << '\n';
    }
    cout << "---\n" << d << "---\n";

    d += "";
    assert(d.size() == 5);
    assert(d[4].indent == 0);
    assert(d[4].data == "");

    const Doc vacant;
    assert(vacant.empty() && !vacant && vacant.size()==0);
    d = vacant;
    assert(d.empty() && !d && d.size()==0);

    cout << d << "---\nDone.\n\n";


    ofstream("data") << " \n one\n  two\n   three\n \n \r \n";
    Doc d1;
    assert(d1.empty() && !d1);
    ifstream in2("data");
    in2 >> d1;
    assert(d1 && !d1.empty());
    assert(d1.size()==3);
    assert(d1[0].indent == 1); assert(d1[0].data == "one");
    assert(d1[1].indent == 2); assert(d1[1].data == "two");
    assert(d1[2].indent == 3); assert(d1[2].data == "three");
    cout << "*** d:\n" << d1;

    Doc d2;
    const string values[] = {"alpha", "  beta", "gamma"};
    d2.append(values+0, values+2);  // excluded gamma
    cout << "*** d2:\n" << d2;

    Doc d3(d1); d3.replace(d2, 1, 1);
    cout << "*** d3:\n" << d3;

    vector<const char *> v = {"truth", "   beauty "};
    Doc d4(d3); d4.insert(v.begin(), v.end(), 3);
    cout << "*** d4:\n" << d4;

    const set<string> s = {" yes", " no "};  // set is sorted
    Doc d5(d4); d5.replace(s.begin(), s.end(), 4);
    cout << "*** d5:\n" << d5;

    assert(d5.size()==6);
    assert(d5[0].indent == 1); assert(d5[0].data == "one");
    assert(d5[1].indent == 0); assert(d5[1].data == "alpha");
    assert(d5[2].indent == 2); assert(d5[2].data == "beta");
    assert(d5[3].indent == 0); assert(d5[3].data == "truth");
    assert(d5[4].indent == 1); assert(d5[4].data == "no ");
    assert(d5[5].indent == 1); assert(d5[5].data == "yes");

    return 0;
}